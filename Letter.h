#pragma once
#include <SDL3/SDL.h>

struct Letter
{
    char ch;

    float x;
    float y;

    int radius;

    bool dragging;
    bool used;
};