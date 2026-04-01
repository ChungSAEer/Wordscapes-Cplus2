#include "Button.h"
#include "../core/TextureManager.h"

void Button::khoiTao(float x, float y, float w, float h, const std::string& chuoi,
                     SDL_Color _mauNen, SDL_Color _mauChu) {
    viTriX = x;
    viTriY = y;
    chieuRong = w;
    chieuCao = h;
    noiDung = chuoi;
    mauNen = _mauNen;
    mauChu = _mauChu;
    hover = false;
}

void Button::veLen(SDL_Renderer* ve, TTF_Font* font) {
    SDL_Color mauVe = mauNen;
    if (hover) {
        mauVe.r = (Uint8)std::min(255, mauVe.r + 30);
        mauVe.g = (Uint8)std::min(255, mauVe.g + 30);
        mauVe.b = (Uint8)std::min(255, mauVe.b + 30);
    }
    TextureManager::veHinhChuNhatBoGoc(ve, viTriX, viTriY, chieuRong, chieuCao, 10.0f, mauVe);

    TextureManager::veChu(ve, font, noiDung,
        viTriX + chieuRong / 2, viTriY + chieuCao / 2, mauChu, true);
}

bool Button::duocNhan(float chuotX, float chuotY, bool nhanChuot) {
    hover = (chuotX >= viTriX && chuotX <= viTriX + chieuRong &&
             chuotY >= viTriY && chuotY <= viTriY + chieuCao);
    return hover && nhanChuot;
}

bool Button::laHover(float chuotX, float chuotY) {
    hover = (chuotX >= viTriX && chuotX <= viTriX + chieuRong &&
             chuotY >= viTriY && chuotY <= viTriY + chieuCao);
    return hover;
}

void Button::datViTri(float x, float y) {
    viTriX = x;
    viTriY = y;
}
