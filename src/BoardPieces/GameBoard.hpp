#pragma once
#include "../Color.hpp"
#include "GamePieces.hpp"
#include <SDL2/SDL.h>
#include <array>
#include <vector>

class GameBoard {

public:
    std::array<std::array<Color, 12>, 21> piecesInPlace;

    const SDL_Rect border{270, 115, 300, 600};


    GameBoard();
    ~GameBoard();

    void render(SDL_Renderer* rend);

    void putInPlace(Piece* piece);

    bool checkIfLine();

    bool checkIfLost();
};