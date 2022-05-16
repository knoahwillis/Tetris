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

    yOffset += 90;

    switch (heldPiece) {
    case NONE:
        break;
    case CYAN:
        SDL_SetRenderDrawColor(rend, 0, 255, 255, 255);
        for (int y = 0; y < 2; y++) {
            for (int x = 0; x < 4; x++) {
                if (pieceI[4 * y + x] == 1) {
                    SDL_Rect r{x * 30 + 120, yOffset + y * 30, 30, 30};
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
                    SDL_Rect r{x * 30 + 120, yOffset + y * 30, 30, 30};
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
                    SDL_Rect r{x * 30 + 120, yOffset + y * 30, 30, 30};
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
                    SDL_Rect r{x * 30 + 120, yOffset + y * 30, 30, 30};
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
                    SDL_Rect r{x * 30 + 120, yOffset + y * 30, 30, 30};
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
                    SDL_Rect r{x * 30 + 120, yOffset + y * 30, 30, 30};
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
                    SDL_Rect r{x * 30 + 120, yOffset + y * 30, 30, 30};
                    SDL_RenderFillRect(rend, &r);
                }
            }
        }
        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        break;
    }
}

Piece* Hold::switchPiece(Piece* p, Next* next) {
    switch (heldPiece) {
    case NONE:
        heldPiece = p->color;
        return next->insertPiece();
    case CYAN:
        heldPiece = p->color;
        return new I;
    case YELLOW:
        heldPiece = p->color;
        return new O;
    case PURPLE:
        heldPiece = p->color;
        return new T;
    case GREEN:
        heldPiece = p->color;
        return new S;
    case RED:
        heldPiece = p->color;
        return new Z;
    case BLUE:
        heldPiece = p->color;
        return new J;
    case ORANGE:
        heldPiece = p->color;
        return new L;
    }
}