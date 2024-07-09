#include "game.h"
#include <raylib.h>

#include "editor/editor_scene.h"
#include "game/game_scene.h"

#include <iostream>

Game::Game() {}

Game::~Game() { delete m_currentScene; }

void Game::loadScene(Scene *scene) {
  m_currentScene = scene;
  m_currentScene->Init();
}

void Game::Init() {
  std::cout << "Game Init called!" << std::endl;
  loadScene(new GameScene());
}

void Game::Update() { m_currentScene->Update(); }

void Game::Render() const {
  BeginDrawing();

  m_currentScene->Render();

  EndDrawing();
}
