//
// Created by jean&seb on 2019-11-28.
//
#include "GameManager.h"


GameManager::GameManager() {
    mapSelected = "basicMap.txt";
}

GameManager::GameManager(std::string map) {
    if (map == "") {
        mapSelected = "basicMap.txt";
    } else {
        mapSelected = map;
    }
}

void GameManager::init() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    win = SDL_CreateWindow("OpenGl Test", SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    context = SDL_GL_CreateContext(win);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT_MODEL_AMBIENT);
    glEnable(GL_LIGHT0);
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (double) 800 / 600, 1, 1000);
    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    idTextureBuilding = loadTexture("../assets/textureBuilding.jpg", true);
    idTextureGrass = loadTexture("../assets/grass.jpg", true);
    projectileManager = new ProjectileManager();
    
    player = new Player(glm::vec3(4, 0, 8));
    followCam = new Camera(player);
    mapList = new std::vector<char>();
    nodeList = new std::vector<Node>();
    std::ifstream file("../assets/map/" +
                       mapSelected); //change file name here to test,   ** Need to implement event based file selection **
    int i = 0, j = 0, k = 0;
    
    if (file) {
        char c;
        int cpt = 0;
        while (file.get(c)) {
            if (!isspace(c)) {//Check if this char is a '/n'
                mapList->push_back(c);
                Node *n = new Node(i, j);
                n->setWalkable(c == '0');
                n->setId(cpt);
                nodeList->push_back(*n);
                /*if(n->isWalkable()){
                    if(cpt%3==0){
                        SpawnLocation newSpawn = {i,j};
                        spawns.push_back(&newSpawn);
                    }
                }*/
                cpt++;
                i++;
            } else {
                planeSize++;
                i = 0;
                j++;
            }//If so increment Plane size
        }
    } else {        //Error if no file is loaded
        std::cout << "no file loaded" << std::endl;
    }
    collisionManager = new CollisionManager();
    collisionManager->init(mapList, planeSize);
    mapList->shrink_to_fit();
    nodeList->shrink_to_fit();
    idMap = drawMap(planeSize, mapList, idTextureBuilding);
    enemy = new Enemy(glm::vec3(20, 0, 3), *nodeList, planeSize);
    
}

void GameManager::loop() {
    bool a = false;
    int death = 10;
    while (isRunning) {
        timeStartLoop = SDL_GetTicks();
        clean();
        glLoadIdentity();
        SDL_GetMouseState(&mouseX, &mouseY);
        
        if (!viewChanged) {
            followCam->moveCam(player, 1);
        } else {
            followCam->moveCam(player, 2);
        }
        handleEvent();
        projectileManager->update(collisionManager, player, enemy);
        
        if (!enemy->isAlive()) {
            player->setScore(player->getScore() + 100);
            enemy = new Enemy(glm::vec3(death, 0, death - 5), *nodeList, planeSize);
            if (death > 35) {
                death = 10;
            } else { death += 5; }
        } else { enemy->movement(player->getPosition()); }
        
        float deltaX = enemy->getPosition().x - player->getPosition().x;
        float deltaY = enemy->getPosition().y - player->getPosition().y;
        float deltaZ = enemy->getPosition().z - player->getPosition().z;
        float distance = (float) sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
        
        if (distance < 1) {
            player->setIsAlive(false);
        }
        
        if (player->getScore() == 500) {
            std::cout << "Victory" << std::endl;
            //Display VICTORY ADD CODE TO RETURN TO MAIN MENU
        }
        if (!player->isAlive()) {
            std::cout << " you deeead" << std::endl;
            //DISPLAY GAME OVER  ADD CODE TO RETURN TO MAIN MENU
        }
        draw();
        //mise a jour de l'ecran
        SDL_Delay(5);
    }
}

