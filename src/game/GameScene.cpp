#include "GameScene.h"

GameScene::GameScene() {
  LOG("Creating a new GameScene");
}

GameScene::~GameScene() {
  LOG("Destructing GameScene");
}

void GameScene::Init() {
  LOG_INIT("GameScene Initialized!");
}

void GameScene::Update() {
}

void GameScene::Render() { DrawRectangle(200, 200, 100, 100, BLUE); }
