#pragma once
#include "../Color.hpp"
#include "Score.hpp"
#include <SDL2/SDL.h>
#include <array>
#include <vector>

class Piece {
protected:
    int pieceOrientation;


public:
    std::array<std::array<SDL_Rect, 4>, 4> piece;

    int fallSpeed;

    Color color;

    Piece();
    ~Piece();

    void moveRight();
    void moveLeft();
    Piece movedRight();
    Piece movedLeft();

    void moveDown(Score* score);
    void moveDownFast(Score* score);

    void rotateRight();
    void rotateLeft();
    Piece rotatedRight();
    Piece rotatedLeft();

    void render(SDL_Renderer* rend);

    std::array<SDL_Rect, 4> current();

    bool collision(std::array<std::array<Color, 12>, 21> piecesInPlace);
};

class I : public Piece {
public:
    I();
};

class O : public Piece {
public:
    O();
};

class T : public Piece {
public:
    T();
};

class S : public Piece {
public:
    S();
};

class Z : public Piece {
public:
    Z();
};

class J : public Piece {
public:
    J();
};

class L : public Piece {
public:
    L();
};
