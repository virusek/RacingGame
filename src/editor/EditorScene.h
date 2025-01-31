#pragma once

#include "core/core.h"

class EditorScene : public Scene {
public:
  EditorScene();
  ~EditorScene() override;

  void Init() override;
  void Update() override;
  void Render() override;
};
