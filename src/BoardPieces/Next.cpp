#include "Next.hpp"
#include <ctime>
#include <iostream>
#include <random>

Next::Next() {}

Next::~Next() {
    for (int i = 0; i < nextPieces.size(); i++) {
        delete nextPieces[i];
    }
}

void Next::render(SDL_Renderer* rend, int xOffset, int yOffset) {

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

    for (int i = 0; i < 4; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 4; x++) {
                if (text[i][4 * y + x] == 1) {
                    SDL_Rect r{xOffset + x * 5, yOffset + y * 5, 5, 5};
                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        xOffset += 30;
    }
}

Piece* Next::insertPiece() {
    int pieceType = rand() % 7;

    switch (pieceType) {
    case 0:
        return new I;
        break;
    case 1:
        return new O;
        break;
    case 2:
        return new T;
        break;
    case 3:
        return new S;
        break;
    case 4:
        return new Z;
        break;
    case 5:
        return new J;
        break;
    case 6:
        return new L;
        break;
    }
}
