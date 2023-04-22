#pragma once

// Includes
#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

using namespace sf;

#include "Ball.hpp"

// Game engine / Wrapper Class

class Game {
 private:
  // Variables
  RenderWindow* window;
  VideoMode videoMode;
  Event ev;

  // Game logic
  int maxBalls;

  int cnt;
  float freq;

  // Game objects
  std::vector<Ball> balls;
  Vector2i mousePos;

  // Private Functions
  void initVariables();
  void initWindow();

 public:
  // Constructors / Destructors
  Game();
  ~Game();

  // Functions
  void pollEvents();
  void updateMousePosition();
  void spawnBall();
  void updateBalls();
  void renderBalls();
  void update();
  void render();

  // Accessors
  bool getWindowIsOpen();
};

#include "Game.cpp"