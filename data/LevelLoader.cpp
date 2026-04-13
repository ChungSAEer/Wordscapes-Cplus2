// load du lieu level, co the them level moi vao day
#include "LevelLoader.h"

void LevelLoader::themLevel(const std::string& chu, std::vector<std::string> dapAn,
                             int dong, int cot, std::vector<ViTriTu> viTri) {
    ThongTinLevel lv;
    lv.cacChuCai = chu;
    lv.dapAn = dapAn;
    lv.soDong = dong;
    lv.soCot = cot;
    lv.viTriCacTu = viTri;
    tatCaLevel.push_back(lv);
}

void LevelLoader::docDuLieu() {
    tatCaLevel.clear();

    themLevel("CAT", {"CAT", "ACT"}, 3, 3,
        {{"ACT", 0, 0, true, false}, {"CAT", 0, 1, false, false}});

    themLevel("DOG", {"DOG", "GOD"}, 3, 3,
        {{"DOG", 1, 0, true, false}, {"GOD", 0, 1, false, false}});

    themLevel("SUN", {"SUN", "US"}, 3, 3,
        {{"SUN", 1, 0, true, false}, {"US", 1, 1, false, false}});

    themLevel("TOP", {"TOP", "POT"}, 3, 3,
        {{"TOP", 1, 0, true, false}, {"POT", 0, 1, false, false}});

    themLevel("RAT", {"RAT", "TAR", "ART"}, 3, 4,
        {{"RAT", 1, 0, true, false}, {"TAR", 0, 1, false, false}, {"ART", 2, 0, true, false}});

    themLevel("NET", {"NET", "TEN"}, 3, 3,
        {{"NET", 1, 0, true, false}, {"TEN", 0, 1, false, false}});

    themLevel("PAN", {"PAN", "NAP"}, 3, 3,
        {{"PAN", 1, 0, true, false}, {"NAP", 0, 1, false, false}});

    themLevel("YOUNG", {"YOUNG", "GUN", "GUY", "YOU"}, 4, 5,
        {{"YOUNG", 2, 0, true, false}, {"GUY", 0, 0, false, false}, {"YOU", 1, 1, false, false}, {"GUN", 1, 2, false, false}});

    themLevel("PIN", {"PIN", "NIP"}, 3, 3,
        {{"PIN", 1, 0, true, false}, {"NIP", 0, 1, false, false}});

    themLevel("CUP", {"CUP", "UP"}, 3, 3,
        {{"CUP", 1, 0, true, false}, {"UP", 1, 1, false, false}});

    themLevel("HATE", {"HATE", "EAT", "HAT"}, 4, 4,
        {{"HATE", 0, 0, true, false}, {"HAT", 0, 0, false, false}, {"EAT", 0, 3, false, false}});

    themLevel("LATE", {"LATE", "ATE", "LET"}, 4, 4,
        {{"LATE", 1, 0, true, false}, {"ATE", 1, 1, false, false}, {"LET", 0, 3, false, false}});

    themLevel("RACE", {"RACE", "CAR", "ACE"}, 4, 4,
        {{"RACE", 1, 0, true, false}, {"ACE", 1, 1, false, false}, {"CAR", 1, 2, false, false}});

    themLevel("LIFE", {"LIFE", "LIE", "FILE"}, 5, 4,
        {{"LIFE", 2, 0, true, false}, {"FILE", 1, 1, false, false}, {"LIE", 0, 3, false, false}});

    themLevel("TIME", {"TIME", "TIE", "MET"}, 5, 4,
        {{"TIME", 0, 0, true, false}, {"TIE", 0, 0, false, false}, {"MET", 0, 2, false, false}});

    themLevel("NOSE", {"NOSE", "ONE", "SON"}, 4, 4,
        {{"NOSE", 0, 0, true, false}, {"ONE", 0, 1, false, false}, {"SON", 0, 2, false, false}});

    themLevel("LOVE", {"LOVE", "LEO"}, 3, 4,
        {{"LOVE", 0, 0, true, false}, {"LEO", 0, 0, false, false}});

    themLevel("NAME", {"NAME", "MAN", "MEN"}, 4, 4,
        {{"NAME", 1, 0, true, false}, {"MAN", 1, 2, false, false}, {"MEN", 0, 3, false, false}});

    themLevel("GAME", {"GAME", "AGE", "GEM"}, 5, 4,
        {{"GAME", 2, 0, true, false}, {"AGE", 2, 1, false, false}, {"GEM", 0, 2, false, false}});

    themLevel("HOPE", {"HOPE", "HOP", "HOE"}, 4, 4,
        {{"HOPE", 1, 0, true, false}, {"HOP", 1, 0, false, false}, {"HOE", 0, 1, false, false}});
}

ThongTinLevel LevelLoader::layLevel(int soThuTu) {
    if (soThuTu >= 0 && soThuTu < (int)tatCaLevel.size())
        return tatCaLevel[soThuTu];
    return tatCaLevel[0];
}

int LevelLoader::tongSoLevel() {
    return (int)tatCaLevel.size();
}
