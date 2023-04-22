#include "Ball.hpp"

// Constructors / Destructors

Ball::Ball(Vector2f position, Color color) {
  // Ball creation
  this->hitbox.setRadius(5.f);
  this->hitbox.setFillColor(color);
  this->hitbox.setPosition(position);

  // Variables definition
  this->mass = 2;
  this->gravity = 9.8f;

  this->velocity = Vector2f(1.f, 0.f);
  this->acceleration = Vector2f(0.f, gravity);

  this->mecanicEnergy = (800 - position.y) * gravity * mass;
}

Ball::~Ball() {}

// Functions
void Ball::updateBall() {
  this->velocity += this->acceleration * this->elapsedTime.getElapsedTime().asSeconds();
  this->elapsedTime.restart();

  this->hitbox.move(velocity);

  // Window boarder inverter
  if (this->hitbox.getPosition().y >= 600) {
    this->velocity.y *= -1;
  }
  if (this->hitbox.getPosition().x >= 800 || this->hitbox.getPosition().x <= 0) {
    this->velocity.x *= -1;
    this->acceleration.x *= -1;
  }
}

void Ball::renderBall(RenderWindow* window) { window->draw(hitbox); }

// Accessors