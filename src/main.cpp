#include "Managers/GameManager.h"


int main(int argc, char **args) {
    auto* game = new GameManager();
    game->init();
    game->loop();
    game->clean();
    return 0;
}