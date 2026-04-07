#include "HUD.h"
#include "../core/TextureManager.h"
#include <SDL3_image/SDL_image.h>
#include <string>

void HUD::khoiTao(int _chieuRong, int _chieuCao, SDL_Renderer* ve) {
    chieuRong = _chieuRong;
    chieuCao = _chieuCao;

    texShuffle = IMG_LoadTexture(ve, "assets/button_shuffle.png");
    texHint    = IMG_LoadTexture(ve, "assets/button_hint.png");

    nutTron.khoiTao(20, _chieuCao - 80, 115, 41, texShuffle);
    nutGoiY.khoiTao(_chieuRong - 150, _chieuCao - 80, 115, 41, texHint);
}

void HUD::veLen(SDL_Renderer* ve, TTF_Font* font, int level, int xu, const std::string& tuHienTai) {
    SDL_Color mauTrang = { 255, 255, 255, 255 };
    SDL_Color mauVang = { 255, 215, 0, 255 };

    std::string chuLevel = "Level " + std::to_string(level);
    TextureManager::veChu(ve, font, chuLevel, 100, 52, mauTrang, true);

    std::string chuXu = "Coins: " + std::to_string(xu);
    TextureManager::veChu(ve, font, chuXu, chieuRong - 100.0f, 52, mauVang, true);

    if (!tuHienTai.empty()) {
        SDL_Color mauXanh = { 100, 220, 255, 255 };
        TextureManager::veChu(ve, font, tuHienTai, chieuRong / 2.0f, chieuCao - 115.0f, mauXanh, true);
    }

    nutTron.veLen(ve, font);
    nutGoiY.veLen(ve, font);
}

bool HUD::nutTronBam(float chuotX, float chuotY, bool nhan) {
    nutTron.laHover(chuotX, chuotY);
    return nutTron.duocNhan(chuotX, chuotY, nhan);
}

bool HUD::nutGoiYBam(float chuotX, float chuotY, bool nhan) {
    nutGoiY.laHover(chuotX, chuotY);
    return nutGoiY.duocNhan(chuotX, chuotY, nhan);
}

void HUD::donDep() {
    if (texShuffle) SDL_DestroyTexture(texShuffle);
    if (texHint) SDL_DestroyTexture(texHint);
}