void GameManager::clean() {
    glClearColor(1.f, 1.f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GameManager::draw() {
    glPushMatrix();
    drawPlane(planeSize, idTextureGrass);
    glCallList(idMap);
    
    glPopMatrix();
    if (player->isAlive()) {
        player->drawEntity();
    }
    if (enemy->isAlive()) {
        enemy->drawEntity();
    }
    /*for(Node n : *nodeList){
        glPushMatrix();
        if(!n.isWalkable()){
            glColor3ub(255,0,0);
            glTranslatef(n.getX(),.7,n.getY());
            glScalef(0.4,0.4,0.4);
            drawCube();
        }else{glColor3ub(100,100,100);
            glTranslatef(n.getX(),-0.3,n.getY());
            glScalef(0.4,0.4,0.4);
            drawCube();}

        glPopMatrix();
    }*/
    
    if (showPath) {
        if (enemy->getPathFinding()->foundPath.size() != 0) {
            for (Node n : enemy->getPathFinding()->foundPath) {
                
                glPushMatrix();
                glColor3ub(0, 0, 0);
                glTranslatef(n.getX(), 0.4, n.getY());
                glScalef(0.1, 0.1, 0.1);
                drawCube();
                glPopMatrix();
            }
        }
    }
    //pathfinding gizmos
    
    glFlush();
    SDL_GL_SwapWindow(win);
}

void GameManager::handleEvent() {
    SDL_PollEvent(&event);
    state = SDL_GetKeyboardState(nullptr);
    if (event.type == SDL_QUIT) {
        isRunning = false;
    }
    if (state[SDL_SCANCODE_ESCAPE]) {
        isRunning = false;
    }
    
    if (state[SDL_SCANCODE_W]) {
        player->movement(true, collisionManager);
    }
    if (state[SDL_SCANCODE_S]) {
        player->movement(false, collisionManager);
    }
    if (state[SDL_SCANCODE_A]) {
        player->setRotation(player->getRotation() + 1);
    }
    if (state[SDL_SCANCODE_D]) {
        player->setRotation(player->getRotation() - 1);
    }   // W A S D Events
    
    if (state[SDL_SCANCODE_LSHIFT] && event.type == SDL_KEYDOWN) { //Temporary enemy spawner
        showPath = true;
        
    }
    if (state[SDL_SCANCODE_LCTRL]) {
        showPath = false;
    }
    if (state[SDL_SCANCODE_LEFT]) {
        player->setCanonRotation(player->getCanonRotation() + 0.7);
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        player->setCanonRotation(player->getCanonRotation() - 0.7);
        
    }
    
    if (state[SDL_SCANCODE_SPACE]) {
        if (!viewChanged) {
            projectileManager->createProjectile(player);
        } else {
            projectileManager->createProjectile(player);;
        }
    }   //Canon Rotation and Shooting Events
    
    if ((state[SDL_SCANCODE_A] && state[SDL_SCANCODE_W]) || (state[SDL_SCANCODE_S] && state[SDL_SCANCODE_A])) {
        if (!viewChanged) {
            player->setRotation(player->getRotation() + 0.75);
        } else {
            player->setRotation(player->getRotation() + 0.75);
        }
    }
    if ((state[SDL_SCANCODE_D] && state[SDL_SCANCODE_W]) || (state[SDL_SCANCODE_S] && state[SDL_SCANCODE_D])) {
        if (!viewChanged) {
            player->setRotation(player->getRotation() - 0.75);
        } else {
            player->setRotation(player->getRotation() - 0.75);
        }
    }   // Dual Inputs Events
    
    if (state[SDL_SCANCODE_V] && event.type == SDL_KEYDOWN) {
        if (viewChanged) {
            viewChanged = false;
        } else { viewChanged = true; }
    }   // Cam Toggle Event
    
}

GameManager::~GameManager() {
    SDL_GL_DeleteContext(context);
    glDeleteTextures(1, &idTextureBuilding);
    glDeleteTextures(1, &idTextureGrass);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
}
