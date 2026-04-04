#include "Game.h"
#include "TextureManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

Game::Game() {
    cuaSo = nullptr;
    boVe = nullptr;
    fontChu = nullptr;
    fontLon = nullptr;
    fontNho = nullptr;
    dangChay = false;
    trangThai = TRANG_THAI_MENU;
    levelHienTai = 0;
    soXu = 100;
    chieuRongCuaSo = 0;
    chieuCaoCuaSo = 0;
    thoiGianThongBao = 0;
}

Game::~Game() {
    donDep();
}

bool Game::khoiDong(const std::string& tieuDe, int chieuRong, int chieuCao) {
    srand((unsigned)time(nullptr));
    chieuRongCuaSo = chieuRong;
    chieuCaoCuaSo = chieuCao;

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        std::cerr << "SDL loi: " << SDL_GetError() << "\n";
        return false;
    }

    if (!TTF_Init()) {
        std::cerr << "TTF loi: " << SDL_GetError() << "\n";
        return false;
    }

    cuaSo = SDL_CreateWindow("Wordscapes - Updated", chieuRong, chieuCao, 0);
    if (!cuaSo) return false;

    boVe = SDL_CreateRenderer(cuaSo, nullptr);
    if (!boVe) return false;

    SDL_SetRenderDrawBlendMode(boVe, SDL_BLENDMODE_BLEND);

    fontChu = TTF_OpenFont("assets/fonts/font.ttf", 24);
    if (!fontChu) fontChu = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 24);

    fontLon = TTF_OpenFont("assets/fonts/font.ttf", 48);
    if (!fontLon) fontLon = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 48);

    fontNho = TTF_OpenFont("assets/fonts/font.ttf", 18);
    if (!fontNho) fontNho = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 18);

    boDocLevel.docDuLieu();
    menuChinh.khoiTao(chieuRong, chieuCao);
    thanhThongTin.khoiTao(chieuRong, chieuCao);

    nutTiepTheo.khoiTao(chieuRong / 2.0f - 80, chieuCao / 2.0f + 60, 160, 50,
                        "NEXT LEVEL", { 46, 204, 113, 255 }, { 255, 255, 255, 255 });

    dangChay = true;
    trangThai = TRANG_THAI_MENU;
    return true;
}

void Game::batDauLevel(int soLevel) {
    if (soLevel >= boDocLevel.tongSoLevel()) {
        trangThai = TRANG_THAI_MENU;
        return;
    }

    levelHienTai = soLevel;
    ThongTinLevel thongTin = boDocLevel.layLevel(soLevel);
    levelData.khoiTao(thongTin);

    std::vector<std::string> dapAnList;
    for (auto& vt : thongTin.viTriCacTu)
        dapAnList.push_back(vt.tu);
    kiemTraTuObj.khoiTao(dapAnList);

    bangOChu.khoiTao(thongTin.soDong, thongTin.soCot, thongTin.viTriCacTu);

    float tamVongX = chieuRongCuaSo / 2.0f;
    float tamVongY = chieuCaoCuaSo - 160.0f;
    float banKinh = 80.0f;
    if (thongTin.cacChuCai.size() >= 4) banKinh = 90.0f;

    vongChuCai.khoiTao(thongTin.cacChuCai, tamVongX, tamVongY, banKinh);

    trangThai = TRANG_THAI_CHOI;
    thongBao = "Xin chao";
    thoiGianThongBao = 0;
}

void Game::kiemTraTu() {
    std::string tuTao = vongChuCai.layTuDangGhep();
    if (tuTao.empty()) return;

    if (kiemTraTuObj.daTuNayRoi(tuTao)) {
        thongBao = "Chu nay da tim roi!";
        thoiGianThongBao = 1.5f;
    } else if (kiemTraTuObj.laDapAnDung(tuTao)) {
        kiemTraTuObj.danhDauDaTim(tuTao);
        levelData.themTuDaTim(tuTao);

        ThongTinLevel tt = levelData.layThongTin();
        bangOChu.dienTuVao(tuTao, tt.viTriCacTu);

        soXu += 10;
        thongBao = "+" + std::to_string(10) + " xu!";
        thoiGianThongBao = 1.5f;

        if (levelData.daHoanThanh()) {
            trangThai = TRANG_THAI_THANG;
            soXu += 50;
        }
    } else {
        if (tuTao.size() >= 2) {
            thongBao = "Sai roi!";
            thoiGianThongBao = 1.0f;
        }
    }
    vongChuCai.xoaTuDangGhep();
}

void Game::chay() {
    Uint64 thoiGianTruoc = SDL_GetTicks();

    while (dangChay) {
        Uint64 thoiGianHienTai = SDL_GetTicks();
        float dt = (thoiGianHienTai - thoiGianTruoc) / 1000.0f;
        thoiGianTruoc = thoiGianHienTai;
        if (dt > 0.05f) dt = 0.05f;

        boXuLyInput.resetKhung();
        xuLySuKien();
        capNhat();
        hienThi();

        SDL_Delay(16);
    }
}

void Game::xuLySuKien() {
    SDL_Event suKien;
    while (SDL_PollEvent(&suKien)) {
        if (suKien.type == SDL_EVENT_QUIT) {
            dangChay = false;
            return;
        }
        if (suKien.type == SDL_EVENT_KEY_DOWN && suKien.key.key == SDLK_ESCAPE) {
            if (trangThai == TRANG_THAI_CHOI)
                trangThai = TRANG_THAI_MENU;
            else
                dangChay = false;
        }
        boXuLyInput.xuLySuKien(suKien);
    }
}

