#include "Menu.h"
#include "../core/TextureManager.h"
#include <cmath>

void Menu::khoiTao(int _chieuRong, int _chieuCao) {
    chieuRong = _chieuRong;
    chieuCao = _chieuCao;
    bienDoNhay = 0;
    thoiGianDemo = 0;

    float giuaX = chieuRong / 2.0f;

    nutChoi.khoiTao(giuaX - 100, chieuCao / 2.0f + 20, 200, 55,
                    "PLAY", { 46, 204, 113, 255 }, { 255, 255, 255, 255 });
    nutThoat.khoiTao(giuaX - 100, chieuCao / 2.0f + 95, 200, 55,
                     "EXIT", { 231, 76, 60, 255 }, { 255, 255, 255, 255 });
}

int Menu::veVaXuLy(SDL_Renderer* ve, TTF_Font* fontLon, TTF_Font* fontNho,
                   float chuotX, float chuotY, bool nhanChuot) {
    thoiGianDemo += 0.016f;
    bienDoNhay = sinf(thoiGianDemo * 2.0f) * 8.0f;

    float giuaX = chieuRong / 2.0f;

    SDL_Color mauVang = { 255, 215, 0, 255 };
    TextureManager::veChu(ve, fontLon, "WORDSCAPES",
                          giuaX, chieuCao / 4.0f + bienDoNhay, mauVang, true);

    SDL_Color mauXam = { 180, 185, 200, 255 };
    TextureManager::veChu(ve, fontNho, "Word Puzzle Game",
                          giuaX, chieuCao / 4.0f + 50, mauXam, true);

    nutChoi.laHover(chuotX, chuotY);
    nutThoat.laHover(chuotX, chuotY);

    nutChoi.veLen(ve, fontNho);
    nutThoat.veLen(ve, fontNho);

    if (nutChoi.duocNhan(chuotX, chuotY, nhanChuot)) return 1;
    if (nutThoat.duocNhan(chuotX, chuotY, nhanChuot)) return 2;

    return 0;
}
