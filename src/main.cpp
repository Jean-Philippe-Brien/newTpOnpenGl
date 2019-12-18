#include "Managers/GameManager.h"
#include "Managers/MenuManager.h"

int main(int argc, char **args) {
    MenuManager *menuManager;
    do {

        MenuManager *menuManager = new MenuManager();
        menuManager->init();
        menuManager->update();

        if (!menuManager->isQuitGame()) {
            GameManager *game = new GameManager(menuManager->getLevelSelected());
            game->init();
            game->loop();
            game->clean();
            game->deleteGameManager();
        }

        //menuManager->setIsRunning(true);
        //menuManager->setMenuState(endPage);
        //menuManager->update();
        menuManager->deleteMeu();
    }while(menuManager->isQuitGame() == 91);


    return 0;
}