#pragma once // dam bao file nay chi duoc include mot lan
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

// Lop bieu dien mot nut bam tren giao dien (UI Button)
class Button {
public:
    // khoi tao nut bam dang chu (text button) voi mau nen va mau chu
    void khoiTao(float x, float y, float w, float h, const std::string& chuoi,
                 SDL_Color mauNen, SDL_Color mauChu);
                 
    // khoi tao nut bam dang hinh anh (image button) thong qua texture
    void khoiTao(float x, float y, float w, float h, SDL_Texture* texture);

    // ve nut bam len man hinh can kieu font neu la nut chu
    void veLen(SDL_Renderer* ve, TTF_Font* font = nullptr);
    
    // kiem tra xem nut bam nay co dang bi click boi chuot hay khong
    bool duocNhan(float chuotX, float chuotY, bool nhanChuot);
    
    // kiem tra xem con tro chuot co dang di chuyen tren nut khong (hover)
    bool laHover(float chuotX, float chuotY);
    
    // thay doi vi tri nut bam
    void datViTri(float x, float y);

private:
    float viTriX, viTriY, chieuRong, chieuCao; // toa do va kich thuoc
    std::string noiDung;                       // noi dung text neu co
    SDL_Color mauNen, mauChu;                  // mau sac cua nut va chu
    bool hover;                                // trang thai chuot co nam tren nut
    
    SDL_Texture* anhNen = nullptr;             // hinh anh nen neu la nut anh
};