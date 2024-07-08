#pragma once

class Game {

public:
  Game();
  ~Game() = default;

  void Init();
  void HandleInput();
  void Update();
  void Render() const;
};
