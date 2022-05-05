#include "GameBoard.hpp"

GameBoard::GameBoard() { ground = {715, 715, 715, 715, 715, 715, 715, 715, 715, 715}; }

GameBoard::~GameBoard() {}

void GameBoard::render(SDL_Renderer* rend, int xOffset, int yOffset) {
    SDL_Rect border1 = {xOffset, yOffset, 300, 602};

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

    SDL_RenderDrawRect(rend, &border1);
}