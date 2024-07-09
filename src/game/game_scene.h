#pragma once
#include "../core/scene.h"

class GameScene : public Scene {
public:
  GameScene();
  ~GameScene() override;

  void Init() override;
  void Update() override;
  void Render() override;
};
