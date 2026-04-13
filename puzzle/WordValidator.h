#pragma once // dam bao file nay chi duoc include mot lan
#include <string>
#include <set>
#include <vector>

// Lop kiem tra xem tu nguoi choi nhap vao co phai la dap an hop le hay khong
class WordValidator {
public:
    // khoi tao trinh kiem tra voi danh sach tat ca dap an cua man choi
    void khoiTao(std::vector<std::string> dapAn);
    
    // kiem tra xem tu nay co nam trong danh sach dap an khong
    bool laDapAnDung(const std::string& tu);
    
    // kiem tra xem tu nay da duoc nguoi choi tim thay truoc do chua
    bool daTuNayRoi(const std::string& tu);
    
    // danh dau mot tu la da duoc doan dung de khong bi tinh diem trung nua
    void danhDauDaTim(const std::string& tu);
    
    // xoa lich su nhung tu da tim thay (khi load level moi)
    void xoaHet();

private:
    std::set<std::string> danhSachDapAn; // tap hop luu cac tu la dap an
    std::set<std::string> daTim;         // tap hop luu cac tu nguoi choi da doan dung
};