void Game::capNhat() {
    ConChuot chuot = boXuLyInput.layChuot();

    if (thoiGianThongBao > 0)
        thoiGianThongBao -= 0.016f;

    if (trangThai == TRANG_THAI_MENU) {
        int ketQua = menuChinh.veVaXuLy(boVe, fontLon, fontChu,
                                          chuot.viTriX, chuot.viTriY, chuot.vuaNhan);
        if (ketQua == 1) batDauLevel(0);
        if (ketQua == 2) dangChay = false;
    }

    if (trangThai == TRANG_THAI_CHOI) {
        vongChuCai.xuLyChuot(chuot.viTriX, chuot.viTriY,
                              chuot.vuaNhan, chuot.vuaNha, chuot.dangNhan);

        if (chuot.vuaNha && vongChuCai.layTuDangGhep().size() > 0) {
            kiemTraTu();
        }

        if (chuot.vuaNhan) {
            if (thanhThongTin.nutTronBam(chuot.viTriX, chuot.viTriY, true)) {
                vongChuCai.tronChu();
            }
            if (thanhThongTin.nutGoiYBam(chuot.viTriX, chuot.viTriY, true)) {
                if (soXu >= 20) {
                    std::string tuGoiY = levelData.goiY();
                    if (!tuGoiY.empty()) {
                        soXu -= 20;
                        ThongTinLevel tt = levelData.layThongTin();
                        bangOChu.loMotChu(tuGoiY, tt.viTriCacTu);
                        thongBao = "Hint : -20 coins!";
                        thoiGianThongBao = 1.5f;
                    }
                } else {
                    thongBao = "Out of coins!";
                    thoiGianThongBao = 1.5f;
                }
            }
        }

        bangOChu.capNhat(0.016f);
    }

    if (trangThai == TRANG_THAI_THANG) {
        nutTiepTheo.laHover(chuot.viTriX, chuot.viTriY);
        if (chuot.vuaNhan && nutTiepTheo.duocNhan(chuot.viTriX, chuot.viTriY, true)) {
            batDauLevel(levelHienTai + 1);
        }
    }
}

void Game::hienThi() {
    SDL_SetRenderDrawColor(boVe, 15, 15, 40, 255);
    SDL_RenderClear(boVe);

    SDL_SetRenderDrawColor(boVe, 20, 20, 55, 100);
    for (int i = 0; i < chieuCaoCuaSo; i += 4) {
        SDL_FRect vach = { 0, (float)i, (float)chieuRongCuaSo, 2.0f };
        SDL_RenderFillRect(boVe, &vach);
    }

    if (trangThai == TRANG_THAI_MENU) {
        menuChinh.veVaXuLy(boVe, fontLon, fontChu,
                            boXuLyInput.layChuot().viTriX,
                            boXuLyInput.layChuot().viTriY, false);
    }

    if (trangThai == TRANG_THAI_CHOI) {
        int soDong = bangOChu.laySoDong();
        int soCot = bangOChu.laySoCot();
        float kichThuocO = 45.0f;
        float khoangCach = 2.0f;
        float tongRong = soCot * (kichThuocO + khoangCach);
        float tongCao = soDong * (kichThuocO + khoangCach);
        float batDauX = (chieuRongCuaSo - tongRong) / 2.0f;
        float batDauY = 60.0f;

        bangOChu.veLen(boVe, fontChu, batDauX, batDauY, kichThuocO);

        std::string tuDangTao = vongChuCai.layTuDangGhep();
        thanhThongTin.veLen(boVe, fontNho, levelHienTai + 1, soXu, tuDangTao);

        vongChuCai.veLen(boVe, fontChu);

        if (thoiGianThongBao > 0 && !thongBao.empty()) {
            SDL_Color mauThongBao;
            if (thongBao.find("+") != std::string::npos)
                mauThongBao = { 46, 204, 113, 255 };
            else if (thongBao.find("Sai") != std::string::npos)
                mauThongBao = { 231, 76, 60, 255 };
            else
                mauThongBao = { 241, 196, 15, 255 };
            TextureManager::veChu(boVe, fontChu, thongBao,
                chieuRongCuaSo / 2.0f, chieuCaoCuaSo / 2.0f - 20, mauThongBao, true);
        }
    }

    if (trangThai == TRANG_THAI_THANG) {
        SDL_Color mauVang = { 255, 215, 0, 255 };
        TextureManager::veChu(boVe, fontLon, "LEVEL COMPLETE!",
            chieuRongCuaSo / 2.0f, chieuCaoCuaSo / 2.0f - 40, mauVang, true);

        SDL_Color mauTrang = { 200, 200, 200, 255 };
        std::string chuBonus = "+50 bonus coins!";
        TextureManager::veChu(boVe, fontChu, chuBonus,
            chieuRongCuaSo / 2.0f, chieuCaoCuaSo / 2.0f + 20, mauTrang, true);

        nutTiepTheo.veLen(boVe, fontChu);
    }

    SDL_RenderPresent(boVe);
}

void Game::donDep() {
    if (fontNho) { TTF_CloseFont(fontNho); fontNho = nullptr; }
    if (fontChu) { TTF_CloseFont(fontChu); fontChu = nullptr; }
    if (fontLon) { TTF_CloseFont(fontLon); fontLon = nullptr; }
    if (boVe) { SDL_DestroyRenderer(boVe); boVe = nullptr; }
    if (cuaSo) { SDL_DestroyWindow(cuaSo); cuaSo = nullptr; }
    TTF_Quit();
    SDL_Quit();
}