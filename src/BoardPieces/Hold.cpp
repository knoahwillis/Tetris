#include "Hold.hpp"

Hold::Hold() {}

Hold::~Hold() {}

void Hold::render(SDL_Renderer* rend, int xOffset, int yOffset) {

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

    for (int i = 0; i < 4; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 4; x++) {
                if (text[i][4 * y + x] == 1) {
                    SDL_Rect r;
                    r.x = xOffset + x * 5;
                    r.y = yOffset + y * 5;
                    r.w = 5;
                    r.h = 5;

                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        xOffset += 30;
    }
}