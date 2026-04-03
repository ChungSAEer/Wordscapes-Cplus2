#include "../core/Game.h"

int main(int argc, char* argv[]) {
    Game troChoi;

    if (!troChoi.khoiDong("Wordscapes - Tro Choi Ghep Chu", 900, 750)) {
        return 1;
    }

    troChoi.chay();

    return 0;
}
