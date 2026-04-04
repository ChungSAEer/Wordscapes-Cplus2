#include "HUD.h"
#include "../core/TextureManager.h"
#include <string>

void HUD::khoiTao(int _chieuRong, int _chieuCao) {
    chieuRong = _chieuRong;
    chieuCao = _chieuCao;

    nutTron.khoiTao(chieuRong / 2.0f - 250, chieuCao - 55, 115, 40,
                    "SHUFFLE", { 52, 152, 219, 255 }, { 255, 255, 255, 255 });
    nutGoiY.khoiTao(chieuRong / 2.0f + 150, chieuCao - 55, 100, 40,
                    "HINT", { 155, 89, 182, 255 }, { 255, 255, 255, 255 });
}

void HUD::veLen(SDL_Renderer* ve, TTF_Font* font, int level, int xu, const std::string& tuHienTai) {
    SDL_Color mauTrang = { 255, 255, 255, 255 };
    SDL_Color mauVang = { 255, 215, 0, 255 };

    std::string chuLevel = "Level " + std::to_string(level);
    TextureManager::veChu(ve, font, chuLevel, 70, 22, mauTrang, true);

    std::string chuXu = "Coins: " + std::to_string(xu);
    TextureManager::veChu(ve, font, chuXu, chieuRong - 80.0f, 22, mauVang, true);

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
