#include "Managers/GameManager.h"
#include "Managers/MenuManager.h"

int main(int argc, char **args) {
    MenuManager* menuManager = new MenuManager();
    menuManager->init();
    menuManager->update();
    menuManager->deleteMeu();
    if(!menuManager->isQuitGame()) {
        GameManager *game = new GameManager(menuManager->getLevelSelected());
        game->init();
        game->loop();
        game->clean();
    }
    return 0;
}