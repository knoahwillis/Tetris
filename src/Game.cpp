#include "Game.hpp"

Game::Game(int h, int w) {
    height = h;
    width = w;

    running = true;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    game = new GameBoard;
    title = new Title;
    score = new Score;
    next = new Next;
    hold = new Hold;

    pieces.push_back(new I);
}

Game::~Game() {
    delete game;
    delete title;
    delete score;
    delete next;
    delete hold;

    for (int i = 0; i < pieces.size(); i++) {
        delete pieces[i];
    }

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Game::endGame() { return running; }

void Game::turn() {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            switch (e.key.keysym.scancode) {
            case SDL_SCANCODE_A:
                pieces.back()->moveLeft();
                break;
            case SDL_SCANCODE_D:
                pieces.back()->moveRight();
                break;
            }
        }
    }

    for(int i = 0; i < pieces.size(); i++){
        if(!pieces[i]->isDown){
            pieces[i]->moveDown();
        }
    }
}

void Game::render() {
    while (running) {
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);

        game->render(rend, width / 2 - 130, 115);
        title->render(rend, width / 2 - 170, 25);
        score->render(rend, width / 2 - 300, 100);
        next->render(rend, width - 200, 100);
        hold->render(rend, width / 2 - 290, 250);
        for(int i = 0; i < pieces.size(); i++){
            pieces[i]->render(rend);
        }

        this->turn();

        SDL_RenderPresent(rend);
    }
}