#include "Game.hpp"

Game::Game(int h, int w) {
    height = h;
    width = w;

    running = true;

    running = true;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    title = new Title; 
}

Game::~Game() {
    delete title;

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::render() {
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderClear(rend);

    title->render(rend, width / 2.0 - 85, 25);

    SDL_RenderPresent(rend);
}