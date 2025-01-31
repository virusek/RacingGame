#pragma once

#include "core/Scene.h"

#include <vector>

class App {
  Scene *m_currentScene;

  std::vector<Scene*> m_scenes;

  void loadScene(Scene *scene);
  void renderUI();
public:
  App() = default;
  ~App() = default;

  void Init();
  void HandleInput();
  void Update();
  void Render();
  void CleanUp();
};
