#include "App.h"
#include <raylib.h>

#include "editor/EditorScene.h"
#include "game/GameScene.h"

#include <iostream>

App::App() {}

App::~App() { delete m_currentScene; }

void App::loadScene(Scene *scene) {
  m_currentScene = scene;
  m_currentScene->Init();
}

void App::Init() {
  std::cout << "Game Init called!" << std::endl;
  loadScene(new GameScene());
}

void App::Update() { m_currentScene->Update(); }

void App::Render() const {
  BeginDrawing();

  m_currentScene->Render();

  EndDrawing();
}
