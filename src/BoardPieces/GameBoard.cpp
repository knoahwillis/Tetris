#include "GameBoard.hpp"

GameBoard::GameBoard() {}

GameBoard::~GameBoard() {}

void GameBoard::render(SDL_Renderer* rend, int xOffset, int yOffset) {
    SDL_Rect border1 = {xOffset, yOffset, 300, 660};

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

    SDL_RenderDrawRect(rend, &border1);
}