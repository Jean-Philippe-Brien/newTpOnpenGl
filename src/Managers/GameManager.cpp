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
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    player = new Player(glm::vec3(0,0,0));

}
void GameManager::loop() {

    while (isRunning) {
        clean();
        glLoadIdentity();
        
        gluLookAt(6, 6, 4, 0, 0, 0, 0, 1, 0);
        
        
        
        handleEvent();
        player->drawEntity();
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
    glFlush();
    SDL_GL_SwapWindow(win);
}
void GameManager::handleEvent() {
    SDL_PollEvent(&event);
    state = SDL_GetKeyboardState(0);
    if (event.type == SDL_QUIT) {
        isRunning = false;
    }
    if(state[SDL_SCANCODE_W])
    {
        player->movement(true);
    }
    if(state[SDL_SCANCODE_S])
    {
        player->movement(false);
    }
    if(state[SDL_SCANCODE_A])
    {
        player->setRotation(player->getRotation() + 0.3);
    }
    if(state[SDL_SCANCODE_D])
    {
        player->setRotation(player->getRotation() - 0.3);
    }
    if(state[SDL_SCANCODE_Q])
    {
        player->setCanonRotation(player->getCanonRotation() + 0.3);
    }
    if(state[SDL_SCANCODE_E])
    {
        player->setCanonRotation(player->getCanonRotation() - 0.3);
    }
    if(state[SDL_SCANCODE_SPACE])
    {
        player->createProjectile();
    }
    
}
GameManager::~GameManager() {
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
}
