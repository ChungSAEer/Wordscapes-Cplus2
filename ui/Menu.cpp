//tao ra man hinh menu chinh, co hieu ung sao bay, nut choi va thoat
#include "Menu.h"
#include "../core/TextureManager.h"
#include <SDL3_image/SDL_image.h>
#include <cmath>
#include <cstdlib>

static void veGradientDoc(SDL_Renderer* ve, int w, int h, SDL_Color mauTren, SDL_Color mauDuoi) {
    for (int y = 0; y < h; y++) {
        float t = (float)y / h;
        Uint8 r = (Uint8)(mauTren.r + t * (mauDuoi.r - mauTren.r));
        Uint8 g = (Uint8)(mauTren.g + t * (mauDuoi.g - mauTren.g));
        Uint8 b = (Uint8)(mauTren.b + t * (mauDuoi.b - mauTren.b));
        SDL_SetRenderDrawColor(ve, r, g, b, 255);
        SDL_FRect dong = { 0, (float)y, (float)w, 1.0f };
        SDL_RenderFillRect(ve, &dong);
    }
}

static void veVongTron(SDL_Renderer* ve, float cx, float cy, float r, SDL_Color mau) {
    SDL_SetRenderDrawColor(ve, mau.r, mau.g, mau.b, mau.a);
    int ri = (int)r;
    for (int dx = -ri; dx <= ri; dx++)
        for (int dy = -ri; dy <= ri; dy++)
            if (dx*dx + dy*dy <= ri*ri)
                SDL_RenderPoint(ve, cx+dx, cy+dy);
}

void Menu::khoiTao(int _chieuRong, int _chieuCao, SDL_Renderer* ve) {
    chieuRong = _chieuRong;
    chieuCao  = _chieuCao;
    bienDoNhay   = 0;
    thoiGianDemo = 0;

    cacSao.clear();
    for (int i = 0; i < 80; i++) {
        MenuStar s;
        s.x     = (float)(rand() % chieuRong);
        s.y     = (float)(rand() % chieuCao);
        s.r     = 0.5f + (rand() % 20) / 10.0f;
        s.speed = 0.3f + (rand() % 15) / 10.0f;
        s.alpha = (float)(rand() % 255);
        cacSao.push_back(s);
    }

    float giuaX = chieuRong / 2.0f;

    texNutStart = IMG_LoadTexture(ve, "assets/button_start.png");
    texNutExit  = IMG_LoadTexture(ve, "assets/button_exit.png");

    nutChoi.khoiTao(giuaX - 110, chieuCao / 2.0f + 30,  220, 58, texNutStart);
    nutThoat.khoiTao(giuaX - 110, chieuCao / 2.0f + 108, 220, 58, texNutExit);
}

int Menu::veVaXuLy(SDL_Renderer* ve, TTF_Font* fontLon, TTF_Font* fontNho,
                   float chuotX, float chuotY, bool nhanChuot) {
    thoiGianDemo += 0.016f;
    bienDoNhay = sinf(thoiGianDemo * 1.8f) * 9.0f;

    SDL_Color nenTren  = { 10,  8,  35, 255 };
    SDL_Color nenDuoi  = {  5, 20,  50, 255 };
    veGradientDoc(ve, chieuRong, chieuCao, nenTren, nenDuoi);

    SDL_SetRenderDrawColor(ve, 255, 255, 255, 10);
    for (int x = 0; x < chieuRong; x += 42)
        SDL_RenderLine(ve, x, 0, x, chieuCao);
    for (int y = 0; y < chieuCao; y += 42)
        SDL_RenderLine(ve, 0, y, chieuRong, y);

    for (auto& s : cacSao) {
        s.alpha += s.speed * 4.0f;
        Uint8 a = (Uint8)(128 + 127 * sinf(s.alpha * 0.02f));
        SDL_Color mauSao = { 200, 220, 255, a };
        veVongTron(ve, s.x, s.y, s.r, mauSao);
    }

    float glowY = chieuCao / 4.0f + bienDoNhay;
    float pulse = 0.55f + 0.45f * sinf(thoiGianDemo * 2.5f);
    SDL_SetRenderDrawColor(ve, (Uint8)(80 * pulse), (Uint8)(40 * pulse), (Uint8)(180 * pulse), 35);
    SDL_FRect haloRect = { chieuRong / 2.0f - 200, glowY - 55, 400, 90 };
    for (int i = 0; i < 18; i++) {
        haloRect.x += 3; haloRect.y += 2;
        haloRect.w -= 6; haloRect.h -= 4;
        SDL_RenderFillRect(ve, &haloRect);
    }

    SDL_Color mauBong  = {  80,  40, 180, 160 };
    SDL_Color mauTieuDe = { 255, 215,   0, 255 };
    TextureManager::veChu(ve, fontLon, "WORDSCAPES", chieuRong / 2.0f + 3, glowY + 3, mauBong, true);
    TextureManager::veChu(ve, fontLon, "WORDSCAPES", chieuRong / 2.0f, glowY, mauTieuDe, true);

    float subAlpha = 180 + (Uint8)(75 * sinf(thoiGianDemo * 1.2f));
    SDL_Color mauPhuDe = { 160, 190, 255, (Uint8)subAlpha };
    TextureManager::veChu(ve, fontNho, "A Word Puzzle Adventure", chieuRong / 2.0f, chieuCao / 4.0f + 58, mauPhuDe, true);

    float lineY = chieuCao / 4.0f + 76;
    SDL_SetRenderDrawColor(ve, 100, 120, 255, 80);
    SDL_RenderLine(ve, (int)(chieuRong/2.0f - 120), (int)lineY, (int)(chieuRong/2.0f + 120), (int)lineY);

    nutChoi.laHover(chuotX, chuotY);
    nutThoat.laHover(chuotX, chuotY);
    
    nutChoi.veLen(ve, fontNho);
    nutThoat.veLen(ve, fontNho);

    if (nutChoi.duocNhan(chuotX, chuotY, nhanChuot))  return 1;
    if (nutThoat.duocNhan(chuotX, chuotY, nhanChuot)) return 2;
    return 0;
}

void Menu::donDep() {
    if (texNutStart != nullptr) SDL_DestroyTexture(texNutStart);
    if (texNutExit != nullptr) SDL_DestroyTexture(texNutExit);
}