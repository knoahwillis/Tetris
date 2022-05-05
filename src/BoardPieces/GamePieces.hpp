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

    void render(SDL_Renderer *rend);
};

class I : public Piece {
public:
    I();
};

class O : public Piece {};

class T : public Piece {};

class S : public Piece {};

class Z : public Piece {};

class J : public Piece {};

class L : public Piece {};
