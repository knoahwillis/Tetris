#pragma once
#include "GamePieces.hpp"
#include <SDL2/SDL.h>
#include <array>
#include <vector>
#include "../Color.hpp"

class GameBoard {
    SDL_Rect temp = {0, 0, 0, 0};
public:
    std::array<std::array<Color, 10>, 20> piecesInPlace;

    SDL_Rect border;

    GameBoard(int xOffset, int yOffset);
    ~GameBoard();

    void render(SDL_Renderer* rend);

    void putInPlace(Piece* piece);

    void printBoard();

    void checkIfLine();
};