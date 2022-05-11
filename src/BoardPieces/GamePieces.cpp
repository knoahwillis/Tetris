#include "GamePieces.hpp"
#include <iostream>

void Piece::moveRight(std::vector<Piece*> pieces) {
    // if (!this->collision(pieces)) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            piece[j][i].x += 30;
        }
    }
    // }
}

void Piece::moveLeft(std::vector<Piece*> pieces) {
    // if (!this->collision(pieces)) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            piece[j][i].x -= 30;
            // }
        }
    }
}

void Piece::moveDown() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            piece[j][i].y += 2;
        }
        if (piece[pieceOrientation][i].y + 30 >= bottom) {
            bottom = piece[pieceOrientation][i].y + 30;
        }
        if (piece[pieceOrientation][i].y <= top) {
            top = piece[pieceOrientation][i].y;
        }
    }
}

void Piece::render(SDL_Renderer* rend) {
    switch (color) {
    case CYAN:
        SDL_SetRenderDrawColor(rend, 0, 255, 255, 255);
        break;
    case YELLOW:
        SDL_SetRenderDrawColor(rend, 255, 255, 0, 255);
        break;
    case PURPLE:
        SDL_SetRenderDrawColor(rend, 255, 0, 255, 255);
        break;
    case GREEN:
        SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);
        break;
    case RED:
        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
        break;
    case BLUE:
        SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
        break;
    case ORANGE:
        SDL_SetRenderDrawColor(rend, 255, 165, 0, 255);
        break;
    case WHITE:
        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        break;
    case NONE:
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        break;
    }
    for (int i = 0; i < 4; i++) {
        SDL_RenderFillRect(rend, &piece[pieceOrientation][i]);
    }
}

void Piece::rotateLeft() {
    if (pieceOrientation == 3) {
        pieceOrientation = 0;
    } else {
        pieceOrientation++;
    }
}

void Piece::rotateRight() {
    if (pieceOrientation == 0) {
        pieceOrientation = 3;
    } else {
        pieceOrientation--;
    }
}

bool Piece::collision(std::array<std::array<Color, 10>, 20> piecesInPlace) {
    int j, k;
    for (int i = 0; i < 4; i++) {
        j = ((piece[pieceOrientation][i].y + 30) / 30) - (115 / 30);
        k = ((piece[pieceOrientation][i].x) / 30) - (270 / 30);
        if (piecesInPlace[j][k] != NONE) {
            return true;
        }
    }
    return false;
}

Piece::Piece() { pieceOrientation = 0; }

Piece::~Piece() {}


std::array<SDL_Rect, 4> Piece::current() { return piece[pieceOrientation]; }

I::I() {
    color = CYAN;
    piece[0] = {SDL_Rect{360, 114, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{420, 114, 30, 30}, SDL_Rect{450, 114, 30, 30}};
    piece[1] = {SDL_Rect{390, 114, 30, 30}, SDL_Rect{390, 84, 30, 30}, SDL_Rect{390, 144, 30, 30}, SDL_Rect{390, 174, 30, 30}};
    piece[2] = piece[0];
    piece[3] = piece[1];
}

O::O() {
    color = YELLOW;
    piece[0] = {SDL_Rect{390, 114, 30, 30}, SDL_Rect{390, 84, 30, 30}, SDL_Rect{420, 84, 30, 30}, SDL_Rect{420, 114, 30, 30}};
    piece[1] = piece[0];
    piece[2] = piece[0];
    piece[3] = piece[0];
}

T::T() {
    color = PURPLE;
    piece[0] = {SDL_Rect{360, 84, 30, 30}, SDL_Rect{390, 84, 30, 30}, SDL_Rect{420, 84, 30, 30}, SDL_Rect{390, 54, 30, 30}};
    piece[1] = {SDL_Rect{420, 24, 30, 30}, SDL_Rect{420, 54, 30, 30}, SDL_Rect{420, 84, 30, 30}, SDL_Rect{390, 54, 30, 30}};
    piece[2] = {SDL_Rect{360, 24, 30, 30}, SDL_Rect{390, 24, 30, 30}, SDL_Rect{420, 24, 30, 30}, SDL_Rect{390, 54, 30, 30}};
    piece[3] = {SDL_Rect{360, 24, 30, 30}, SDL_Rect{360, 54, 30, 30}, SDL_Rect{360, 84, 30, 30}, SDL_Rect{390, 54, 30, 30}};
}

S::S() {
    color = GREEN;
    piece[0] = {SDL_Rect{360, 114, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{420, 84, 30, 30}, SDL_Rect{390, 84, 30, 30}};
    piece[1] = {SDL_Rect{360, 114, 30, 30}, SDL_Rect{360, 84, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{390, 144, 30, 30}};
    piece[2] = {SDL_Rect{360, 114, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{420, 84, 30, 30}, SDL_Rect{390, 84, 30, 30}};
    piece[3] = {SDL_Rect{360, 114, 30, 30}, SDL_Rect{360, 84, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{390, 144, 30, 30}};
}

Z::Z() {
    color = RED;
    piece[0] = {SDL_Rect{360, 84, 30, 30}, SDL_Rect{390, 84, 30, 30}, SDL_Rect{420, 114, 30, 30}, SDL_Rect{390, 114, 30, 30}};
    piece[1] = {SDL_Rect{390, 84, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{420, 114, 30, 30}, SDL_Rect{420, 144, 30, 30}};
    piece[2] = {SDL_Rect{360, 84, 30, 30}, SDL_Rect{390, 84, 30, 30}, SDL_Rect{420, 114, 30, 30}, SDL_Rect{390, 114, 30, 30}};
    piece[3] = {SDL_Rect{390, 84, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{420, 114, 30, 30}, SDL_Rect{420, 144, 30, 30}};
}

J::J() {
    color = BLUE;
    piece[0] = {SDL_Rect{360, 84, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{420, 114, 30, 30}, SDL_Rect{360, 114, 30, 30}};
    piece[1] = {SDL_Rect{360, 144, 30, 30}, SDL_Rect{390, 84, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{390, 144, 30, 30}};
    piece[2] = {SDL_Rect{420, 144, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{420, 114, 30, 30}, SDL_Rect{360, 114, 30, 30}};
    piece[3] = {SDL_Rect{420, 84, 30, 30}, SDL_Rect{390, 84, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{390, 144, 30, 30}};
}

L::L() {
    color = ORANGE;
    piece[0] = {SDL_Rect{420, 84, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{420, 114, 30, 30}, SDL_Rect{360, 114, 30, 30}};
    piece[1] = {SDL_Rect{360, 84, 30, 30}, SDL_Rect{390, 84, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{390, 144, 30, 30}};
    piece[2] = {SDL_Rect{360, 144, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{420, 114, 30, 30}, SDL_Rect{360, 114, 30, 30}};
    piece[3] = {SDL_Rect{420, 144, 30, 30}, SDL_Rect{390, 84, 30, 30}, SDL_Rect{390, 114, 30, 30}, SDL_Rect{390, 144, 30, 30}};
}

Border::Border() {
    color = WHITE;
    piece[0] = {SDL_Rect{0, 714, 1000, 1000}, SDL_Rect{0, 714, 1000, 1000}, SDL_Rect{0, 714, 1000, 1000}, SDL_Rect{0, 714, 1000, 1000}};
    piece[1], piece[2], piece[3] = piece[0], piece[0], piece[0];
}