#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>
#include "Button.h"
#include <vector>

struct MenuStar {
    float x, y, r, speed, alpha;
};

class Menu {
public:
    void khoiTao(int chieuRong, int chieuCao);
    int veVaXuLy(SDL_Renderer* ve, TTF_Font* fontLon, TTF_Font* fontNho,
                 float chuotX, float chuotY, bool nhanChuot);

private:
    Button nutChoi;
    Button nutThoat;
    int chieuRong, chieuCao;
    float bienDoNhay;
    float thoiGianDemo;
    std::vector<MenuStar> cacSao;
};
