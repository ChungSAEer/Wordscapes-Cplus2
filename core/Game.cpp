#include "Game.h"
#include <iostream>

// ============================================================
// Constructor / Destructor
// ============================================================

Game::Game() {}

Game::~Game() {
    clean();
}

// ============================================================
// init() – Khởi tạo SDL, tạo cửa sổ, renderer, font
// ============================================================

bool Game::init(const std::string& title, int width, int height) {
    m_windowWidth  = width;
    m_windowHeight = height;

    // --- Khởi tạo SDL ---
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        std::cerr << "[ERROR] SDL_Init failed: " << SDL_GetError() << "\n";
        return false;
    }

    // --- Khởi tạo SDL_ttf ---
    if (!TTF_Init()) {
        std::cerr << "[ERROR] TTF_Init failed: " << SDL_GetError() << "\n";
        return false;
    }

    // --- Tạo cửa sổ ---
    m_window = SDL_CreateWindow(title.c_str(), width, height, 0);
    if (!m_window) {
        std::cerr << "[ERROR] SDL_CreateWindow failed: " << SDL_GetError() << "\n";
        return false;
    }

    // --- Tạo renderer (dùng GPU acceleration nếu có) ---
    m_renderer = SDL_CreateRenderer(m_window, nullptr);
    if (!m_renderer) {
        std::cerr << "[ERROR] SDL_CreateRenderer failed: " << SDL_GetError() << "\n";
        return false;
    }

    // --- Load font ---
    // Dùng font mặc định của Windows, bạn có thể thay bằng font .ttf của riêng bạn
    // Đặt file .ttf vào thư mục assets/fonts/ và đổi đường dẫn bên dưới
    m_font = TTF_OpenFont("assets/fonts/font.ttf", 28);
    if (!m_font) {
        // Nếu chưa có font riêng, dùng font hệ thống Windows làm fallback
        m_font = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 28);
        if (!m_font) {
            std::cerr << "[WARNING] Không load được font. Text sẽ không hiển thị.\n";
            // Vẫn cho chạy tiếp, chỉ không có text
        }
    }

    m_running = true;
    m_state   = GameState::MENU;

    std::cout << "[OK] Game initialized successfully!\n";
    return true;
}

// ============================================================
// run() – Game loop chính
// ============================================================

void Game::run() {
    while (m_running) {
        handleEvents();
        update();
        render();
    }
}

// ============================================================
// handleEvents() – Xử lý input
// ============================================================

void Game::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {

        case SDL_EVENT_QUIT:
            m_running = false;
            break;

        case SDL_EVENT_KEY_DOWN:
            // Nhấn ESC để thoát
            if (event.key.key == SDLK_ESCAPE) {
                m_running = false;
            }
            // Nhấn SPACE ở MENU để vào game (test)
            if (event.key.key == SDLK_SPACE && m_state == GameState::MENU) {
                m_state = GameState::PLAYING;
                std::cout << "[INPUT] Chuyển sang PLAYING\n";
            }
            break;

        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            std::cout << "[INPUT] Mouse down tại ("
                      << event.button.x << ", " << event.button.y << ")\n";
            break;

        case SDL_EVENT_MOUSE_BUTTON_UP:
            std::cout << "[INPUT] Mouse up tại ("
                      << event.button.x << ", " << event.button.y << ")\n";
            break;

        case SDL_EVENT_MOUSE_MOTION:
            // Uncomment dòng dưới nếu muốn log mọi chuyển động chuột
            // std::cout << "[INPUT] Mouse move: (" << event.motion.x << ", " << event.motion.y << ")\n";
            break;

        default:
            break;
        }
    }
}

// ============================================================
// update() – Cập nhật logic game
// ============================================================

void Game::update() {
    // Phase 1: chưa có logic gameplay, để trống
    // Phase 2 trở đi sẽ cập nhật LetterWheel, WordBuilder, v.v.
}

// ============================================================
// render() – Vẽ lên màn hình
// ============================================================

void Game::render() {
    // Xóa màn hình
    SDL_SetRenderDrawColor(m_renderer, 30, 30, 50, 255); // màu nền tối
    SDL_RenderClear(m_renderer);

    // Vẽ tùy theo trạng thái game
    switch (m_state) {

    case GameState::MENU:
        renderMenu();
        break;

    case GameState::PLAYING:
        renderPlaying();
        break;

    case GameState::LEVEL_COMPLETE:
        renderText("Level Complete!", m_windowWidth / 2, m_windowHeight / 2, {255, 215, 0, 255});
        break;

    default:
        break;
    }

    // Hiển thị frame lên màn hình
    SDL_RenderPresent(m_renderer);
}

// ============================================================
// renderMenu() – Vẽ màn hình menu
// ============================================================

void Game::renderMenu() {
    renderText("WORDSCAPES",
               m_windowWidth / 2, 180,
               {100, 200, 255, 255}); // tiêu đề màu xanh

    renderText("Nhan SPACE de bat dau",
               m_windowWidth / 2, 300,
               {200, 200, 200, 255}); // hướng dẫn màu xám

    renderText("Nhan ESC de thoat",
               m_windowWidth / 2, 350,
               {150, 150, 150, 255});
}

// ============================================================
// renderPlaying() – Vẽ màn hình gameplay (placeholder)
// ============================================================

void Game::renderPlaying() {
    renderText("Dang choi...",
               m_windowWidth / 2, m_windowHeight / 2,
               {255, 255, 255, 255});

    renderText("(Phase 2 se co Letter Wheel)",
               m_windowWidth / 2, m_windowHeight / 2 + 60,
               {150, 150, 150, 255});
}

// ============================================================
// renderText() – Helper: vẽ text căn giữa tại (x, y)
// ============================================================

void Game::renderText(const std::string& text, int x, int y, SDL_Color color) {
    if (!m_font) return;

    SDL_Surface* surface = TTF_RenderText_Blended(m_font, text.c_str(), 0, color);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    SDL_DestroySurface(surface);
    if (!texture) return;

    float w = 0, h = 0;
    SDL_GetTextureSize(texture, &w, &h);

    // Căn giữa theo x
    SDL_FRect dst = {
        (float)(x - w / 2),
        (float)(y - h / 2),
        w, h
    };

    SDL_RenderTexture(m_renderer, texture, nullptr, &dst);
    SDL_DestroyTexture(texture);
}

// ============================================================
// clean() – Dọn dẹp tài nguyên
// ============================================================

void Game::clean() {
    if (m_font)     { TTF_CloseFont(m_font);          m_font     = nullptr; }
    if (m_renderer) { SDL_DestroyRenderer(m_renderer); m_renderer = nullptr; }
    if (m_window)   { SDL_DestroyWindow(m_window);     m_window   = nullptr; }
    TTF_Quit();
    SDL_Quit();
    std::cout << "[OK] Game cleaned up.\n";
}