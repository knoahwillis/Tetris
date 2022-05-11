#include "Next.hpp"
#include <ctime>
#include <iostream>
#include <random>

Next::Next() {
    for (int i = 0; i < 7; i++) {
        int pieceType = rand() % 6;
        
        switch (pieceType) {
        case 0:
            nextPieces.push_back(new I);
            break;
        case 1:
            nextPieces.push_back(new O);
            break;
        case 2:
            nextPieces.push_back(new T);
            break;
        case 3:
            nextPieces.push_back(new S);
            break;
        case 4:
            nextPieces.push_back(new Z);
            break;
        case 5:
            nextPieces.push_back(new J);
            break;
        case 6:
            nextPieces.push_back(new L);
            break;
        }
    }
}

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
    srand(time(0));

    int pieceType = rand() % 6;

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
