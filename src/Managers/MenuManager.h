//
// Created by ssohy on 12/9/2019.
//

#ifndef MONPROJETSDL_MENUMANAGER_H
#define MONPROJETSDL_MENUMANAGER_H


#include "../Utils/Include.h"

class MenuManager {
    
    std::vector<std::ifstream> mapDataBase;
    std::vector<glm::vec3> mainMenuLayout;
    bool levelSelected;
    SDL_Event event;

public:
    MenuManager();
    
    void init();
    
    void update();
    
    std::vector<std::ifstream> loadMaps();
    
    void drawMenu();
};


#endif //MONPROJETSDL_MENUMANAGER_H
