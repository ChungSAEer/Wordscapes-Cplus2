#pragma once
#include <SDL3/SDL.h>

// cau truc luu tru trang thai cua chuot (toa do va cac trang thai click)
struct ConChuot {
    float viTriX = 0;
    float viTriY = 0;
    bool dangNhan = false;
    bool vuaNhan = false;
    bool vuaNha = false;
};

// lop quan ly phan cung dau vao (chuot, ban phim)
class Input {
public:
    // xoa trang thai click hien tai de chuan bi cho khung hinh moi
    void resetKhung();
    // doc su kien tu he dieu hanh va cap nhat trang thai chuot
    void xuLySuKien(SDL_Event& e);
    // tra ve thong tin cua con chuot de cac class khac su dung
    ConChuot layChuot();

private:
    ConChuot chuot;
};
