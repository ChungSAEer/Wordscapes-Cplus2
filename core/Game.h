#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>
#include <string>

#include "../data/LevelLoader.h"
#include "../puzzle/Grid.h"
#include "../puzzle/LetterWheel.h"
#include "../puzzle/Level.h"
#include "../puzzle/WordValidator.h"
#include "../ui/Button.h"
#include "../ui/Menu.h"
#include "../ui/HUD.h"
#include "Input.h"

enum TrangThaiGame {
    TRANG_THAI_MENU,
    TRANG_THAI_CHOI,
    TRANG_THAI_THANG
};

class Game {
public:
    Game();
    ~Game();
    bool khoiDong(const std::string& tieuDe, int chieuRong, int chieuCao);
    void chay();
    void donDep();

private:
    void xuLySuKien();
    void capNhat();
    void hienThi();

    void batDauLevel(int soLevel);
    void kiemTraTu();

    SDL_Window* cuaSo;
    SDL_Renderer* boVe;
    TTF_Font* fontChu;
    TTF_Font* fontLon;
    TTF_Font* fontNho;
    SDL_Texture* texNutTiepTheo = nullptr;

    bool dangChay;
    TrangThaiGame trangThai;

    int levelHienTai;
    int soXu;

    LevelLoader boDocLevel;
    Grid bangOChu;
    LetterWheel vongChuCai;
    Level levelData;
    WordValidator kiemTraTuObj;
    Menu menuChinh;
    HUD thanhThongTin;
    Input boXuLyInput;

    int chieuRongCuaSo;
    int chieuCaoCuaSo;

    std::string thongBao;
    float thoiGianThongBao;

    Button nutTiepTheo;
    SDL_AudioSpec thongSoNhac;
    Uint8* duLieuNhac = nullptr;
    Uint32 chieuDaiNhac = 0;
    SDL_AudioStream* luongAmThanh = nullptr;
};