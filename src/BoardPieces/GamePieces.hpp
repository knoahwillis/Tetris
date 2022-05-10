#pragma once
#include <SDL2/SDL.h>
#include <array>
#include "../Color.hpp"
#include <vector>

class Piece {
protected:
    int pieceOrientation;

public:
    std::array<std::array<SDL_Rect, 4>, 4> piece;

    Color color;

    int bottom = 0;
    int top = 0;

    Piece();
    ~Piece();

    void moveRight(std::vector<Piece*> pieces);
    void moveLeft(std::vector<Piece*> pieces);
    void moveDown();

    void rotateLeft();
    void rotateRight();

    void render(SDL_Renderer* rend);

    std::array<SDL_Rect, 4> current();

    bool collision(std::array<std::array<Color, 10>, 20> piecesInPlace);
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

class Border : public Piece {
public:
    Border();
};
