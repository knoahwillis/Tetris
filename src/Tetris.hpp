#pragma once
#include "BoardPieces/GameBoard.hpp"
#include "BoardPieces/GamePieces.hpp"
#include "BoardPieces/Hold.hpp"
#include "BoardPieces/Next.hpp"
#include "BoardPieces/Score.hpp"
#include "BoardPieces/Title.hpp"
#include "BoardPieces/Controls.hpp"
#include <vector>


class Tetris {
    int height, width;

    bool running;
    bool fallFast;

    SDL_Renderer* rend;
    SDL_Window* window;

    GameBoard* game;
    Title* title;
    Score* score;
    Next* next;
    Hold* hold;
    Controls* controls;

    Piece* currentPiece;

public:
    Tetris(int h, int w);
    ~Tetris();

    bool endGame();

    void turn();

    void render();
};