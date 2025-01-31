#pragma once
#include "core/core.h"

class GameScene : public Scene {
private:


public:
  GameScene();
  ~GameScene() override;

  void Init() override;
  void Update() override;
  void Render() override;
};
