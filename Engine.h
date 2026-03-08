#pragma once

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <vector>
#include <string>

#include "Letter.h"
#include "Level.h"
#include "words.h"

class Engine
{

public:

    bool init();
    void run();

private:

    SDL_Window* window;
    SDL_Renderer* renderer;

    TTF_Font* font;

    bool running;

    int currentLevel;

    std::vector<Letter> letters;

    void loadLevel();

    void handleEvents();
    void update();
    void render();

    void drawCircle(int x, int y, int r);
    void drawBoard();

};