#pragma once
#include <SDL2/SDL.h>
#include <array>

class GameBoard {
public:
    std::array<int, 10> ground;

    GameBoard();
    ~GameBoard();

    void render(SDL_Renderer* rend, int xOffset, int yOffset);
};