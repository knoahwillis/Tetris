#include "Tetris.hpp"
#include <iostream>

Tetris::Tetris(int h, int w) {
    height = h;
    width = w;

    running = true;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    game = new GameBoard(width / 2 - 130, 115);
    title = new Title;
    score = new Score;
    next = new Next;
    hold = new Hold;

    // pieces.push_back(new Border);
    int test = rand() % 7;
    switch (test) {
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

    for (auto pieces : piecesDown) {
        delete pieces;
    }

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
                currentPiece->moveLeft(piecesDown);
                break;
            case SDL_SCANCODE_D:
                currentPiece->moveRight(piecesDown);
                break;
            case SDL_SCANCODE_Q:
                currentPiece->rotateLeft();
                break;
            case SDL_SCANCODE_E:
                currentPiece->rotateRight();
                break;
            case SDL_SCANCODE_SPACE:
                break;
            case SDL_SCANCODE_ESCAPE:
                running = false;
                break;
            }
        }
    }

    if (currentPiece->current()[0].y + 30 >= 715 || currentPiece->current()[1].y + 30 >= 715 || currentPiece->current()[2].y + 30 >= 715 ||
        currentPiece->current()[3].y + 30 >= 715) {
        game->putInPlace(currentPiece);
        currentPiece = next->insertPiece();
    } else if (currentPiece->collision(game->piecesInPlace)) {
        game->putInPlace(currentPiece);
        currentPiece = next->insertPiece();
    } else {
        currentPiece->moveDown();
    }
    game->checkIfLine();
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
        for (int i = 0; i < piecesDown.size(); i++) {
            piecesDown[i]->render(rend);
        }

        this->turn();

        SDL_RenderPresent(rend);
    }
}