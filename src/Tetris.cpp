#include "Tetris.hpp"
#include <iostream>

Tetris::Tetris(int h, int w) {
    height = h;
    width = w;

    running = true;
    fallFast = false;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    game = new GameBoard;
    title = new Title;
    score = new Score;
    next = new Next;
    hold = new Hold;

    switch (rand() % 7) {
    case 0:
        currentPiece = new I;
        break;
    case 1:
        currentPiece = new O;
        break;
    case 2:
        currentPiece = new T;
        break;
    case 3:
        currentPiece = new Z;
        break;
    case 4:
        currentPiece = new S;
        break;
    case 5:
        currentPiece = new J;
        break;
    case 6:
        currentPiece = new L;
        break;
    }
}

Tetris::~Tetris() {
    delete game;
    delete title;
    delete score;
    delete next;
    delete hold;

    delete currentPiece;


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
                if (!currentPiece->movedLeft().collision(game->piecesInPlace)) {
                    currentPiece->moveLeft();
                }
                break;
            case SDL_SCANCODE_D:
                if (!currentPiece->movedRight().collision(game->piecesInPlace)) {
                    currentPiece->moveRight();
                }
                break;
            case SDL_SCANCODE_Q:
                if (!currentPiece->rotatedLeft().collision(game->piecesInPlace)) {
                    currentPiece->rotateLeft();
                }
                break;
            case SDL_SCANCODE_E:
                if (!currentPiece->rotatedRight().collision(game->piecesInPlace)) {
                    currentPiece->rotateRight();
                }
                break;
            case SDL_SCANCODE_SPACE:
                fallFast = !fallFast;
                break;
            case SDL_SCANCODE_TAB:
                currentPiece = hold->switchPiece(currentPiece, next);
                break;
            case SDL_SCANCODE_ESCAPE:
                running = false;
                break;
            }
        }
    }

    if (currentPiece->collision(game->piecesInPlace)) {
        game->putInPlace(currentPiece);
        currentPiece = next->insertPiece();
    } else if (!fallFast) {
        currentPiece->moveDown();
    } else {
        currentPiece->moveDownFast();
    }

    if (game->checkIfLine()) {
        score->updateScore(100);
    }
    if (game->checkIfLost()) {
        running = false;
    }
}

void Tetris::render() {
    while (running) {
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);

        game->render(rend);
        title->render(rend, width / 2 - 170, 25);
        score->render(rend, width / 2 - 300, 100);
        next->render(rend, width - 200, 100);
        hold->render(rend, width / 2 - 290, 250);
        currentPiece->render(rend);

        turn();

        SDL_RenderPresent(rend);

        SDL_Delay(1000 / 60);
    }
}