#include "GamePieces.hpp"

void Piece::moveRight() {
    for (int i = 0; i < 4; i++) {
        piece[i].x += 35;
    }
}

void Piece::moveLeft() {
    for (int i = 0; i < 4; i++) {
        piece[i].x -= 35;
    }
}

void Piece::moveDown() {
    for (int i = 0; i < 4; i++) {
        piece[i].y += 1;
    }
    if(piece[3].y + 35 > 650){
        isDown = true;
    }
}

void Piece::render(SDL_Renderer *rend){
    SDL_SetRenderDrawColor(rend, color[0], color[1], color[2], 255);
    for(int i = 0; i < 4; i++){
        SDL_RenderFillRect(rend, &piece[i]);
    }
}

Piece::Piece() { isDown = false; }

Piece::~Piece() {}

I::I() {
    color = {0, 255, 255};
    piece[0] = SDL_Rect{130, 0, 35, 35};
    piece[1] = SDL_Rect{410, 0, 35, 35};
    piece[2] = SDL_Rect{445, 0, 35, 35};
    piece[3] = SDL_Rect{480, 0, 35, 35};
}