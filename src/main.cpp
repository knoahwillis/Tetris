#include "Tetris.hpp"
#include <memory>

int main(int argc, char* argv[]) {
    std::unique_ptr<Tetris> tetris = std::make_unique<Tetris>(800, 800);
    while (!tetris->endGame()) {
        tetris->render();
    }
    return 0;
}