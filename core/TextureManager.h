#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>
#include <string>

class TextureManager {
public:
    static void veChu(SDL_Renderer* ve, TTF_Font* font, const std::string& chuoi,
                      float x, float y, SDL_Color mau, bool canGiua = true);
    static void veHinhTronDoc(SDL_Renderer* ve, float taiX, float taiY, float banKinh, SDL_Color mau);
    static void veHinhChuNhatBoGoc(SDL_Renderer* ve, float x, float y, float w, float h,
                                    float boGoc, SDL_Color mau);
    static void veDuongThang(SDL_Renderer* ve, float x1, float y1, float x2, float y2,
                              float doDay, SDL_Color mau);
};
