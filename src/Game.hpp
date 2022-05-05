#pragma once
#include "BoardPieces/Title.hpp"
#include "BoardPieces/Score.hpp"


class Game {
    int height, width;

    bool running;

    SDL_Renderer* rend;
    SDL_Window* window;

    // GameBoard* game;
    Score* score;
    Title* title;
    // Hold* hold;
    // Next* next;

public:
    Game(int h, int w);
    ~Game();

    bool endGame();

    void turn();

    void render();
};