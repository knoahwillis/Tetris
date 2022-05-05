#pragma once
// #include "./Color.hpp"
#include <SDL2/SDL.h>
// #include <array>

class GameBoard {
public:
    GameBoard();
    ~GameBoard();

    void render(SDL_Renderer* rend, int xOffset, int yOffset);
};