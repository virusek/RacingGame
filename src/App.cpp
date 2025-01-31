#include "App.h"

#include "core/core.h"

#include "editor/EditorScene.h"
#include "game/GameScene.h"

void App::loadScene(Scene *scene) {
  m_currentScene = scene;
  m_currentScene->Init();
}

void App::renderUI() {
  rlImGuiBegin();

  ImGui::Begin("Scenes");

  if(ImGui::Button("Game Scene")) {
    LOG("Game Scene");
    loadScene(m_scenes[0]);
  }

  if(ImGui::Button("Editor Scene")) {
    LOG("Editor Scene");
    loadScene(m_scenes[1]);
  }

  ImGui::End();

  rlImGuiEnd();
}

void App::Init() {
  LOG_INIT("App init called!");

  m_scenes.push_back(new GameScene());
  m_scenes.push_back(new EditorScene());

  rlImGuiSetup(true);

  loadScene(m_scenes[0]);
}

void App::HandleInput() {

}

void App::Update() { m_currentScene->Update(); }

void App::Render() {
  BeginDrawing();
  ClearBackground(RAYWHITE);

  renderUI();

  m_currentScene->Render();

  EndDrawing();
}

void App::CleanUp() {
  rlImGuiShutdown();

  for (int i = 0; i < m_scenes.size(); i++) {
    delete m_scenes[i];
  }
}
