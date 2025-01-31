#include <raylib.h>

#include "App.h"

int main(int argc, char *argv[]) {
  InitWindow(1280, 720, "Racing Game");
  SetTargetFPS(60);

  App app;

  app.Init();

  while (!WindowShouldClose()) {
    app.HandleInput();
    app.Update();
    app.Render();
  }

  app.CleanUp();

  CloseWindow();

  return 0;
}
