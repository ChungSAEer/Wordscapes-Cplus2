#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
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

// danh sach cac trang thai cua game giup cho state machine hoat dong
enum TrangThaiGame {
    TRANG_THAI_MENU,
    TRANG_THAI_CHOI,
    TRANG_THAI_THANG
};

// lop trung tam quan ly toan bo vong doi va logic cua tro choi
class Game {
public:
    // ham khoi tao constructor
    Game();
    // ham huy destructor de don dac bo nho
    ~Game();
    
    // ham setup dau tien (khoi tao cua so sdl, load data)
    bool khoiDong(const std::string& tieuDe, int chieuRong, int chieuCao); //setup
    
    // ham vong lap vo tan de giu game hoat dong lien tuc (game loop)
    void chay();
    
    // ham giai phong tai nguyen va huy cua so khi thoat
    void donDep();

private:
    // ham thu thap cac tuong tac mang tinh vat ly (click chuot, bam phim)
    void xuLySuKien(); // input chuot + phim
    
    // ham cap nhat cac bien so va xu ly tu duy logic cua tro choi
    void capNhat();
    
    // ham ve lai toan bo moi thu len man hinh sau khi da cap nhat xong
    void hienThi(); //render

    // ham tai du lieu tu file json vao dung map tuong ung với so level do
    void batDauLevel(int soLevel);
    
    // ham so khop chuoi ki tu nguoi dung vua ghep voi danh sach dap an hien co
    void kiemTraTu();

    SDL_Window* cuaSo;
    SDL_Renderer* boVe;
    TTF_Font* fontChu;
    TTF_Font* fontLon;
    TTF_Font* fontNho;
    SDL_Texture* texNutTiepTheo = nullptr;
    SDL_Texture* anhNenChung = nullptr;

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