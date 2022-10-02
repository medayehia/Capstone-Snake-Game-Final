#ifndef GAME_H
#define GAME_H

#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "food.h"
#include "score.h"

#include <random>
#include <SDL.h>


class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  std::shared_ptr<Snake> snake;
  std::unique_ptr<Food> myFood;
  std::vector<SDL_Point> food;
  SDL_Point fo;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  Score Tscore;

  int count = 1;

  int score{0};

  void PlaceFood();
  void Update();
};

#endif
