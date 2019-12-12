#include "Managers/GameManager.h"
#include "Managers/MenuManager.h"

int main(int argc, char **args) {
    MenuManager* menuManager = new MenuManager();
    menuManager->init();
    menuManager->update();
    menuManager->deleteMeu();
    GameManager *game = new GameManager();
    game->init();
    game->loop();
    game->clean();

    return 0;
}