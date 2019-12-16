//
// Created by jean&seb on 2019-11-28.
//

#ifndef MONPROJETSDL_GAMEMANAGER_H
#define MONPROJETSDL_GAMEMANAGER_H
#include "../Utils/Include.h"
#include "../Managers/ProjectileManager.h"
#include "../Managers/CollisionManager.h"
#include "../Classes/Camera.h"
#include "../Classes/Enemy.h"
#include "../Utils/Pathfinding/Node.h"
#include "../Utils/Pathfinding/aStar.h"


class GameManager {
private:
    //test
    CollisionManager *collisionManager;
    //fin test
    double timeStartLoop;

    const Uint8* state = nullptr;
    SDL_Event event;
    bool isRunning = true;
    bool viewChanged = false;
    SDL_Window *win;
    SDL_GLContext context;
    int width = 800, height = 600;
    int mouseX=0,mouseY=0;
    int planeSize=1;
    std::vector<char> *mapList;
    std::vector<Node> *nodeList;
    aStar *pathfinding;
    std::string mapSelected;
    Player *player;
    Enemy *enemy;
    Camera *followCam;
    Camera *fpsCam;
    ProjectileManager *projectileManager;

public:
    GameManager();
    GameManager(std::string map);
    void init();
    void loop();
    void handleEvent();
    void draw();
    void clean();
    ~GameManager();
};


#endif //GAMELOOP_GAME_H
