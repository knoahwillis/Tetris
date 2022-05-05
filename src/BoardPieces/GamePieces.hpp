#pragma once
#include "../Color.hpp"
#include <SDL2/SDL.h>
#include <array>
#include <tuple>

class Piece {
protected:
    std::array<int, 3> color;
    std::array<SDL_Rect, 4> piece;

public:
    bool isDown;
    Piece();
    ~Piece();

    void moveRight();
    void moveLeft();
    void moveDown();
    void moveDownFast();

    void render(SDL_Renderer* rend);
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
