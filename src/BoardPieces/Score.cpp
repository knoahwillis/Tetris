#include "Score.hpp"
#include <iostream>

Score::Score() {}

Score::~Score() {}

void Score::render(SDL_Renderer* rend, int xOffset, int yOffset) {

    int xOffsetTemp1 = xOffset;
    int xOffsetTemp2 = xOffset + 30;

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

    for (int i = 0; i < 5; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 4; x++) {
                if (text[i][4 * y + x] == 1) {
                    SDL_Rect r;
                    r.x = xOffsetTemp1 + x * 5;
                    r.y = yOffset + y * 5;
                    r.w = 5;
                    r.h = 5;

                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        xOffsetTemp1 += 30;
    }

    yOffset += 60;

    for (int i = 0; i < score.length(); i++) {
        std::array<int, 15> currNumber;
        switch (score[i]) {
        case '0':
            currNumber = numbers[0];
            break;
        case '1':
            currNumber = numbers[1];
            break;
        case '2':
            currNumber = numbers[2];
            break;
        case '3':
            currNumber = numbers[3];
            break;
        case '4':
            currNumber = numbers[4];
            break;
        case '5':
            currNumber = numbers[5];
            break;
        case '6':
            currNumber = numbers[6];
            break;
        case '7':
            currNumber = numbers[7];
            break;
        case '8':
            currNumber = numbers[8];
            break;
        case '9':
            currNumber = numbers[9];
            break;
        }
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 3; x++) {
                if (currNumber[3 * y + x] == 1) {
                    SDL_Rect r{x * 5 + xOffsetTemp2, yOffset + y * 5, 5, 5};
                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        xOffsetTemp2 += 30;
    }
}

void Score::updateScore(int update) {
    int scoreInt = std::stoi(score);
    scoreInt += update;
    score = std::to_string(scoreInt);
}

int Score::getScore() {
    return std::stoi(score);
}