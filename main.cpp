#include "src/Game.hpp"

int main() {
  // Initiating game engine
  Game game;

  while (game.getWindowIsOpen()) {
    game.update();
    game.render();
  }

  return 0;
}