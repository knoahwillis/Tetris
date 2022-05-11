#include "GameBoard.hpp"
#include <iostream>

GameBoard::GameBoard() {
    border = {270, 115, 300, 600};
    for (int i = 0; i < piecesInPlace.size(); i++) {
        for (int j = 0; j < piecesInPlace[i].size(); j++) {
            if (j == 0 || j == 11) {
                piecesInPlace[i][j] = BORDER;
            } else {
                piecesInPlace[i][j] = NONE;
            }
        }
    }
}

GameBoard::~GameBoard() {}

void GameBoard::render(SDL_Renderer* rend) {

    for (int i = 0; i < piecesInPlace.size(); i++) {
        for (int j = 0; j < piecesInPlace[i].size(); j++) {
            switch (piecesInPlace[i][j]) {
            case CYAN:
                SDL_SetRenderDrawColor(rend, 0, 255, 255, 255);
                break;
            case YELLOW:
                SDL_SetRenderDrawColor(rend, 255, 255, 0, 255);
                break;
            case PURPLE:
                SDL_SetRenderDrawColor(rend, 255, 0, 255, 255);
                break;
            case GREEN:
                SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);
                break;
            case RED:
                SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
                break;
            case BLUE:
                SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
                break;
            case ORANGE:
                SDL_SetRenderDrawColor(rend, 255, 165, 0, 255);
                break;
            case WHITE:
                SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
                break;
            case NONE:
                SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
                break;
            }
            SDL_Rect temp = {j * 30 + 270, i * 30 + 115, 30, 30};
            SDL_RenderFillRect(rend, &temp);
            SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        }
    }

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

    SDL_RenderDrawRect(rend, &border);
}

void GameBoard::putInPlace(Piece* piece) {
    for (int i = 0; i < 4; i++) {
        piecesInPlace[((piece->current()[i].y) / 30) - (115 / 30)][(piece->current()[i].x / 30) - (270 / 30)] = piece->color;
    }
}

void GameBoard::checkIfLine() {
    for (int i = 19; i >= 0; i--) {
        if (piecesInPlace[i][1] != NONE && piecesInPlace[i][2] != NONE && piecesInPlace[i][3] != NONE && piecesInPlace[i][4] != NONE &&
            piecesInPlace[i][5] != NONE && piecesInPlace[i][6] != NONE && piecesInPlace[i][7] != NONE && piecesInPlace[i][8] != NONE &&
            piecesInPlace[i][9] != NONE && piecesInPlace[i][10] != NONE) {
            for (int j = i; j > 0; j--) {
                piecesInPlace[j] = piecesInPlace[j - 1];
            }
            return;
        }
    }
}

void GameBoard::printBoard() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << piecesInPlace[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool GameBoard::checkIfLost() {
    for (int i = 1; i < 10; i++) {
        if (piecesInPlace[0][i] != NONE && piecesInPlace[0][i] != BORDER) {
            return true;
        }
    }
    return false;
}