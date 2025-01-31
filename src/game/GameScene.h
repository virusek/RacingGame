#pragma once
#include "../core/Scene.h"

class GameScene : public Scene {
public:
  GameScene();
  ~GameScene() override;

  void Init() override;
  void Update() override;
  void Render() override;
};
