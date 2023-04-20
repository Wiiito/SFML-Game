#pragma once

// Includes
#include <SFML/Graphics.hpp>
using namespace sf;

// Game engine / Wrapper Class

class Game {
 private:
  // Variables
  RenderWindow* window;
  VideoMode videoMode;
  Event ev;

  // Game objects
  RectangleShape enemy;

  // Private Functions
  void initVariables();
  void initWindow();
  void initEnimies();

 public:
  // Constructors / Destructors
  Game();
  ~Game();

  // Functions
  void pollEvents();
  void update();
  void render();

  // Accessors
  bool getWindowIsOpen();
};

#include "Game.cpp"