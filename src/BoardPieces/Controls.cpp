#include "Controls.hpp"


Controls::Controls() {}

Controls::~Controls() {}

void Controls::render(SDL_Renderer* rend, int xOffset, int yOffset) {

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

    int xOffsetTemp = xOffset;
    for (int i = 0; i < 9; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 4; x++) {
                if (title[i][4 * y + x] == 1) {
                    SDL_Rect r{xOffsetTemp + x * 3, yOffset + y * 3, 3, 3};
                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        xOffsetTemp += 20;
    }

    xOffsetTemp = xOffset;
    yOffset += 60;

    for (int i = 0; i < 6; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 4; x++) {
                if (left[i][4 * y + x] == 1) {
                    SDL_Rect r{xOffsetTemp + x * 3, yOffset + y * 3, 3, 3};
                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        xOffsetTemp += 20;
    }

    xOffsetTemp = xOffset;
    yOffset += 30;

    for (int i = 0; i < 7; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 4; x++) {
                if (right[i][4 * y + x] == 1) {
                    SDL_Rect r{xOffsetTemp + x * 3, yOffset + y * 3, 3, 3};
                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        xOffsetTemp += 20;
    }

    xOffsetTemp = xOffset;
    yOffset += 30;

    for (int i = 0; i < 10; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 4; x++) {
                if (rotLeft[i][4 * y + x] == 1) {
                    SDL_Rect r{xOffsetTemp + x * 3, yOffset + y * 3, 3, 3};
                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        xOffsetTemp += 20;
    }

    xOffsetTemp = xOffset;
    yOffset += 30;

    for (int i = 0; i < 10; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 4; x++) {
                if (rotRight[i][4 * y + x] == 1) {
                    SDL_Rect r{xOffsetTemp + x * 3, yOffset + y * 3, 3, 3};
                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        xOffsetTemp += 20;
    }

    xOffsetTemp = xOffset;
    yOffset += 30;

    for (int i = 0; i < 8; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 4; x++) {
                if (tab[i][4 * y + x] == 1) {
                    SDL_Rect r{xOffsetTemp + x * 3, yOffset + y * 3, 3, 3};
                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        xOffsetTemp += 20;
    }

    xOffsetTemp = xOffset;
    yOffset += 30;

    for (int i = 0; i < 22; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 4; x++) {
                if (fastFall[i][4 * y + x] == 1) {
                    SDL_Rect r{xOffsetTemp + x * 3, yOffset + y * 3, 3, 3};
                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        xOffsetTemp += 20;
    }
}
