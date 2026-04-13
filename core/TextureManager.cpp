// ve khoi + ve chu + load file bang sdl image
#include "TextureManager.h"
#include <cmath>

// ham nay convert text string thanh be mat anh sau do quang len render canvas
void TextureManager::veChu(SDL_Renderer* ve, TTF_Font* font, const std::string& chuoi,
                            float x, float y, SDL_Color mau, bool canGiua) {
    if (!font || chuoi.empty()) return;

    SDL_Surface* matPhang = TTF_RenderText_Blended(font, chuoi.c_str(), 0, mau);
    if (!matPhang) return;

    SDL_Texture* hinh = SDL_CreateTextureFromSurface(ve, matPhang);
    SDL_DestroySurface(matPhang);
    if (!hinh) return;

    float w = 0, h = 0;
    SDL_GetTextureSize(hinh, &w, &h);

    SDL_FRect hinhChuNhat;
    if (canGiua) {
        hinhChuNhat = { x - w / 2, y - h / 2, w, h };
    } else {
        hinhChuNhat = { x, y, w, h };
    }

    SDL_RenderTexture(ve, hinh, nullptr, &hinhChuNhat);
    SDL_DestroyTexture(hinh);
}

// ham nay quet cac diem anh de to mau thanh mot vong tron dac (solid circle) bang thuat toan pytago
void TextureManager::veHinhTronDoc(SDL_Renderer* ve, float taiX, float taiY,
                                    float banKinh, SDL_Color mau) {
    SDL_SetRenderDrawColor(ve, mau.r, mau.g, mau.b, mau.a);
    int r = (int)banKinh;
    for (int w = -r; w <= r; w++) {
        for (int h = -r; h <= r; h++) {
            if (w * w + h * h <= r * r) {
                SDL_RenderPoint(ve, taiX + w, taiY + h);
            }
        }
    }
}

// ham nay chia hinh chu nhat bo goc thanh cac cuc nho (3 cuc chu nhat va bo goc pytago 4 ben) roi dap vo voi nhau
void TextureManager::veHinhChuNhatBoGoc(SDL_Renderer* ve, float x, float y, float w, float h,
                                         float boGoc, SDL_Color mau) {
    SDL_SetRenderDrawColor(ve, mau.r, mau.g, mau.b, mau.a);

    SDL_FRect giua = { x + boGoc, y, w - 2 * boGoc, h };
    SDL_RenderFillRect(ve, &giua);

    SDL_FRect trai = { x, y + boGoc, boGoc, h - 2 * boGoc };
    SDL_RenderFillRect(ve, &trai);

    SDL_FRect phai = { x + w - boGoc, y + boGoc, boGoc, h - 2 * boGoc };
    SDL_RenderFillRect(ve, &phai);

    int br = (int)boGoc;
    float gocX[] = { x + boGoc, x + w - boGoc, x + boGoc, x + w - boGoc };
    float gocY[] = { y + boGoc, y + boGoc, y + h - boGoc, y + h - boGoc };
    for (int i = 0; i < 4; i++) {
        for (int dx = -br; dx <= br; dx++) {
            for (int dy = -br; dy <= br; dy++) {
                if (dx * dx + dy * dy <= br * br)
                    SDL_RenderPoint(ve, gocX[i] + dx, gocY[i] + dy);
            }
        }
    }
}

// ham nay noi cac diem anh tu a den b sinh ra mot duong thang (quang duong vecto) co do day do minh qui dinh
void TextureManager::veDuongThang(SDL_Renderer* ve, float x1, float y1, float x2, float y2,
                                   float doDay, SDL_Color mau) {
    SDL_SetRenderDrawColor(ve, mau.r, mau.g, mau.b, mau.a);
    float dx = x2 - x1;
    float dy = y2 - y1;
    float doDai = sqrtf(dx * dx + dy * dy);
    if (doDai < 0.001f) return;

    float nx = -dy / doDai * doDay / 2;
    float ny = dx / doDai * doDay / 2;

    for (float t = 0; t <= 1.0f; t += 1.0f / doDai) {
        float cx = x1 + dx * t;
        float cy = y1 + dy * t;
        for (float s = -1; s <= 1; s += 0.5f) {
            SDL_RenderPoint(ve, cx + nx * s, cy + ny * s);
        }
    }
}
