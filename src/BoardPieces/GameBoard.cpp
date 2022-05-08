#include "GameBoard.hpp"

GameBoard::GameBoard(int xOffset, int yOffset) {
    ground = {715, 715, 715, 715, 715, 715, 715, 715, 715, 715};
    border = {xOffset, yOffset, 300, 600};
}

GameBoard::~GameBoard() {}

void GameBoard::render(SDL_Renderer* rend) {

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

    SDL_RenderDrawRect(rend, &border);
}