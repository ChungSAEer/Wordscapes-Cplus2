#pragma once
#include <string>
#include <set>
#include <vector>

class WordValidator {
public:
    void khoiTao(std::vector<std::string> dapAn);
    bool laDapAnDung(const std::string& tu);
    bool daTuNayRoi(const std::string& tu);
    void danhDauDaTim(const std::string& tu);
    void xoaHet();

private:
    std::set<std::string> danhSachDapAn;
    std::set<std::string> daTim;
};
