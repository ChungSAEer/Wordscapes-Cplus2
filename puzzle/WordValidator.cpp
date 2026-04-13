// quan ly danh sach dap an, tu da tim, kiem tra tu hop le, danh dau tu da tim, xoa het
#include "WordValidator.h"

void WordValidator::khoiTao(std::vector<std::string> dapAn) {
    danhSachDapAn.clear();
    daTim.clear();
    for (auto& s : dapAn)
        danhSachDapAn.insert(s);
}

bool WordValidator::laDapAnDung(const std::string& tu) {
    return danhSachDapAn.count(tu) > 0;
}

bool WordValidator::daTuNayRoi(const std::string& tu) {
    return daTim.count(tu) > 0;
}

void WordValidator::danhDauDaTim(const std::string& tu) {
    daTim.insert(tu);
}

void WordValidator::xoaHet() {
    daTim.clear();
}
