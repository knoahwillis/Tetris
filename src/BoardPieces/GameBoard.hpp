#pragma once
#include "../Color.hpp"
#include "GamePieces.hpp"
#include <SDL2/SDL.h>
#include <array>
#include <vector>

class GameBoard {

public:
    std::array<std::array<Color, 12>, 21> piecesInPlace;

    SDL_Rect border;

    GameBoard();
    ~GameBoard();

    void render(SDL_Renderer* rend);

    void putInPlace(Piece* piece);

    void printBoard();

    bool checkIfLine();

    bool checkIfLost();
};