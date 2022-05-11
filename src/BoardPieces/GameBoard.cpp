#include "GameBoard.hpp"
#include <iostream>

GameBoard::GameBoard(int xOffset, int yOffset) {
    border = {270, 115, 300, 600};
    for (int i = 0; i < piecesInPlace.size(); i++) {
        for (int j = 0; j < piecesInPlace[i].size(); j++) {
            piecesInPlace[i][j] = NONE;
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
    border = {270, 115, 300, 600};
    SDL_RenderDrawRect(rend, &border);
}

void GameBoard::putInPlace(Piece* piece) {
    for (int i = 0; i < 4; i++) {
        piecesInPlace[((piece->current()[i].y) / 30) - (115 / 30)][(piece->current()[i].x / 30) - (270 / 30)] = piece->color;
    }
}

void GameBoard::printBoard() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 10; j++) {
            std::cout << piecesInPlace[i][j] << " ";
        }
        std::cout << "\n";
    }
}