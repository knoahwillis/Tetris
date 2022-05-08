#pragma once
#include "GamePieces.hpp"
#include <SDL2/SDL.h>
#include <array>
#include <vector>

class GameBoard {
public:
    std::array<int, 10> ground;

    SDL_Rect border;

    GameBoard(int xOffset, int yOffset);
    ~GameBoard();

    void render(SDL_Renderer* rend);
};