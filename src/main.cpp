#include <memory>
#include "Game.hpp"


int main(int argc, char *argv[]){
    std::unique_ptr<Game> game = std::make_unique<Game>(400, 400); 
    game->render();
    return 0;
}