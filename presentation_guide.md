# 🎮 Hướng Dẫn Thuyết Trình Project: Wordscapes C++ (SDL3)

Tài liệu này tóm tắt cấu trúc dự án, luồng hoạt động chính, chức năng của từng tệp tin và các vị trí mã nguồn mà bạn có thể cấu hình lại để phục vụ cho buổi thuyết trình trước Giảng Viên.

---

## 1. Cấu Trúc Thư Mục Chung (Directory Structure)
Dự án được cấu trúc theo mô hình khá chuẩn cho các game C++:

- `src/`: Điểm bắt đầu (entry point) của chương trình.
- `core/`: Chứa các file cốt lõi của game như khung cửa sổ, vòng lặp game, quản lý texture (ảnh) và thu thập thao tác bấm chuột/phím.
- `puzzle/`: "Trái tim" logic của trò chơi ghép chữ, tính toán bảng lưới (Grid), vòng xoay chữ cái (LetterWheel) và so khớp từ vựng.
- `ui/`: Các thành phần giao diện người dùng như màn hình Menu, các nút bấm, Thanh thông tin (HUD).
- `data/`: Phụ trách nạp dữ liệu cấp độ (đọc `levels.json`) để đưa cấu trúc trò chơi vào RAM.
- `assets/`: Nơi lưu trữ tài nguyên hình ảnh (`.png`), font chữ (`.ttf`), âm thanh (`.wav`) và file dữ liệu màn chơi (`.json`).

---

## 2. Các Thành Phần File Chính (Key Files)

### 2.1 Điểm bắt đầu
*   **`src/main.cpp`**: 
    Hàm `main` được gọi đầu tiên. Tại đây, lớp `Game` được khởi tạo và chạy với tên tiêu đề và kích thước màn hình.

### 2.2 Core Game Loop
*   **`core/Game.cpp`** / **`Game.h`**: Lớp điều khiển chính của trò chơi.  
    - Giao tiếp với SDL3 để mở Window.
    - Duy trì "Vòng lặp Game" (Game Loop).
    - Có 4 hàm quan trọng: `khoiDong()` (Setup), `xuLySuKien()` (Input chuột phím), `capNhat()` (Update logic), và `hienThi()` (Render đồ hoạ).
*   **`core/TextureManager.cpp`**: Đơn giản hoá việc vẽ hình khối (bo góc), vẽ chữ (Text) và Load file ảnh bằng thư viện phụ `SDL3_image` và `SDL3_ttf`.

### 2.3 Phân hệ xếp chữ (Puzzle)
*   **`puzzle/Grid.cpp`**: Chịu trách nhiệm hiển thị các ô lưới hình vuông ở giữa màn hình. Khi người chơi giải đúng 1 từ, nó có hiệu ứng làm loé sáng (fade màu) báo hiệu từ lộ ra.
*   **`puzzle/LetterWheel.cpp`**: Quản lý cái "bánh xe" chữ cái nằm dưới cùng. Xử lý logic khi người chơi giữ và kéo chuột giữa các nút tròn chứa chữ cái và vẽ đường chỉ nối giữa chúng.
*   **`puzzle/WordValidator.cpp`**: Lớp tiện ích kiểm tra xem chuỗi (string) người chơi vừa nối có khớp với bất kỳ từ nào được cấu hình trong `levels.json` hay không.

### 2.4 Giao Diện (UI - User Interface)
*   **`ui/Menu.cpp`**: Nơi vẽ màn hình khởi động đầu tiên với hiệu ứng chuyển sắc (gradient), các hạt (particles) làm "ngôi sao bay", và logo text lấp lánh (halo effect).
*   **`ui/HUD.cpp`**: Vẽ thanh thông tin ở trên cùng (hiện số vàng/coins, Level hiện tại).
*   **`ui/Button.cpp`**: Định nghĩa một nút bấm có khả năng biết được khi nào người chơi kéo chuột ngang qua (Hover) hay nhấn 클릭 (Click).

---

## 3. Luồng Hoạt Động (Flow of Execution)

Để bạn dễ giải thích nguyên lý hoạt động cho Giảng Viên:

1.  **Bước 1: Khởi động (Init)**
    - Trong `main.cpp` gọi `troChoi.khoiDong()`.
    - Game thiết lập môi trường SDL3, nạp Fonts, nạp Audio và ảnh nền `bg.png`. 
    - Nạp `levels.json` vào danh sách. Trạng thái Game đặt là `TRANG_THAI_MENU`.

