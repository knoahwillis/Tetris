#pragma once
#include <SDL2/SDL.h>

class Score {
    // clang-format off
const int text[5][20] = {
        {1, 1, 1, 1,
         1, 0, 0, 0,
         1, 1, 1, 1,
         0, 0, 0, 1,
         1, 1, 1, 1},

        {1, 1, 1, 1,
         1, 0, 0, 0,
         1, 0, 0, 0,
         1, 0, 0, 0,
         1, 1, 1, 1},

        {1, 1, 1, 1,
         1, 0, 0, 1,
         1, 0, 0, 1,
         1, 0, 0, 1,
         1, 1, 1, 1},

        {1, 1, 1, 1,
         1, 0, 0, 1,
         1, 1, 1, 1,
         1, 1, 1, 0,
         1, 1, 0, 1},

        {1, 1, 1, 1, 
         1, 1, 0, 0,
         1, 1, 1, 1,
         1, 1, 0, 0,
         1, 1, 1, 1}
    };
    // clang-format on

    int score;

public:
    Score();
    ~Score();

    void render(SDL_Renderer* rend, int xOffset, int yOffset);

    int getScore();
    bool updateScore(int update);
};