# Wordscapes Clone (SDL2 + C++) – Roadmap Phát Triển

## Tổng quan dự án

Đây là dự án phát triển một **game giải đố dạng Wordscapes** bằng **C++ và thư viện SDL3**. Người chơi nối các chữ cái để tạo thành từ và điền vào **bảng ô chữ (crossword grid)**.

**Số lượng thành viên:** 3 người
**Thời gian dự kiến:** 4–6 tuần
**Mục tiêu:** Tạo một game chơi được với khoảng **50 level**.

---

# Tính năng của game

## Tính năng chính

* Bảng ô chữ (crossword grid)
* Vòng chữ cái để nối chữ (letter wheel)
* Kéo chuột để tạo từ
* Kiểm tra từ đúng / sai
* Điền từ vào bảng ô chữ
* Hệ thống nhiều level
* Menu chính
* Nút trộn chữ (Shuffle)
* Hệ thống gợi ý (Hint)

---

# Công nghệ sử dụng

| Thành phần      | Công nghệ            |
| --------------- | -------------------- |
| Ngôn ngữ        | C++                  |
| Thư viện đồ họa | SDL3                 |
| Load ảnh        | SDL_image            |
| Hiển thị chữ    | SDL_ttf              |
| Âm thanh        | SDL_mixer (optional) |

---

# Cấu trúc thư mục project

```
/src
    main.cpp
/core
    Game.cpp
    Input.cpp
    TextureManager.cpp
/puzzle
    Grid.cpp
    LetterWheel.cpp
    Level.cpp
    WordValidator.cpp
/ui
    Button.cpp
    Menu.cpp
    HUD.cpp
/data
    LevelLoader.cpp
/assets
    images
    fonts
    levels.json
    dictionary.txt
```

---

# Roadmap phát triển

## Phase 1 – Setup Project (3–4 ngày)

### Mục tiêu

Tạo nền tảng engine để game có thể chạy.

### Task

* Setup project C++ + SDL2
* Cài SDL_image và SDL_ttf
* Tạo cửa sổ game
* Tạo renderer
* Viết **game loop**
* Viết hệ thống input
* Render text bằng SDL_ttf

### Game Loop

```cpp
while (running)
{
    handleInput();
    update();
    render();
}
```

### Milestone

Game có thể:

* mở cửa sổ
* hiển thị chữ
* nhận input chuột

---

# Phase 2 – Prototype Gameplay (Tuần 2)

### Mục tiêu

Người chơi có thể **kéo các chữ để tạo thành từ**.

## Letter Wheel

Hiển thị các chữ cái dạng vòng tròn:

```
   A
T     E
   O
```

Struct chữ cái:

```cpp
struct Letter
{
    char value;
    SDL_Rect hitbox;
};
```

## Drag System

Logic:

```
mouse_down(letter)
bắt đầu tạo từ

mouse_drag
thêm chữ vào từ

mouse_up
submit từ
```

Ví dụ:

```
A → T → E
```

Tạo từ:

```
ATE
```

### Milestone

Prototype hoạt động:

* kéo chữ
* tạo từ

---

# Phase 3 – Puzzle System (Tuần 3)

### Mục tiêu

Điền từ vào **bảng ô chữ**.

## Grid System

Grid lưu dạng **ma trận 2 chiều**.

Ví dụ:

```
_ T _
A T E
_ E _
```

Struct ô chữ:

```cpp
struct Cell
{
    char letter;
    bool filled;
};
```

## Level Loader

Level được lưu trong file:

```
levels.json
```

Ví dụ:

```json
{
 "letters":["A","T","E"],
 "answers":[
   "ATE",
   "TEA",
   "EAT"
 ]
}
```

## Kiểm tra từ

Logic:

```
if word nằm trong đáp án
    điền vào grid
else if word có trong dictionary
    bonus word
else
    từ sai
```

### Milestone

Game có thể:

* tạo từ
* kiểm tra từ
* điền vào crossword

---

# Phase 4 – UI và Level System (Tuần 4)

### Mục tiêu

Game có menu và nhiều level.

## Menu System

Menu gồm:

```
Start
Exit
```

State của game:

```
MENU
PLAYING
LEVEL_COMPLETE
```

## Level Progression

Logic:

```
giải xong puzzle
→ sang level tiếp theo
```

## Shuffle Letters

Button:

```
Shuffle
```

Ví dụ:

```
A T E → T E A
```

## Hint System

Gợi ý 1 chữ.

Ví dụ:

```
_ A _
```

### Milestone

Game chơi được với:

* menu
* nhiều level
* hệ thống hint

---

# Phase 5 – Hoàn thiện (Tuần 5–6)

### Mục tiêu

Cải thiện trải nghiệm game.

## Animation

* highlight chữ
* animation khi đúng từ
* animation khi điền grid

## Sound

Thêm âm thanh:

```
click
correct word
level complete
```

## Score / Coin

Ví dụ:

```
đúng từ → +coin
dùng hint → -coin
```

## Tạo nội dung

Tạo khoảng:

```
50 level
```

---

# Phân chia công việc

## Dev 1 – Engine

* setup SDL
* game loop
* renderer
* input system
* state machine

## Dev 2 – Gameplay

* letter wheel
* drag system
* word builder
* shuffle

## Dev 3 – Puzzle + UI

* crossword grid
* level loader
* menu
* hint system

---

# Timeline

| Tuần   | Tiến độ        |
| ------ | -------------- |
| Tuần 1 | Setup engine   |
| Tuần 2 | Drag letters   |
| Tuần 3 | Puzzle system  |
| Tuần 4 | Level + UI     |
| Tuần 5 | Hint + shuffle |
| Tuần 6 | Polish         |

---

# Kết quả cuối

Game hoàn chỉnh có:

* menu
* 50 level
* nối chữ tạo từ
* bảng ô chữ
* hint
* shuffle
* âm thanh

Thời gian chơi:

```
30 – 60 phút
```
