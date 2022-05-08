#pragma once
#include <SDL2/SDL.h>
#include <array>
#include <vector>

class Piece {
protected:
    std::array<int, 3> color;
    int pieceOrientation;

public:
    std::array<std::array<SDL_Rect, 4>, 4> piece;

    int bottom = 0;
    int top = 0;
    bool isDown;

    Piece();
    ~Piece();

    void moveRight();
    void moveLeft();
    void moveDown();

    void rotateLeft();
    void rotateRight();

    void render(SDL_Renderer* rend);

    std::array<int, 8> getY();

    std::array<SDL_Rect, 4> current();
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
