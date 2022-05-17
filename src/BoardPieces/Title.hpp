#pragma once
#include <SDL2/SDL.h>

class Title {
    // clang-format off
    const int text[6][20] = {
        {1, 1, 1, 1, 
         1, 1, 1, 1, 
         0, 1, 1, 0,
         0, 1, 1, 0,
         0, 1, 1, 0},

        {1, 1, 1, 1, 
         1, 1, 0, 0,
         1, 1, 1, 1,
         1, 1, 0, 0,
         1, 1, 1, 1}, 
         
        {1, 1, 1, 1,
         1, 1, 1, 1,
         0, 1, 1, 0,
         0, 1, 1, 0,
         0, 1, 1, 0}, 

        {1, 1, 1, 1,
         1, 0, 0, 1,
         1, 1, 1, 1,
         1, 1, 1, 0,
         1, 1, 0, 1}, 
         
        {0, 1, 1, 0,
         0, 1, 1, 0,
         0, 1, 1, 0,
         0, 1, 1, 0,
         0, 1, 1, 0}, 
         
        {1, 1, 1, 1,
         1, 0, 0, 0,
         1, 1, 1, 1,
         0, 0, 0, 1,
         1, 1, 1, 1}
         };
    // clang-format on
    
public:
    Title();
    ~Title();

    void render(SDL_Renderer *rend, int xOffset, int yOffset);
};