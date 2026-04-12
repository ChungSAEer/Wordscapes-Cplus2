#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include <string>

struct ChuTrenVong {
    char kyTu;
    float viTriX, viTriY;
    float banKinh;
    bool dangChon;
    float gocHienTai;
};

class LetterWheel {
public:
    void khoiTao(const std::string& cacChu, float tamX, float tamY, float banKinhVong);
    void veLen(SDL_Renderer* ve, TTF_Font* font);
    void xuLyChuot(float chuotX, float chuotY, bool nhanMoi, bool nhaChuot, bool dangGiu);
    std::string layTuDangGhep();
    void xoaTuDangGhep();
    bool dangKeoKhong();
    void tronChu();

private:
    std::vector<ChuTrenVong> danhSachChu;
    std::vector<int> chuDaChon;
    bool dangKeoThat;
    float tamX, tamY, banKinhVong;
    std::string tuHienTai;
    int timChuTaiViTri(float x, float y);
};
