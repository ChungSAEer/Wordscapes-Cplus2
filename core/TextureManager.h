#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

// lop ho tro ve cac hinh anh, text bo sung cho engine sdl goc
class TextureManager {
public:
    // ham ho tro ve chu (text) tu 1 vi tri nhat dinh voi font va mau cho truoc
    static void veChu(SDL_Renderer* ve, TTF_Font* font, const std::string& chuoi,
                      float x, float y, SDL_Color mau, bool canGiua = true);
    
    // ham ho tro ve hinh tron dac
    static void veHinhTronDoc(SDL_Renderer* ve, float taiX, float taiY, float banKinh, SDL_Color mau);
    
    // ham ho tro ve hinh chu nhat co bo cong o 4 goc nhin cho dep
    static void veHinhChuNhatBoGoc(SDL_Renderer* ve, float x, float y, float w, float h,
                                    float boGoc, SDL_Color mau);
    
    // ham ho tro ve duong thang co do day nhat dinh (de noi chu)
    static void veDuongThang(SDL_Renderer* ve, float x1, float y1, float x2, float y2,
                              float doDay, SDL_Color mau);
};
