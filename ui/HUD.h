#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>
#include <string>
#include "Button.h"

class HUD {
public:
    void khoiTao(int chieuRong, int chieuCao);
    void veLen(SDL_Renderer* ve, TTF_Font* font, int level, int xu, const std::string& tuHienTai);
    bool nutTronBam(float chuotX, float chuotY, bool nhan);
    bool nutGoiYBam(float chuotX, float chuotY, bool nhan);

private:
    Button nutTron;
    Button nutGoiY;
    int chieuRong, chieuCao;
};
