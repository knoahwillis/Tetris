#pragma once
#include <vector>
#include <SDL2/SDL.h>

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
    // clang-format on
    //std::vector<Pieces> pieces
public:
    Next();
    ~Next();

    void render(SDL_Renderer *rend, int xOffset, int yOffset);

    //void insertPiece();
};