#pragma once

#include "core/Scene.h"

class App {
  Scene *m_currentScene;
  void loadScene(Scene *scene);

public:
  App();
  ~App();

  void Init();
  void HandleInput();
  void Update();
  void Render() const;
  void CleanUp();
};
