#include "game.h"

#include <raylib.h>

Game::Game() {}

void Game::Init() {}

void Game::Update() {}

void Game::Render() const {
  BeginDrawing();
  DrawRectangle(200, 200, 100, 100, RED);
  EndDrawing();
}
