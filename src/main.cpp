#include <raylib.h>

#include "game.h"

int main(int argc, char *argv[]) {
  InitWindow(1280, 720, "Racing Game");
  SetTargetFPS(60);

  Game game;

  game.Init();

  while (!WindowShouldClose()) {
    game.Update();
    game.Render();
  }

  CloseWindow();
  return 0;
}
