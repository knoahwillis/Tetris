#include "Game.hpp"
#include <memory>

int main(int argc, char* argv[]) {
    std::unique_ptr<Game> game = std::make_unique<Game>(800, 800);
    while (game->endGame()) {
        game->render();
    }
    return 0;
}