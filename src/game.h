#pragma once

#include "core/scene.h"

class Game {
private:
  Scene *m_currentScene;

private:
  void loadScene(Scene *scene);

public:
  Game();
  ~Game();

  void Init();
  void HandleInput();
  void Update();
  void Render() const;
  void CleanUp();
};
