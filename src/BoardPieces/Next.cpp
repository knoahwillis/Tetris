#include "Next.hpp"
#include <ctime>
#include <iostream>
#include <random>

Next::Next() {
    for (int i = 0; i < 3; i++) {
        int pieceType = rand() % 7;

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
    SDL_RenderDrawRect(rend, &nextBorder);

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


    yOffset += 60;
    for (int i = 0; i < 3; i++) {
        switch (nextPieces[i]->color) {
        case CYAN:
            SDL_SetRenderDrawColor(rend, 0, 255, 255, 255);
            for (int y = 0; y < 2; y++) {
                for (int x = 0; x < 4; x++) {
                    if (pieceI[4 * y + x] == 1) {
                        SDL_Rect r{xOffset - 120 + x * 30, yOffset + y * 30, 30, 30};
                        SDL_RenderFillRect(rend, &r);
                    }
                }
            }
            SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
            break;
        case YELLOW:
            SDL_SetRenderDrawColor(rend, 255, 255, 0, 255);
            for (int y = 0; y < 2; y++) {
                for (int x = 0; x < 4; x++) {
                    if (pieceO[4 * y + x] == 1) {
                        SDL_Rect r{xOffset - 120 + x * 30, yOffset + y * 30, 30, 30};
                        SDL_RenderFillRect(rend, &r);
                    }
                }
            }
            SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
            break;
        case PURPLE:
            SDL_SetRenderDrawColor(rend, 255, 0, 255, 255);
            for (int y = 0; y < 2; y++) {
                for (int x = 0; x < 4; x++) {
                    if (pieceT[4 * y + x] == 1) {
                        SDL_Rect r{xOffset - 120 + x * 30, yOffset + y * 30, 30, 30};
                        SDL_RenderFillRect(rend, &r);
                    }
                }
            }
            SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
            break;
        case GREEN:
            SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);
            for (int y = 0; y < 2; y++) {
                for (int x = 0; x < 4; x++) {
                    if (pieceS[4 * y + x] == 1) {
                        SDL_Rect r{xOffset - 120 + x * 30, yOffset + y * 30, 30, 30};
                        SDL_RenderFillRect(rend, &r);
                    }
                }
            }
            SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
            break;
        case RED:
            SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
            for (int y = 0; y < 2; y++) {
                for (int x = 0; x < 4; x++) {
                    if (pieceZ[4 * y + x] == 1) {
                        SDL_Rect r{xOffset - 120 + x * 30, yOffset + y * 30, 30, 30};
                        SDL_RenderFillRect(rend, &r);
                    }
                }
            }
            SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
            break;
        case BLUE:
            SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
            for (int y = 0; y < 2; y++) {
                for (int x = 0; x < 4; x++) {
                    if (pieceJ[4 * y + x] == 1) {
                        SDL_Rect r{xOffset - 120 + x * 30, yOffset + y * 30, 30, 30};
                        SDL_RenderFillRect(rend, &r);
                    }
                }
            }
            SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
            break;
        case ORANGE:
            SDL_SetRenderDrawColor(rend, 255, 165, 0, 255);
            for (int y = 0; y < 2; y++) {
                for (int x = 0; x < 4; x++) {
                    if (pieceL[4 * y + x] == 1) {
                        SDL_Rect r{xOffset - 120 + x * 30, yOffset + y * 30, 30, 30};
                        SDL_RenderFillRect(rend, &r);
                    }
                }
            }
            SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
            break;
        }
        yOffset += 120;
    }
}

Piece* Next::insertPiece() {
    int pieceType = rand() % 7;

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
    Piece* ret = nextPieces[0];
    nextPieces.erase(nextPieces.begin());
    return ret;
}
