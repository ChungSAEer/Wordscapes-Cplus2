// quan ly vong chu, ve vong chu, xu ly chon chu bang chuot, lay tu dang ghep, xoa tu dang ghep, tron chu
#include "LetterWheel.h"
#include "../core/TextureManager.h"
#include <cmath>
#include <algorithm>
#include <cstdlib>

#define SO_PI 3.14159265358979323846f

void LetterWheel::khoiTao(const std::string& cacChu, float _tamX, float _tamY, float _banKinhVong) {
    tamX = _tamX;
    tamY = _tamY;
    banKinhVong = _banKinhVong;
    dangKeoThat = false;
    tuHienTai = "";
    danhSachChu.clear();
    chuDaChon.clear();

    for (int i = 0; i < (int)cacChu.size(); i++) {
        ChuTrenVong chu;
        chu.kyTu = cacChu[i];
        float goc = -SO_PI / 2 + i * 2 * SO_PI / cacChu.size();
        chu.gocHienTai = goc;
        chu.viTriX = tamX + cosf(goc) * banKinhVong;
        chu.viTriY = tamY + sinf(goc) * banKinhVong;
        chu.banKinh = 30.0f;
        chu.dangChon = false;
        danhSachChu.push_back(chu);
    }
}

void LetterWheel::veLen(SDL_Renderer* ve, TTF_Font* font) {
    SDL_Color mauVong = { 40, 45, 70, 255 };
    TextureManager::veHinhTronDoc(ve, tamX, tamY, banKinhVong + 45, mauVong);

    SDL_Color mauVongTrong = { 30, 35, 55, 255 };
    TextureManager::veHinhTronDoc(ve, tamX, tamY, banKinhVong - 15, mauVongTrong);

    for (int i = 1; i < (int)chuDaChon.size(); i++) {
        auto& c1 = danhSachChu[chuDaChon[i - 1]];
        auto& c2 = danhSachChu[chuDaChon[i]];
        SDL_Color mauDuong = { 255, 200, 50, 200 };
        TextureManager::veDuongThang(ve, c1.viTriX, c1.viTriY, c2.viTriX, c2.viTriY, 4.0f, mauDuong);
    }

    for (int i = 0; i < (int)danhSachChu.size(); i++) {
        auto& chu = danhSachChu[i];
        SDL_Color mauNen;
        if (chu.dangChon) {
            mauNen = { 255, 200, 50, 255 };
        } else {
            mauNen = { 220, 225, 240, 255 };
        }
        TextureManager::veHinhTronDoc(ve, chu.viTriX, chu.viTriY, chu.banKinh, mauNen);

        char chuoi[2] = { chu.kyTu, 0 };
        SDL_Color mauChu = { 30, 30, 50, 255 };
        TextureManager::veChu(ve, font, chuoi, chu.viTriX, chu.viTriY, mauChu, true);
    }
}

int LetterWheel::timChuTaiViTri(float x, float y) {
    for (int i = 0; i < (int)danhSachChu.size(); i++) {
        float dx = x - danhSachChu[i].viTriX;
        float dy = y - danhSachChu[i].viTriY;
        if (dx * dx + dy * dy <= danhSachChu[i].banKinh * danhSachChu[i].banKinh)
            return i;
    }
    return -1;
}

void LetterWheel::xuLyChuot(float chuotX, float chuotY, bool nhanMoi, bool nhaChuot, bool dangGiu) {
    if (nhanMoi) {
        int viTri = timChuTaiViTri(chuotX, chuotY);
        if (viTri >= 0) {
            dangKeoThat = true;
            chuDaChon.clear();
            tuHienTai = "";
            for (auto& c : danhSachChu) c.dangChon = false;

            chuDaChon.push_back(viTri);
            danhSachChu[viTri].dangChon = true;
            tuHienTai += danhSachChu[viTri].kyTu;
        }
    }

    if (dangKeoThat && dangGiu) {
        int viTri = timChuTaiViTri(chuotX, chuotY);
        if (viTri >= 0 && !danhSachChu[viTri].dangChon) {
            chuDaChon.push_back(viTri);
            danhSachChu[viTri].dangChon = true;
            tuHienTai += danhSachChu[viTri].kyTu;
        }
    }

    if (nhaChuot && dangKeoThat) {
        dangKeoThat = false;
    }
}

std::string LetterWheel::layTuDangGhep() {
    return tuHienTai;
}

void LetterWheel::xoaTuDangGhep() {
    tuHienTai = "";
    chuDaChon.clear();
    for (auto& c : danhSachChu) c.dangChon = false;
}

bool LetterWheel::dangKeoKhong() {
    return dangKeoThat;
}

void LetterWheel::tronChu() {
    int soLuong = (int)danhSachChu.size();
    for (int i = soLuong - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char tam = danhSachChu[i].kyTu;
        danhSachChu[i].kyTu = danhSachChu[j].kyTu;
        danhSachChu[j].kyTu = tam;
    }
}
