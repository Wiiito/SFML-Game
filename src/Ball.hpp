#pragma once

#include "Game.hpp"  // Removing vsc erro underline. The code runs perfectly without this

class Ball {
 private:
  // Variables
  CircleShape hitbox;

  Clock elapsedTime;

  float mass;
  float gravity;

  Vector2f velocity;
  Vector2f acceleration;

  float mecanicEnergy;
  float cineticEnergy;
  float gravityEnergy;

 public:
  // Constructors / Destructors
  Ball(Vector2f position, Color color);
  ~Ball();

  // Functions
  void updateBall();
  void renderBall(RenderWindow* window);
};

#include "Ball.cpp"