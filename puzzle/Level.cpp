#include "Level.h"
#include <algorithm>

void Level::khoiTao(ThongTinLevel thongTin) {
    duLieu = thongTin;
    tuDaTim.clear();
    for (auto& vt : duLieu.viTriCacTu)
        vt.daTim = false;
}

ThongTinLevel Level::layThongTin() {
    return duLieu;
}

bool Level::themTuDaTim(const std::string& tu) {
    for (auto& s : tuDaTim)
        if (s == tu) return false;

    bool hopLe = false;
    for (auto& vt : duLieu.viTriCacTu) {
        if (vt.tu == tu && !vt.daTim) {
            vt.daTim = true;
            hopLe = true;
        }
    }
    if (hopLe)
        tuDaTim.push_back(tu);
    return hopLe;
}

bool Level::daHoanThanh() {
    for (auto& vt : duLieu.viTriCacTu)
        if (!vt.daTim) return false;
    return true;
}

std::vector<std::string> Level::layDapAnChuaTim() {
    std::vector<std::string> ketQua;
    for (auto& vt : duLieu.viTriCacTu)
        if (!vt.daTim)
            ketQua.push_back(vt.tu);
    return ketQua;
}

std::string Level::goiY() {
    for (auto& vt : duLieu.viTriCacTu)
        if (!vt.daTim) return vt.tu;
    return "";
}
