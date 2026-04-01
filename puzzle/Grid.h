#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>
#include <vector>
#include <string>
#include "Level.h"

struct OVuong {
    char kyTu;
    bool daLo;
    bool coTonTai;
    float hieuUng;
};

class Grid {
public:
    void khoiTao(int dong, int cot, std::vector<ViTriTu> danhSach);
    void veLen(SDL_Renderer* ve, TTF_Font* font, float batDauX, float batDauY, float kichThuoc);
    bool dienTuVao(const std::string& tu, std::vector<ViTriTu>& viTriCacTu);
    bool daXongChua();
    void capNhat(float dt);
    int laySoDong();
    int laySoCot();
    void loMotChu(const std::string& tu, std::vector<ViTriTu>& viTriCacTu);

private:
    std::vector<std::vector<OVuong>> mangO;
    int soDong, soCot;
};
