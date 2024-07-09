#include "game_scene.h"

#include <iostream>
#include <raylib.h>

GameScene::GameScene() {}
GameScene::~GameScene() {}

void GameScene::Init() { std::cout << "Game Scene initialized!" << std::endl; }

void GameScene::Update() {}

void GameScene::Render() { DrawRectangle(200, 200, 100, 100, BLUE); }
