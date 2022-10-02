#include "controller.h"

#include <iostream>



void Controller::ChangeDirection(std::shared_ptr<Snake> snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake->direction != opposite || snake->size == 1) snake->direction = input;
  return;
}

void Controller::ChangeSpeed(std::shared_ptr<Snake> snake, float s) const
{
   if (snake->speed > 0.0 && snake->speed < 0.5) snake->speed = snake->speed + s;

   else snake->speed = 0.49;
   return;

}

void Controller::HandleInput(bool &running, std::shared_ptr<Snake> snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;

          //user can use S key to speed up the snake
        case SDLK_s:
          ChangeSpeed(snake, 0.01);

          break;

          //user can use D key to speed down the snake
        case SDLK_d:
          ChangeSpeed(snake, -0.01);

         break;

      }
    }
  }
}
