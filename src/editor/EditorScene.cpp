#include "EditorScene.h"

#include <iostream>
#include <raylib.h>

EditorScene::EditorScene() {
  LOG("Creating a new EditorScene");
}

EditorScene::~EditorScene() {
  LOG("Destructing EditorScene");
}

void EditorScene::Init() {
  LOG_INIT("EditorScene Initialized!");
}

void EditorScene::Update() {}

void EditorScene::Render() { DrawRectangle(200, 200, 100, 100, GREEN); }
