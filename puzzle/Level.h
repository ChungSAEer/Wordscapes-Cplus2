#pragma once // dung de goi lai file nay nhieu lan ma khong bi loi
#include <string>
#include <vector>

struct ViTriTu {
    std::string tu;
    int dong, cot;
    bool ngang;
    bool daTim;
};

struct ThongTinLevel {
    std::string cacChuCai;
    std::vector<std::string> dapAn;
    int soDong, soCot;
    std::vector<ViTriTu> viTriCacTu;
};

class Level {
public:
    void khoiTao(ThongTinLevel thongTin);
    ThongTinLevel layThongTin();
    bool themTuDaTim(const std::string& tu);
    bool daHoanThanh();
    std::vector<std::string> layDapAnChuaTim();
    std::string goiY();

private:
    ThongTinLevel duLieu;
    std::vector<std::string> tuDaTim;
};
