#pragma once
#include "GamePieces.hpp"
#include <SDL2/SDL.h>
#include <vector>

class Next {
    // clang-format off
    const int text[4][20] = {
        {1, 0, 0, 1,
         1, 1, 0, 1,
         1, 1, 0, 1,
         1, 0, 1, 1,
         1, 0, 1, 1,},

        {1, 1, 1, 1, 
         1, 1, 0, 0,
         1, 1, 1, 1,
         1, 1, 0, 0,
         1, 1, 1, 1},

        {1, 0, 0, 1,
         0, 1, 1, 0,
         0, 1, 1, 0,
         0, 1, 1, 0,
         1, 0, 0, 1},

        {1, 1, 1, 1,
         1, 1, 1, 1,
         0, 1, 1, 0,
         0, 1, 1, 0,
         0, 1, 1, 0}
    };

    const int pieceI[8] = {
        0, 0, 0, 0,
        1, 1, 1, 1
    };

    const int pieceO[8] = {
        0, 1, 1, 0,
        0, 1, 1, 0
    };

    const int pieceS[8] = {
        0, 0, 1, 1,
        0, 1, 1, 0
    };

    const int pieceZ[8] = {
        1, 1, 0, 0,
        0, 1, 1, 0
    };

    const int pieceL[8] = {
        0, 0, 1, 0,
        1, 1, 1, 0
    };

    const int pieceJ[8] = {
        0, 1, 0, 0,
        0, 1, 1, 1
    };

    const int pieceT[8] = {
        0, 1, 0, 0,
        1, 1, 1, 0
    };
    // clang-format on
    std::vector<Piece*> nextPieces;

    SDL_Rect border = {595, 150, 130, 350};

public:
    Next();
    ~Next();

    void render(SDL_Renderer* rend, int xOffset, int yOffset);

    Piece* insertPiece();
};