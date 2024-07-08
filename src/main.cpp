#include <raylib.h>

int main(int argc, char *argv[]) {
  InitWindow(1280, 720, "Racing Game");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawRectangle(200, 200, 100, 100, RED);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
