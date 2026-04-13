// quan ly input, chuot, ban phim, tra ve thong tin chuot
#include "Input.h"

// ham nay dung de lam moi lai trang thai bam/nha chuot moi khi bat dau render 1 frame (khung hinh) moi
void Input::resetKhung() {
    chuot.vuaNhan = false;
    chuot.vuaNha = false;
}

// ham nay nhan event tu sdl roi phan loai xem no la hanh dong gi (di chuyen hay la click)
void Input::xuLySuKien(SDL_Event& e) {
    if (e.type == SDL_EVENT_MOUSE_MOTION) {
        chuot.viTriX = e.motion.x;
        chuot.viTriY = e.motion.y;
    }
    if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        chuot.dangNhan = true;
        chuot.vuaNhan = true;
        chuot.viTriX = e.button.x;
        chuot.viTriY = e.button.y;
    }
    if (e.type == SDL_EVENT_MOUSE_BUTTON_UP) {
        chuot.dangNhan = false;
        chuot.vuaNha = true;
        chuot.viTriX = e.button.x;
        chuot.viTriY = e.button.y;
    }
}

// ham nay tra ve data cua chuot hien tai
ConChuot Input::layChuot() {
    return chuot;
}
