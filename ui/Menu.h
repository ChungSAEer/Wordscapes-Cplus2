#pragma once // dam bao file nay chi duoc include mot lan
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "Button.h"
#include <vector>

// cau truc luu thong tin cua mot ngoi sao trong hieu ung bay o man hinh menu
struct MenuStar {
    float x, y, r, speed, alpha; // toa do, ban kinh, toc do bay, do mo (alpha)
};

// Lop quan ly man hinh Menu chinh cua game (voi nut Play va Exit)
class Menu {
public:
    // khoi tao menu voi kich thuoc man hinh, load cac hinh anh can thiet
    void khoiTao(int _chieuRong, int _chieuCao, SDL_Renderer* ve);
    
    // ve man hinh menu (hieu ung nen, tieu de, nut) va xu ly tuong tac chuot.
    // Tra ve 1 neu chon Play, 2 neu chon Exit, 0 neu chua chon gi
    int veVaXuLy(SDL_Renderer* ve, TTF_Font* fontLon, TTF_Font* fontNho,
                 float chuotX, float chuotY, bool nhanChuot);

    // don dep huy do hoa cua nut khi thoat khoi ung dung
    void donDep();

private:
    Button nutChoi;  // nut de bat dau tro choi
    Button nutThoat; // nut de thoat ra ngoai win
    
    int chieuRong, chieuCao;       // kich thuoc hien thicua so
    float bienDoNhay;              // do nhay len xuong de lam hieu ung chuyen dong muot
    float thoiGianDemo;            // bo dem thoi gian cho cac hieu ung (sao bay, pulse)
    std::vector<MenuStar> cacSao;  // mang danh sach cac ngoi sao

    SDL_Texture* texNutStart = nullptr; // hinh anh texture cua nut Start
    SDL_Texture* texNutExit = nullptr;  // hinh anh texture cua nut Exit
};