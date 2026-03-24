#include "../core/Game.h"
#include <iostream>

int main(int argc, char* argv[]) {
    Game game;

    if (!game.init("Wordscapes Clone", 800, 600)) {
        std::cerr << "[ERROR] Khong the khoi tao game!\n";
        return 1;
    }

    game.run();

    return 0;
}