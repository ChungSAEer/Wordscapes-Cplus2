#pragma once // dung de goi lai file nay nhieu lan ma khong bi loi
#include <string>
#include <vector>

// cau truc luu thong tin ve vi tri mot tu trong bang dien chu
struct ViTriTu {
    std::string tu;   // noi dung tu do
    int dong, cot;    // toa do danh tran bat dau (dong, cot)
    bool ngang;       // chieu cua tu: true (ngang), false (doc)
    bool daTim;       // danh dau tu nay da duoc nguoi choi tim thay chua
};

// cau truc chua toan bo du lieu khoi tao mot level
struct ThongTinLevel {
    std::string cacChuCai;           // cac chu cai duoc cung cap cho nguoi choi ghep
    std::vector<std::string> dapAn;  // danh sach cac dap an cua tro choi
    int soDong, soCot;               // kich thuoc ma tran bang dien chu
    std::vector<ViTriTu> viTriCacTu; // danh sach mo ta vi tri cua tung tu
};

// Lop quan ly thong tin, tien trinh nguoi choi trong 1 man game (cap do)
class Level {
public:
    // khoi tao man choi voi du lieu cap do truyen vao
    void khoiTao(ThongTinLevel thongTin);
    
    // lay du lieu thong tin man choi hien tai
    ThongTinLevel layThongTin();
    
    // them tu nguoi choi moi tim thay. tra ve true neu tu do ton tai va chua bi doan truoc do
    bool themTuDaTim(const std::string& tu);
    
    // kiem tra xem toan bo cac tu trong man nay da duoc doan dung chua
    bool daHoanThanh();
    
    // lay danh sach nhung tu chua duoc nguoi choi tim thay
    std::vector<std::string> layDapAnChuaTim();
    
    // tra ve mot tu ngau nhien chua duoc tim thay lam goi y cho nguoi choi
    std::string goiY();

private:
    ThongTinLevel duLieu; // du lieu cua level hien tai
    std::vector<std::string> tuDaTim; // luu nhung tu nguoi choi da doan dung
};
