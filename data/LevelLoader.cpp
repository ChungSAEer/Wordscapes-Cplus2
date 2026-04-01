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
        {{"ACT", 0, 0, true, false}, {"CAT", 0, 0, false, false}});

    themLevel("DOG", {"DOG", "GOD"}, 3, 3,
        {{"DOG", 1, 0, true, false}, {"GOD", 0, 1, false, false}});

    themLevel("SUN", {"SUN", "NUS"}, 3, 3,
        {{"SUN", 1, 0, true, false}, {"NUS", 0, 1, false, false}});

    themLevel("TOP", {"TOP", "POT"}, 3, 3,
        {{"TOP", 1, 0, true, false}, {"POT", 0, 1, false, false}});

    themLevel("RAT", {"RAT", "TAR", "ART"}, 4, 4,
        {{"RAT", 2, 1, true, false}, {"TAR", 1, 2, false, false}, {"ART", 1, 1, false, false}});

    themLevel("NET", {"NET", "TEN"}, 3, 3,
        {{"NET", 1, 0, true, false}, {"TEN", 0, 1, false, false}});

    themLevel("PAN", {"PAN", "NAP"}, 3, 3,
        {{"PAN", 1, 0, true, false}, {"NAP", 0, 1, false, false}});

    themLevel("GUN", {"GUN", "NUG"}, 3, 3,
        {{"GUN", 1, 0, true, false}, {"NUG", 0, 1, false, false}});

    themLevel("PIN", {"PIN", "NIP"}, 3, 3,
        {{"PIN", 1, 0, true, false}, {"NIP", 0, 1, false, false}});

    themLevel("CUP", {"CUP", "UP"}, 3, 3,
        {{"CUP", 0, 0, true, false}, {"UP", 0, 1, false, false}});

    themLevel("HATE", {"HATE", "EAT", "HAT"}, 4, 4,
        {{"HATE", 2, 0, true, false}, {"EAT", 1, 1, false, false}, {"HAT", 0, 2, false, false}});

    themLevel("LATE", {"LATE", "ALE", "LET"}, 5, 4,
        {{"LATE", 2, 0, true, false}, {"ALE", 2, 1, false, false}, {"LET", 0, 2, false, false}});

    themLevel("RACE", {"RACE", "CAR", "ACE"}, 4, 4,
        {{"RACE", 1, 0, true, false}, {"CAR", 1, 2, false, false}, {"ACE", 1, 1, false, false}});

    themLevel("LIFE", {"LIFE", "LIE", "FILE"}, 5, 4,
        {{"LIFE", 2, 0, true, false}, {"LIE", 2, 0, false, false}, {"FILE", 1, 1, false, false}});

    themLevel("TIME", {"TIME", "TIE", "MET"}, 5, 4,
        {{"TIME", 2, 0, true, false}, {"TIE", 2, 0, false, false}, {"MET", 2, 2, false, false}});

    themLevel("NOSE", {"NOSE", "ONE", "SON"}, 5, 4,
        {{"NOSE", 2, 0, true, false}, {"ONE", 2, 1, false, false}, {"SON", 2, 2, false, false}});

    themLevel("LOVE", {"LOVE", "OLE"}, 4, 4,
        {{"LOVE", 1, 0, true, false}, {"OLE", 1, 1, false, false}});

    themLevel("NAME", {"NAME", "MAN", "MEN"}, 4, 4,
        {{"NAME", 1, 0, true, false}, {"MAN", 0, 2, false, false}, {"MEN", 1, 2, false, false}});

    themLevel("GAME", {"GAME", "AGE", "GEM"}, 4, 4,
        {{"GAME", 1, 0, true, false}, {"AGE", 0, 1, false, false}, {"GEM", 1, 1, false, false}});

    themLevel("HOPE", {"HOPE", "HOP", "HOE"}, 4, 4,
        {{"HOPE", 1, 0, true, false}, {"HOP", 0, 2, false, false}, {"HOE", 1, 0, false, false}});
}

ThongTinLevel LevelLoader::layLevel(int soThuTu) {
    if (soThuTu >= 0 && soThuTu < (int)tatCaLevel.size())
        return tatCaLevel[soThuTu];
    return tatCaLevel[0];
}

int LevelLoader::tongSoLevel() {
    return (int)tatCaLevel.size();
}
