#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "Button.h"
#include <string>

class HUD {
public:
    void khoiTao(int _chieuRong, int _chieuCao, SDL_Renderer* ve);
    void veLen(SDL_Renderer* ve, TTF_Font* font, int level, int xu, const std::string& tuHienTai);
    bool nutTronBam(float chuotX, float chuotY, bool nhan);
    bool nutGoiYBam(float chuotX, float chuotY, bool nhan);
    void donDep();

private:
    int chieuRong, chieuCao;
    Button nutTron;
    Button nutGoiY;
    
    SDL_Texture* texShuffle = nullptr;
    SDL_Texture* texHint = nullptr;
};