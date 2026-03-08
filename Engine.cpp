#include "Engine.h"
#include <cmath>
#include <iostream>

#define PI 3.14159265358979323846
bool Engine::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    window = SDL_CreateWindow("Word Game", 800, 700, 0);
    renderer = SDL_CreateRenderer(window, nullptr);

    font = TTF_OpenFont("arial.ttf", 40);

    currentLevel = 0;

    loadLevel();

    running = true;

    return true;
}

void Engine::loadLevel()
{
    letters.clear();

    std::string base = LEVELS[currentLevel].words[0];

    float cx = 400;
    float cy = 550;
    float R = 120;

    for (int i = 0; i < base.size(); i++)
    {
        Letter l;

        float angle = i * 2 * PI / base.size();

        l.x = cx + cos(angle) * R;
        l.y = cy + sin(angle) * R;

        l.ch = base[i];

        l.radius = 40;

        l.dragging = false;
        l.used = false;

        letters.push_back(l);
    }
}

void Engine::drawCircle(int cx, int cy, int r)
{
    for (int w = -r; w < r; w++)
    {
        for (int h = -r; h < r; h++)
        {
            if (w * w + h * h <= r * r)
                SDL_RenderPoint(renderer, cx + w, cy + h);
        }
    }
}

void Engine::drawBoard()
{
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

    for (int i = 0; i < 8; i++)
    {
        SDL_FRect rect;

        rect.x = 200 + i * 50;
        rect.y = 200;
        rect.w = 48;
        rect.h = 48;

        SDL_RenderRect(renderer, &rect);
    }
}

void Engine::render()
{
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);

    drawBoard();

    for (auto& l : letters)
    {

        SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);

        drawCircle(l.x, l.y, l.radius);

        char text[2] = { l.ch, 0 };

        SDL_Color col = { 0,0,0,255 };

        SDL_Surface* surf = TTF_RenderText_Blended(font, text, 0, col);

        SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);

        SDL_FRect rect;

        rect.x = l.x - surf->w / 2.0f;
        rect.y = l.y - surf->h / 2.0f;
        rect.w = (float)surf->w;
        rect.h = (float)surf->h;

        SDL_RenderTexture(renderer, tex, NULL, &rect);

        SDL_DestroyTexture(tex);
        SDL_DestroySurface(surf);

    }

    SDL_RenderPresent(renderer);
}

void Engine::handleEvents()
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {

        if (e.type == SDL_EVENT_QUIT)
            running = false;

    }
}

void Engine::update()
{
}

void Engine::run()
{
    while (running)
    {

        handleEvents();

        update();

        render();

        SDL_Delay(16);

    }
}