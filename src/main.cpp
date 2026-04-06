#include "../core/Game.h"

int main(int argc, char* argv[]) {
    Game troChoi;

    if (!troChoi.khoiDong("Wordscapes - Tro Choi Ghep Chu", 900, 1000)) {
        return 1;
    }

    troChoi.chay();

    return 2;
}
