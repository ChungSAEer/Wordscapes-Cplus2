#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "Button.h"
#include <vector>

struct MenuStar {
    float x, y, r, speed, alpha;
};

class Menu {
public:
    void khoiTao(int _chieuRong, int _chieuCao, SDL_Renderer* ve);
    int veVaXuLy(SDL_Renderer* ve, TTF_Font* fontLon, TTF_Font* fontNho,
                 float chuotX, float chuotY, bool nhanChuot);

    void donDep();

private:
    Button nutChoi;
    Button nutThoat;
    
    int chieuRong, chieuCao;
    float bienDoNhay;
    float thoiGianDemo;
    std::vector<MenuStar> cacSao;

    SDL_Texture* texNutStart = nullptr;
    SDL_Texture* texNutExit = nullptr;
};