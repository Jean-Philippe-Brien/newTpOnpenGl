//
// Created by jean- on 2019-11-28.
//

#ifndef MONPROJETSDL_GAMEMANAGER_H
#define MONPROJETSDL_GAMEMANAGER_H
#include "../Utils/Include.h"
#include "../Player.h"


class GameManager {
private:
    const Uint8* state = nullptr;
    SDL_Event event;
    bool isRunning = true;
    SDL_Window *win;
    SDL_GLContext context;
    int width = 800, height = 600;
    Player *player;

public:

    void init();
    void loop();
    void handleEvent();
    void draw();
    void clean();
    ~GameManager();
};


#endif //GAMELOOP_GAME_H
