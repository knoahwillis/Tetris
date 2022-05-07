#include "Tetris.hpp"
#include <iostream>

Tetris::Tetris(int h, int w) {
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

    int test = rand() % 6;
    switch (test) {
    case 0:
        pieces.push_back(new I);
        break;
    case 1:
        pieces.push_back(new O);
        break;
    case 2:
        pieces.push_back(new T);
        break;
    case 3:
        pieces.push_back(new Z);
        break;
    case 4:
        pieces.push_back(new S);
        break;
    case 5:
        pieces.push_back(new J);
        break;
    case 6:
        pieces.push_back(new L);
        break;
    }
}

Tetris::~Tetris() {
    delete game;
    delete title;
    delete score;
    delete next;
    delete hold;

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Tetris::endGame() { return !running; }

void Tetris::turn() {
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
            case SDL_SCANCODE_Q:
                pieces.back()->rotateLeft();
                break;
            case SDL_SCANCODE_E:
                pieces.back()->rotateRight();
                break;
            case SDL_SCANCODE_SPACE:
                pieces.back()->isDown = true;
                break;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        if (pieces.back()->bottom >= game->ground[i]) {
            pieces.back()->isDown = true;
            next->insertPiece(pieces);
        }
    }

    if (!pieces.back()->isDown) {
        pieces.back()->moveDown();
    }
}

void Tetris::render() {
    while (running) {
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);

        game->render(rend, width / 2 - 130, 115);
        title->render(rend, width / 2 - 170, 25);
        score->render(rend, width / 2 - 300, 100);
        next->render(rend, width - 200, 100);
        hold->render(rend, width / 2 - 290, 250);
        for (int i = 0; i < pieces.size(); i++) {
            pieces[i]->render(rend);
        }

        this->turn();

        SDL_RenderPresent(rend);
    }
}