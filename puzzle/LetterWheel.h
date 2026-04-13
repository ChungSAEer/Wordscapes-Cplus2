#pragma once // dam bao file nay chi duoc include mot lan
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include <string>

// Luu tru thong tin mot chu cai tren vong tron
struct ChuTrenVong {
    char kyTu;          // ky tu chu cai
    float viTriX, viTriY; // vi tri tam
    float banKinh;      // ban kinh hinh tron chua chu
    bool dangChon;      // trang thai nguoi choi da noi chu nay vao doan chua
    float gocHienTai;   // goc hien tai tren vong tron de sap xep
};

// Lop quan ly vong tron chua cac chu cai, va xu ly noi chu
class LetterWheel {
public:
    // khoi tao vong chu, truyen vao cac chu cai, vi tri tam va ban kinh vong
    void khoiTao(const std::string& cacChu, float tamX, float tamY, float banKinhVong);
    
    // ham ve vong chu ra man hinh, ke ca cac duong noi
    void veLen(SDL_Renderer* ve, TTF_Font* font);
    
    // xu ly khi dang nhap chuot hoac keo qua cac chu cai
    void xuLyChuot(float chuotX, float chuotY, bool nhanMoi, bool nhaChuot, bool dangGiu);
    
    // tra ve chuoi ky tu nguoi choi dang ghep
    std::string layTuDangGhep();
    
    // reset/xoa bo tu dang ghep de bat dau tu moi
    void xoaTuDangGhep();
    
    // cho biet nguoi choi co dang thao tac tren vong chu khong
    bool dangKeoKhong();
    
    // lenh dao vi tri ngau nhien cac chu cai tren vong (nup shuffle)
    void tronChu();

private:
    std::vector<ChuTrenVong> danhSachChu; // danh sach cac chu tren vong
    std::vector<int> chuDaChon; // thu tu (index) cac chu da duoc ket noi
    bool dangKeoThat; // co dang bat chuot khong
    float tamX, tamY, banKinhVong;
    std::string tuHienTai; // tu hien dang duoc ghep boi nguoi choi
    
    // tim kiem xem co chu nao nam o toa do x, y nay khong
    int timChuTaiViTri(float x, float y);
};
