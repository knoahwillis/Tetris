#pragma once
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
    // clang-format on

    //Piece piece;
public:
    Hold();
    ~Hold();

    void render(SDL_Renderer *rend, int xOffset, int yOffset);

    // void switchPiece(Piece p);
};