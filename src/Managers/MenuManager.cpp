//
// Created by ssohy on 12/9/2019.
//

#include "MenuManager.h"


MenuManager::MenuManager() {
    play = new TextureManager();
    bg = new TextureManager();
}

void MenuManager::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    SDL_CreateWindowAndRenderer(width, height, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC, &win, &render);
    play->loadTexture("../assets/Menu/buttonWhiteNoHover.png", render);
    play->setScreenRect((width / 2) - 200, (height / 4) - 50, 400, 100);
    bg->loadTexture("../assets/Menu/Bg.png", render);
    bg->setScreenRect(0, 0, width, height);
    readDirectory();
}

MenuManager::~MenuManager() {
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void MenuManager::update() {
    while (isRunning) {
        //Nettoyer la fenetre
        SDL_SetRenderDrawColor(render, 0, 128, 255, 255);
        SDL_RenderClear(render);
        //gestion evenement
        SDL_GetMouseState(&mouseX, &mouseY);
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        bg->draw();
        //play->draw();
        drawMapSelection();

        setButtonTexture(play, "buttonWhite");
        //pause dans l image
        SDL_Delay(15);
        //mise a jour de l ecran
        SDL_RenderPresent(render);
    }
}

std::vector<std::ifstream> MenuManager::loadMaps() {

    std::vector<std::ifstream> fileList;
    
    //access map folder and read file names, then load mapdata
    
    return fileList;
}

void MenuManager::drawMenu() {

}

bool MenuManager::isInMenu() const {
    return inMenu;
}

void MenuManager::setInMenu(bool inMenu) {
    MenuManager::inMenu = inMenu;
}

void MenuManager::deleteMeu() {
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(win);
    SDL_Quit();
    mapName.clear();
}

void MenuManager::setButtonTexture(TextureManager* texture, std::string fileNameNoExt) {
    if(mouseX > texture->getScreenRect().x && mouseX < texture->getScreenRect().x + texture->getScreenRect().w && mouseY > texture->getScreenRect().y && mouseY < texture->getScreenRect().y + texture->getScreenRect().h){
        texture->loadTexture("../assets/Menu/" + fileNameNoExt + ".png", render);
        if(event.type == SDL_MOUSEBUTTONDOWN && SDL_BUTTON(SDL_BUTTON_LEFT) && !mouseDown){
            mouseDown = true;
            isRunning = false;
        }
    }
    else{
        texture->loadTexture("../assets/Menu/" + fileNameNoExt + "NoHover.png", render);
    }
    if(event.type == SDL_MOUSEBUTTONUP && SDL_BUTTON(SDL_BUTTON_LEFT) && mouseDown){
        mouseDown = false;
    }
}
void MenuManager::readDirectory()
{
    DIR* dirp = opendir(path.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        if(strncmp(dp->d_name, ".", 1) && strncmp(dp->d_name, "..", 2)){
            mapName.push_back(dp->d_name);

            TextureManager *add = new TextureManager();
            Text* addText = new Text();
            std::string temp = dp->d_name;
            temp.substr(temp.find('.'));
            addText->init(render, "../assets/Menu/Long_Shot.ttf", temp);
            add->loadTexture("../assets/Menu/normalButtonNoHover.png", render);
            mapTexture.push_back(add);
            mapText.push_back(addText);
        }
    }
    closedir(dirp);
}

void MenuManager::drawMapSelection() {
    int compteur = 0;
    for(TextureManager* map : mapTexture){
        map->setScreenRect((width / 2) - 175, 100 + (110 * compteur), 350, 100);
        setButtonTexture(map, "normalButton");
        map->draw();
        compteur++;
    }

}
