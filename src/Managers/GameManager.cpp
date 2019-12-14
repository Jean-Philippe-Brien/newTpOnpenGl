//
// Created by jean- on 2019-11-28.
//
#include "GameManager.h"

GameManager::GameManager() {
    mapSelected = "basicMap.txt";
}

GameManager::GameManager(std::string map) {
    if(map == "")
        mapSelected = "basicMap.txt";
    else
        mapSelected = map;
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
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    //glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (double) 800 / 600, 1, 1000);
    //glEnable(GL_DEPTH_TEST);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    projectileManager = new ProjectileManager();
    enemy = new Enemy(glm::vec3(20,0,3));
    player = new Player(glm::vec3(10,0,3));
    followCam = new Camera(player);

    mapList = new std::vector<char>();
    std::ifstream file("../assets/map/" + mapSelected); //change file name here to test,   ** Need to implement event based file selection **
    if (file) {
        char c;
        while (file.get(c)) {
            if(!isspace(c)){//Check if this char is a '/n'
                mapList->push_back(c);
            }else{planeSize++;}//If so increment Plane size
        }
    } else {        //Error if no file is loaded
        std::cout << "no file loaded" << std::endl;
    }
    collisionManager = new CollisionManager();
    collisionManager->init(mapList, planeSize);
    mapList->shrink_to_fit();

}
void GameManager::loop() {

    while (isRunning) {
        timeStartLoop = SDL_GetTicks();
        clean();
        glLoadIdentity();
        SDL_GetMouseState(&mouseX,&mouseY);

        if (!viewChanged) {//3rd Person Cam
            followCam->moveCam(player, 1);
            //FPS Cam below
        } else { //fpsCam->moveCam(player,2);
            followCam->moveCam(player, 2);
        }

        handleEvent();
        //std::cout << mouseX << " < X  ,  Y  > " << mouseY << std::endl;

        projectileManager->update(collisionManager);
        //wall->detectColosion(player);
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

    drawMap(planeSize,mapList);
    glColor3ub(0,0,0);
    
    player->drawEntity();
    enemy->drawEntity();
    glFlush();
    SDL_GL_SwapWindow(win);
}
void GameManager::handleEvent() {
    SDL_PollEvent(&event);
    state = SDL_GetKeyboardState(nullptr);
    if (event.type == SDL_QUIT) {
        isRunning = false;
    }
    if(state[SDL_SCANCODE_ESCAPE]){
        isRunning=false;
    }

    if(state[SDL_SCANCODE_W])
    {
        if(!viewChanged){
            player->movement(true, collisionManager);
        }else {player->movement(true, collisionManager);
        }
    }
    if(state[SDL_SCANCODE_S])
    {
        if(!viewChanged){
            player->movement(false, collisionManager);
        }else {
            player->movement(false, collisionManager);
        }
    }
    if(state[SDL_SCANCODE_A])
    {
        if(!viewChanged){
            player->setRotation(player->getRotation() + 1);
        }else {player->setRotation(player->getRotation() + 1);
        }
    }
    if(state[SDL_SCANCODE_D])
    {
        if(!viewChanged){
            player->setRotation(player->getRotation() - 1);
        }else {player->setRotation(player->getRotation() - 1);
        }
    }
    if(state[SDL_SCANCODE_LEFT])
    {
        if(!viewChanged){
            player->setCanonRotation(player->getCanonRotation() + 0.7);
        }else {player->setCanonRotation(player->getCanonRotation() + 0.7);
        }
    }
    if(state[SDL_SCANCODE_RIGHT])
    {
        if(!viewChanged){
            player->setCanonRotation(player->getCanonRotation() - 0.7);
        }else {player->setCanonRotation(player->getCanonRotation() - 0.7);
        }
    }
    if(state[SDL_SCANCODE_SPACE])
    {
        if(!viewChanged){
            projectileManager->createProjectile(player);
        }else {
            projectileManager->createProjectile(player);;
        }
    }
    if((state[SDL_SCANCODE_A]&&state[SDL_SCANCODE_W]) || (state[SDL_SCANCODE_S]&&state[SDL_SCANCODE_A])){
        if(!viewChanged){
            player->setRotation(player->getRotation() + 0.7);
        }else {player->setRotation(player->getRotation() + 0.7);
        }
    }
    if((state[SDL_SCANCODE_D]&&state[SDL_SCANCODE_W]) || (state[SDL_SCANCODE_S]&&state[SDL_SCANCODE_D])){
        if(!viewChanged){
            player->setRotation(player->getRotation() - 0.7);
        }else {player->setRotation(player->getRotation() - 0.7);
        }
    }
    if(event.type == SDL_MOUSEWHEEL) {
        if (event.wheel.y != 0) // scroll up
        {
            std::cout << event.wheel.y;
            followCam->setDistance(event.wheel.y);

        }
        event.wheel.y = 0;
    }
        if (state[SDL_SCANCODE_V] && event.type == SDL_KEYDOWN) {
            //Reserved for View changes
            if (viewChanged) {
                viewChanged = false;
            } else { viewChanged = true; }
            SDL_Delay(75);  //Temporary fix....
        }
    
}
GameManager::~GameManager() {
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
}
