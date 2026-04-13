#pragma once // dam bao file nay chi duoc include mot lan
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "Button.h"
#include <string>

// Lop quan ly Heads-Up Display (thong tin hien thi tren cung cua game nhu Level, Xu, nut goi kieu)
class HUD {
public:
    // khoi tao HUD voi kich thuoc cua so game
    void khoiTao(int _chieuRong, int _chieuCao, SDL_Renderer* ve);
    
    // ve cac thong tin chieu len man hinh (level, so xu, va tu dang ghep)
    void veLen(SDL_Renderer* ve, TTF_Font* font, int level, int xu, const std::string& tuHienTai);
    
    // kiem tra xem nguoi choi co nhan vao nut tron (shuffle) hay khong
    bool nutTronBam(float chuotX, float chuotY, bool nhan);
    
    // kiem tra xem nguoi choi co nhan vao nut goi y (hint) hay khong
    bool nutGoiYBam(float chuotX, float chuotY, bool nhan);
    
    // giai phong bo nho cua cac doi tuong do hoa sau khi dung xong
    void donDep();

private:
    int chieuRong, chieuCao;   // kich thuoc cua hud, thuong la bang cua so
    Button nutTron;            // nut bam doi cho cac chu cai (shuffle)
    Button nutGoiY;            // nut bam nhan goi y (hint)
    
    SDL_Texture* texShuffle = nullptr; // hinh anh cua nut tron
    SDL_Texture* texHint = nullptr;    // hinh anh cua nut hint
};