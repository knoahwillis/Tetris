#include "Title.hpp"

Title::Title() {}

Title::~Title() {}

void Title::render(SDL_Renderer* rend, int xOffset, int yOffset) {

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

    for (int i = 0; i < 6; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 4; x++) {
                if (text[i][4 * y + x] == 1) {
                    SDL_Rect r;
                    r.x = xOffset + x * 10;
                    r.y = yOffset + y * 10;
                    r.w = 10;
                    r.h = 10;

                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        xOffset += 60;
    }
}