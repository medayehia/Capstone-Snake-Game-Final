#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "score.h"

#include <iostream>
#include <chrono>
#include <thread>

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};


  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  Score score;
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  score.writeScore(game.GetScore());
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Top Score: " << score.topScore()<< "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}
