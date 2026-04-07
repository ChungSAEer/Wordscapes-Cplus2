#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>
#include <string>

class Button {
public:
    // Hàm khởi tạo nút chữ
    void khoiTao(float x, float y, float w, float h, const std::string& chuoi,
                 SDL_Color mauNen, SDL_Color mauChu);
                 
    // Hàm khởi tạo cho nút ảnh
    void khoiTao(float x, float y, float w, float h, SDL_Texture* texture);

    void veLen(SDL_Renderer* ve, TTF_Font* font = nullptr);
    bool duocNhan(float chuotX, float chuotY, bool nhanChuot);
    bool laHover(float chuotX, float chuotY);
    void datViTri(float x, float y);

private:
    float viTriX, viTriY, chieuRong, chieuCao;
    std::string noiDung;
    SDL_Color mauNen, mauChu;
    bool hover;
    
    SDL_Texture* anhNen = nullptr;
};