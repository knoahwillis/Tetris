#pragma once
#include "BoardPieces/Title.hpp"

class Game {
    int height, width;

    bool running;

    SDL_Renderer* rend;
    SDL_Window* window;

    // GameBoard* game;
    // ScoreBoard* score;
    Title* title;
    // Hold* hold;
    // Next* next;

public:
    Game(int h, int w);
    ~Game();

    void render();

    void turn();
};