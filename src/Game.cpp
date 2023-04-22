#include "Game.hpp"

// Private functions

// Initialize game functions

void Game::initVariables() {
  // Randomize rand() with srand and time
  std::srand(static_cast<unsigned>(time(NULL)));

  // Initialize null window pointer
  this->window = nullptr;

  // Game varibles
  this->maxBalls = 1000;
}

void Game::initWindow() {
  this->videoMode.height = 600;
  this->videoMode.width = 800;

  this->window = new RenderWindow(videoMode, "Janela", Style::Titlebar | Style::Close);

  this->window->setFramerateLimit(60);
}

/*
  Private Functions ↑
  Public Functions ↓
*/

// Consctructor / Destructors

Game::Game() {
  this->initVariables();
  this->initWindow();
}

Game::~Game() { delete this->window; }

// Functions
void Game::pollEvents() {
  /*
    Pool window events
  */

  while (this->window->pollEvent(this->ev)) {
    switch (this->ev.type) {
      case Event::Closed:
        window->close();
        break;
      case Event::KeyPressed:
        if (this->ev.key.code == Keyboard::Escape) {
          window->close();
        }
    }
  }
}

void Game::updateMousePosition() {
  /*
    @return void

    Update the mouse position relative to screen
  */
  this->mousePos = Mouse::getPosition(*this->window);
}

void Game::spawnBall() {
  /*
    @return void

    Spawns Balls and sets their colors and positions
    - Sets a random position
    - Sets a random color
    - Adds Ball to the vector
  */

  static int count = 1;

  float wavelength = (float)count / this->maxBalls;
  float r = 0.0f, g = 0.0f, b = 0.0f;

  if (wavelength < 0.5f) {
    r = 1.0f - 2.0f * wavelength;
    g = 2.0f * wavelength;
    b = 0.0f;
  } else {
    r = 0.0f;
    g = 2.0f - 2.0f * wavelength;
    b = 2.0f * (wavelength - 0.5f);
  }

  count++;

  Color color(r * 255, g * 255, b * 255);

  Vector2f position(rand() % 800, 10);

  Ball ball(position, color);

  balls.push_back(ball);
}

void Game::updateBalls() {
  /*
    @return void

    Spawn enimies
    - Check if Ball spawn time has elapsed, if so, spawn another Ball
    - Go through the Balls array and update all Balls

    Move enimies

    Remove Ball out of screen // TODO

  */

  // Checks if the time has elapsed && max Balls is greater than Balls on screen
  if (this->maxBalls > this->balls.size()) {
    // Spawn Ball and restart the timer
    this->spawnBall();
  }

  for (auto &elem : this->balls) {
    elem.updateBall();
  }
}

void Game::renderBalls() {
  /*
    @return void
    - Go through the Balls array and render all Balls
  */

  for (auto &elem : this->balls) {
    elem.renderBall(window);
  }
}

void Game::update() {
  this->pollEvents();

  this->updateMousePosition();

  this->updateBalls();
}

void Game::render() {
  /*
      @return void

    - Clear Window
    - Draw window objects
    - Diplay window

    Renders the gameo bjects;
  */

  this->window->clear();

  // Drawing game objects

  this->renderBalls();

  this->window->display();
}

// Accessors
bool Game::getWindowIsOpen() { return this->window->isOpen(); }