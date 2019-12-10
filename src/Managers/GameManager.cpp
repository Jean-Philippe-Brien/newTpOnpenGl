//
// Created by jean- on 2019-11-28.
//
#include "GameManager.h"


void GameManager::init() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    win = SDL_CreateWindow("OpenGl Test", SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    context = SDL_GL_CreateContext(win);
   // glEnable(GL_DEPTH_TEST);
   glLightModeli(GL_LIGHT_MODEL_AMBIENT, GL_TRUE);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (double) 800 / 600, 1, 1000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    player = new Player(glm::vec3(0,0,0));
    followCam = new Camera(player, 1);
    fpsCam = new Camera(player,2);
    
    mapList = new std::vector<char>();
    std::ifstream file("assets/basicMap.txt"); //change file name here to test,   ** Need to implement event based file selection **
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
    mapList->shrink_to_fit();
    
}
void GameManager::loop() {

    while (isRunning) {
        clean();
        glLoadIdentity();
        SDL_GetMouseState(&mouseX,&mouseY);
        
        if (!viewChanged) {//3rd Person Cam
            followCam->moveCam(player, 1);
            //FPS Cam below
        } else { //fpsCam->moveCam(player,2);
            gluLookAt(6, 6, 4, 0, 0, 0, 0, 1, 0);
        }
        
        handleEvent();
        //std::cout << mouseX << " < X  ,  Y  > " << mouseY << std::endl;
        SDL_Delay(1);

        draw();
        //mise a jour de l'ecran
    }
}
void GameManager::clean() {
    glClearColor(1.f, 1.f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GameManager::draw() {
    
    drawMap(planeSize,*mapList);
    glColor3ub(0,0,0);
    
    player->drawEntity();
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
            player->movement(true);
        }else {player->movement(true);
        }
    }
    if(state[SDL_SCANCODE_S])
    {
        if(!viewChanged){
            player->movement(false);
        }else {player->movement(false);
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
        }else {
        }
    }
    if(state[SDL_SCANCODE_RIGHT])
    {
        if(!viewChanged){
            player->setCanonRotation(player->getCanonRotation() - 0.7);
        }else {
        }
    }
    if(state[SDL_SCANCODE_SPACE])
    {
        if(!viewChanged){
            player->createProjectile();
        }else {
            player->createProjectile();
        }
    }
    if((state[SDL_SCANCODE_A]&&state[SDL_SCANCODE_W]) || (state[SDL_SCANCODE_S]&&state[SDL_SCANCODE_A])){
        if(!viewChanged){
            player->setRotation(player->getRotation() + 1.5);
        }else {player->setRotation(player->getRotation() + 1.5);
        }
    }
    if((state[SDL_SCANCODE_D]&&state[SDL_SCANCODE_W]) || (state[SDL_SCANCODE_S]&&state[SDL_SCANCODE_D])){
        if(!viewChanged){
            player->setRotation(player->getRotation() - 1.5);
        }else {player->setRotation(player->getRotation() - 1.5);
        }
    }
    if(state[SDL_SCANCODE_V]){
        //Reserved for View changes
        if(viewChanged){
            viewChanged=false;
        }else{viewChanged=true;}
        SDL_Delay(75);  //Temporary fix....
    }
    
}
GameManager::~GameManager() {
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
}
