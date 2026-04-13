#pragma once // dam bao file nay chi duoc include mot lan
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include <string>
#include "Level.h"

// cau truc du lieu luu thong tin cua mot o chu tren bang
struct OVuong {
    char kyTu;       // ky tu chua trong o
    bool daLo;       // da duoc doan dung chua
    bool coTonTai;   // o nay co thuoc ve mot tu nao do khong
    float hieuUng;   // hieu ung sang len khi vua lo xong
};

// lop Grid quan ly luoi cac tu (crossword) tren man hinh
class Grid {
public:
    // khoi tao bang o vao cac vi tri tu
    void khoiTao(int dong, int cot, std::vector<ViTriTu> danhSach);
    
    // ve toan bo cac o tren bang len man hinh
    void veLen(SDL_Renderer* ve, TTF_Font* font, float batDauX, float batDauY, float kichThuoc);
    
    // dien mot tu nguoi choi vua doan dung vao bang
    bool dienTuVao(const std::string& tu, std::vector<ViTriTu>& viTriCacTu);
    
    // kiem tra xem tat ca cac o da duoc lo hay chua
    bool daXongChua();
    
    // cap nhat hieu ung tung khung hinh
    void capNhat(float dt);
    
    int laySoDong();
    int laySoCot();
    
    // chuc nang goi y, mo mot chu cai ngau nhien trong mọt tu chua mo
    void loMotChu(const std::string& tu, std::vector<ViTriTu>& viTriCacTu);

private:
    std::vector<std::vector<OVuong>> mangO; // ma tran cac o vuong
    int soDong, soCot;
};
