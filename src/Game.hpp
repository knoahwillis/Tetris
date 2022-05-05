#pragma once
#include "BoardPieces/Score.hpp"
#include "BoardPieces/Title.hpp"
#include "BoardPieces/Next.hpp"
#include "BoardPieces/Hold.hpp"


class Game {
    int height, width;

    bool running;

    SDL_Renderer* rend;
    SDL_Window* window;

    // GameBoard* game;
    Title* title;
    Score* score;
    Next* next;
    Hold* hold;

public:
    Game(int h, int w);
    ~Game();

    bool endGame();

    void turn();

    void render();
};