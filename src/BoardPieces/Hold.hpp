#pragma once
#include "../Color.hpp"
#include "GamePieces.hpp"
#include "Next.hpp"
#include <SDL2/SDL.h>

class Hold {
    // clang-format off
    const int text[4][20] = {
        {1, 0, 0, 1,
         1, 0, 0, 1,
         1, 1, 1, 1,
         1, 0, 0, 1,
         1, 0, 0, 1},

        {1, 1, 1, 1,
         1, 0, 0, 1,
         1, 0, 0, 1,
         1, 0, 0, 1,
         1, 1, 1, 1},

        {1, 0, 0, 0,
         1, 0, 0, 0,
         1, 0, 0, 0,
         1, 0, 0, 0,
         1, 1, 1, 1},

        {1, 1, 1, 0,
         1, 0, 1, 1,
         1, 0, 0, 1,
         1, 0, 1, 1,
         1, 1, 1, 0}
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

    Color heldPiece = NONE;

    const SDL_Rect holdBorder = {100, 300, 150, 160};

public:
    Hold();
    ~Hold();

    void render(SDL_Renderer* rend, int xOffset, int yOffset);

    Piece* switchPiece(Piece* p, Next* next);
};