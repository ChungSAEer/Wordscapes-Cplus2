
#include "Grid.h"
#include "../core/TextureManager.h"

void Grid::khoiTao(int dong, int cot, std::vector<ViTriTu> danhSach) {
    soDong = dong;
    soCot = cot;
    mangO.clear();
    mangO.resize(dong, std::vector<OVuong>(cot, { ' ', false, false, 0.0f }));

    for (auto& vt : danhSach) {
        for (int i = 0; i < (int)vt.tu.size(); i++) {
            int d = vt.dong + (vt.ngang ? 0 : i);
            int c = vt.cot + (vt.ngang ? i : 0);
            if (d >= 0 && d < soDong && c >= 0 && c < soCot) {
                mangO[d][c].kyTu = vt.tu[i];
                mangO[d][c].coTonTai = true;
            }
        }
    }
}

void Grid::veLen(SDL_Renderer* ve, TTF_Font* font, float batDauX, float batDauY, float kichThuoc) {
    float khoangCach = 2.0f;

    for (int d = 0; d < soDong; d++) {
        for (int c = 0; c < soCot; c++) {
            if (!mangO[d][c].coTonTai) continue;

            float ox = batDauX + c * (kichThuoc + khoangCach);
            float oy = batDauY + d * (kichThuoc + khoangCach);

            SDL_Color mauNen;
            if (mangO[d][c].daLo) {
                float ef = mangO[d][c].hieuUng;
                Uint8 xanh = (Uint8)(180 + ef * 75);
                mauNen = { xanh, (Uint8)(xanh - 20), 255, 255 };
            } else {
                mauNen = { 45, 50, 80, 255 };
            }

            TextureManager::veHinhChuNhatBoGoc(ve, ox, oy, kichThuoc, kichThuoc, 6.0f, mauNen);

            SDL_SetRenderDrawColor(ve, 80, 90, 130, 255);
            SDL_FRect vienNgoai = { ox, oy, kichThuoc, kichThuoc };
            SDL_RenderRect(ve, &vienNgoai);

            if (mangO[d][c].daLo) {
                char chuoi[2] = { mangO[d][c].kyTu, 0 };
                SDL_Color mauChu = { 30, 30, 60, 255 };
                TextureManager::veChu(ve, font, chuoi,
                    ox + kichThuoc / 2, oy + kichThuoc / 2, mauChu, true);
            }
        }
    }
}

bool Grid::dienTuVao(const std::string& tu, std::vector<ViTriTu>& viTriCacTu) {
    bool daDien = false;
    for (auto& vt : viTriCacTu) {
        if (vt.tu == tu && vt.daTim) {
            for (int i = 0; i < (int)vt.tu.size(); i++) {
                int d = vt.dong + (vt.ngang ? 0 : i);
                int c = vt.cot + (vt.ngang ? i : 0);
                if (d >= 0 && d < soDong && c >= 0 && c < soCot) {
                    mangO[d][c].daLo = true;
                    mangO[d][c].hieuUng = 1.0f;
                }
            }
            daDien = true;
        }
    }
    return daDien;
}

bool Grid::daXongChua() {
    for (int d = 0; d < soDong; d++)
        for (int c = 0; c < soCot; c++)
            if (mangO[d][c].coTonTai && !mangO[d][c].daLo)
                return false;
    return true;
}

void Grid::capNhat(float dt) {
    for (int d = 0; d < soDong; d++)
        for (int c = 0; c < soCot; c++)
            if (mangO[d][c].hieuUng > 0)
                mangO[d][c].hieuUng -= dt * 2.0f;
}

int Grid::laySoDong() { return soDong; }
int Grid::laySoCot() { return soCot; }

void Grid::loMotChu(const std::string& tu, std::vector<ViTriTu>& viTriCacTu) {
    for (auto& vt : viTriCacTu) {
        if (vt.tu == tu && !vt.daTim) {
            std::vector<std::pair<int,int>> chuaCuaLo;
            for (int i = 0; i < (int)vt.tu.size(); i++) {
                int d = vt.dong + (vt.ngang ? 0 : i);
                int c = vt.cot + (vt.ngang ? i : 0);
                if (d >= 0 && d < soDong && c >= 0 && c < soCot && !mangO[d][c].daLo) {
                    chuaCuaLo.push_back({d, c});
                }
            }
            if (!chuaCuaLo.empty()) {
                int idx = rand() % chuaCuaLo.size();
                auto [d, c] = chuaCuaLo[idx];
                mangO[d][c].daLo = true;
                mangO[d][c].hieuUng = 1.0f;
            }
            break;
        }
    }
}
