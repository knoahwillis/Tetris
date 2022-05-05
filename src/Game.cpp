#include "Game.hpp"

Game::Game(int h, int w) {
    height = h;
    width = w;

    running = true;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    title = new Title;
    score = new Score;
}

Game::~Game() {
    delete title;
    delete score;

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Game::endGame(){
    return running;
}

void Game::turn() {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT:
            running = false;
            break;
        }
    }
}

void Game::render() {
    while (running) {
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);

        title->render(rend, width / 2 - 170, 25);
        score->render(rend, width / 2 - 300, 100);

        this->turn();

        SDL_RenderPresent(rend);
    }
}