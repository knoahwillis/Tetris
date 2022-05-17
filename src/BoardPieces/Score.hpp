#pragma once
#include <SDL2/SDL.h>
#include <array>
#include <string>

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

const std::array<std::array<int, 15>, 10> numbers {{
        {1, 1, 1,
         1, 0, 1,
         1, 0, 1,
         1, 0, 1,
         1, 1, 1},

        {0, 1, 0,
         0, 1, 0,
         0, 1, 0,
         0, 1, 0,
         0, 1, 0},

        {1, 1, 1,
         0, 0, 1,
         0, 1, 1,
         1, 0, 0,
         1, 1, 1},

        {1, 1, 1,
         0, 0, 1,
         1, 1, 1,
         0, 0, 1,
         1, 1, 1},

        {1, 0, 1,
         1, 0, 1,
         1, 1, 1,
         0, 0, 1,
         0, 0, 1},

        {1, 1, 1,
         1, 0, 0,
         1, 1, 1,
         0, 0, 1,
         1, 1, 1},

        {1, 1, 1,
         1, 0, 0,
         1, 1, 1,
         1, 0, 1,
         1, 1, 1},

        {1, 1, 1,
         0, 0, 1,
         0, 0, 1,
         0, 0, 1,
         0, 0, 1},

        {1, 1, 1,
         1, 0, 1,
         1, 1, 1,
         1, 0, 1,
         1, 1, 1},

        {1, 1, 1,
         1, 0, 1,
         1, 1, 1,
         0, 0, 1,
         0, 0, 1}
    }};
    // clang-format on

    std::string score = "000";

public:
    Score();
    ~Score();

    void render(SDL_Renderer* rend, int xOffset, int yOffset);

    int getScore();
    int gameSpeed = 1;
    void updateScore(int update);

    void printScore();
};