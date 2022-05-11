#pragma once
#include "../Color.hpp"
#include "GamePieces.hpp"
#include <SDL2/SDL.h>
#include <array>
#include <vector>

class GameBoard {
    SDL_Rect temp = {0, 0, 0, 0};

public:
    std::array<std::array<Color, 12>, 20> piecesInPlace;

    SDL_Rect border;

    GameBoard();
    ~GameBoard();

    void render(SDL_Renderer* rend);

    void putInPlace(Piece* piece);

    void printBoard();

    void checkIfLine();

    bool checkIfLost();
};