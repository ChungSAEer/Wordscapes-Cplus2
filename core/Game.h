#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>
#include <string>

// Các trạng thái của game
enum class GameState {
    MENU,
    PLAYING,
    LEVEL_COMPLETE,
    EXIT
};

class Game {
public:
    Game();
    ~Game();

    // Khởi tạo SDL, tạo cửa sổ và renderer
    bool init(const std::string& title, int width, int height);

    // Game loop chính
    void run();

    // Dọn dẹp tài nguyên
    void clean();

    bool isRunning() const { return m_running; }

private:
    // --- Game Loop ---
    void handleEvents();
    void update();
    void render();

    // --- Render helpers ---
    void renderMenu();
    void renderPlaying();
    void renderText(const std::string& text, int x, int y, SDL_Color color);

    SDL_Window*   m_window   = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    TTF_Font*     m_font     = nullptr;

    bool      m_running = false;
    GameState m_state   = GameState::MENU;

    int m_windowWidth  = 0;
    int m_windowHeight = 0;
};