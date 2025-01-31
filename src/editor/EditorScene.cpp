#include "EditorScene.h"

#include <iostream>
#include <raylib.h>

EditorScene::EditorScene() {}
EditorScene::~EditorScene() {}

void EditorScene::Init() {
  std::cout << "Editor Scene initialized!" << std::endl;
}

void EditorScene::Update() {}

void EditorScene::Render() { DrawRectangle(200, 200, 100, 100, GREEN); }