2.  **Bước 2: Vòng lặp liên tục (Game Loop)**
    - Chuyển quyền vào phương thức `Game::chay()`. 
    - Ở đây có một vòng `while(dangChay)` cứ khoảng ~16ms sẽ chạy 1 lần (~60 Hình/giây).
    - Nó thu thập input -> Update -> Render ảnh rồi xoá màn hình render lại.

3.  **Bước 3: Tương tác Menu (Menu to Game)**
    - Người chơi ấn nút **Start**. Trạng thái Game chuyển sang `TRANG_THAI_CHOI`.
    - Hệ thống gọi hàm `batDauLevel(0)`. Vòng chữ và Bảng ô chữ (`Grid`) sẽ đọc tọa độ từ level 0 và xếp chữ lên màn hình hiển thị.

4.  **Bước 4: Logic nối từ (Gameplay Logic)**
    - Người chơi nhấn, giữ và rê chuột trên các cụm từ (xử lý ở trong `LetterWheel`).
    - Khi thả chuột, hàm `kiemTraTu()` bên trong `Game.cpp` được gọi.
    - Nếu đúng -> Cộng vàng (Coin += 10), báo thông báo xanh. Truyền từ này sang cho đối tượng `Grid` để lật các ô vuông ra.
    - Nếu sai -> Báo chữ màu cam/đỏ.
    - Khi lật hết ô vuông -> Chuyển sang `TRANG_THAI_THANG` và có tuỳ chọn lên Level kế tiếp.

---

## 4. Những Chỗ Nên Chỉnh Sửa Demo (Tweakable Demo Parameters)

Để chứng minh bạn hiểu rõ Code thay vì chỉ copy, hãy tự tin vào thay đổi những con số hiển thị. Giảng viên rất thích khi sinh viên làm điều này:

> [!TIP]
> **1. Kích thước cửa sổ (Window Size)**
> Phóng to thu nhỏ màn hình gốc. Thay đổi tại `src/main.cpp` - Dòng `6`:
> ```cpp
> troChoi.khoiDong("Wordscapes - Tro Choi Ghep Chu", 900, 1000); // Đổi 900x1000
> ```

> [!TIP]
> **2. Kích thước viền Ô Lưới Nhỏ Lại, Rộng Ra (Grid Cells)**
> Bạn có thể thay đổi kích thước từng ô vuông điền chữ ở `core/Game.cpp` - Dòng `263`:
> ```cpp
> float kichThuocO = 45.0f; // Thay bằng 60.0f để ô chữ bự hơn
> float khoangCach = 2.0f;  // Khoảng hở giữa 2 ô vuông
> ```

> [!TIP]
> **3. Đẩy "Vòng chữ cái" Lên Cao hoặc Xuống Thấp (Wheel Position)**
> Điều tiết toạ độ tâm điểm của hình quạt chữ ở `core/Game.cpp` - Dòng `106`:
> ```cpp
> float tamVongY = chieuCaoCuaSo - 160.0f; 
> // VD màn hình cao 1000 thì nó đang cách đáy 160px.
> float banKinh = 80.0f; // Mở rộng vòng kéo chữ bự ra
> ```

> [!TIP]
> **4. Chỉnh lượng Vàng/Coin (Economy System)**
> Rất dễ giải thích logic thưởng phạt. Mở `core/Game.cpp` - Tại dòng `131` & `215`:
> ```cpp
> // Được bao bọc vàng khi trả lời đúng (Game.cpp L-131)
> soXu += 10; 
> // Số vàng trừ đi khi bấm Hint (Gợi ý) (Game.cpp L-215)
> soXu -= 20;
> ```

> [!TIP]
> **5. Toạ Độ Các Nút Start và Exit (Menu Positioning)**
> Hiểu cách vẽ bằng tay không xài engine UI kéo thả. Mở `ui/Menu.cpp` - Dòng `52-53`:
> ```cpp
> float giuaX = chieuRong / 2.0f;
> nutChoi.khoiTao(giuaX - 110, chieuCao / 2.0f + 30,  220, 58, texNutStart);  // Toạ độ X, Toạ độ Y, Width, Height
> nutThoat.khoiTao(giuaX - 110, chieuCao / 2.0f + 108, 220, 58, texNutExit);
> ```

---
**Chúc bạn thuyết trình đồ án tốt nhé! Bản đồ kiến trúc Project này rất "sạch" và chia mô đun OOP rất bài bản nên Giảng viên sẽ đánh giá rất cao độ chuẩn mực của nó.**
