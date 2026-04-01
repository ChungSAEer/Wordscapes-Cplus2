#include "Input.h"

void Input::resetKhung() {
    chuot.vuaNhan = false;
    chuot.vuaNha = false;
}

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

ConChuot Input::layChuot() {
    return chuot;
}
