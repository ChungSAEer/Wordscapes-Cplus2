#pragma once
#include <vector>
#include "../puzzle/Level.h"

class LevelLoader {
public:
    void docDuLieu();
    ThongTinLevel layLevel(int soThuTu);
    int tongSoLevel();

private:
    std::vector<ThongTinLevel> tatCaLevel;
    void themLevel(const std::string& chu, std::vector<std::string> dapAn,
                   int dong, int cot, std::vector<ViTriTu> viTri);
};
