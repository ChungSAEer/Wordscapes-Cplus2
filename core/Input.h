#pragma once
#include <SDL3/SDL.h>

struct ConChuot {
    float viTriX = 0;
    float viTriY = 0;
    bool dangNhan = false;
    bool vuaNhan = false;
    bool vuaNha = false;
};

class Input {
public:
    void resetKhung();
    void xuLySuKien(SDL_Event& e);
    ConChuot layChuot();

private:
    ConChuot chuot;
};
