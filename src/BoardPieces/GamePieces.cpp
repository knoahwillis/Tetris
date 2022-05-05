#include "GamePieces.hpp"

void Piece::moveRight() {
    for (int i = 0; i < 4; i++) {
        piece[i].x += 30;
    }
}

void Piece::moveLeft() {
    for (int i = 0; i < 4; i++) {
        piece[i].x -= 30;
    }
}

void Piece::moveDown() {
    for (int i = 0; i < 4; i++) {
        piece[i].y += 1;
    }
    if (piece[3].y + 30 > 650) {
        isDown = true;
    }
}

void Piece::moveDownFast() {
    for (int i = 0; i < 4; i++) {
        piece[i].y += 20;
    }
    if (piece[3].y + 30 > 650) {
        isDown = true;
    }
}

void Piece::render(SDL_Renderer* rend) {
    SDL_SetRenderDrawColor(rend, color[0], color[1], color[2], 255);
    for (int i = 0; i < 4; i++) {
        SDL_RenderFillRect(rend, &piece[i]);
    }
}

Piece::Piece() { isDown = false; }

Piece::~Piece() {}

I::I() {
    color = {0, 165, 165};
    piece[0] = SDL_Rect{360, 114, 30, 30};
    piece[1] = SDL_Rect{390, 114, 30, 30};
    piece[2] = SDL_Rect{420, 114, 30, 30};
    piece[3] = SDL_Rect{450, 114, 30, 30};
}

O::O() {
    color = {255, 255, 0};
    piece[0] = SDL_Rect{390, 114, 30, 30};
    piece[1] = SDL_Rect{390, 84, 30, 30};
    piece[2] = SDL_Rect{420, 84, 30, 30};
    piece[3] = SDL_Rect{420, 114, 30, 30};
}

T::T() {
    color = {128, 0, 128};
    piece[0] = SDL_Rect{360, 114, 30, 30};
    piece[1] = SDL_Rect{390, 114, 30, 30};
    piece[2] = SDL_Rect{420, 114, 30, 30};
    piece[3] = SDL_Rect{390, 84, 30, 30};
}

S::S() {
    color = {0, 128, 0};
    piece[0] = SDL_Rect{360, 114, 30, 30};
    piece[1] = SDL_Rect{390, 114, 30, 30};
    piece[2] = SDL_Rect{420, 84, 30, 30};
    piece[3] = SDL_Rect{390, 84, 30, 30};
}

Z::Z() {
    color = {128, 0, 0};
    piece[0] = SDL_Rect{360, 84, 30, 30};
    piece[1] = SDL_Rect{390, 84, 30, 30};
    piece[2] = SDL_Rect{420, 114, 30, 30};
    piece[3] = SDL_Rect{390, 114, 30, 30};
}

J::J() {
    color = {0, 0, 128};
    piece[0] = SDL_Rect{360, 84, 30, 30};
    piece[1] = SDL_Rect{390, 114, 30, 30};
    piece[2] = SDL_Rect{420, 114, 30, 30};
    piece[3] = SDL_Rect{360, 114, 30, 30};
}

L::L() {
    color = {255, 165, 0};
    piece[0] = SDL_Rect{420, 84, 30, 30};
    piece[1] = SDL_Rect{390, 114, 30, 30};
    piece[2] = SDL_Rect{420, 114, 30, 30};
    piece[3] = SDL_Rect{360, 114, 30, 30};
}