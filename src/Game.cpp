#include "Game.hpp"

// Private functions

// Initialize game functions

void Game::initVariables() { this->window = nullptr; }

void Game::initWindow() {
  this->videoMode.height = 600;
  this->videoMode.width = 800;

  this->window =
      new RenderWindow(videoMode, "Janela", Style::Titlebar | Style::Close);
}

void Game::initEnimies() {
  this->enemy.setPosition(window->getSize().x / 2, window->getSize().y / 2);
  this->enemy.setSize(Vector2f(100.f, 100.f));
  this->enemy.setFillColor(Color::Cyan);
}

/*
  Private Functions ↑
  Public Functions ↓
*/

// Consctructor / Destructors

Game::Game() {
  this->initVariables();
  this->initWindow();
  this->initEnimies();
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

void Game::update() { this->pollEvents(); }

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
  window->draw(enemy);

  this->window->display();
}

// Accessors
bool Game::getWindowIsOpen() { return this->window->isOpen(); }