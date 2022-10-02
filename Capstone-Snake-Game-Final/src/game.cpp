#include "game.h"
#include <iostream>
#include <memory>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(new Snake(grid_width, grid_height)),
      myFood(new Food()),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1))
{
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(*snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.UpdateWindowTitle(score,snake->speed *100, Tscore.topScore(), frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood()
{
  int x, y;
  while (true)
  {
    x = random_w(engine);
    y = random_h(engine);
    
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake->SnakeCell(x, y))
    {
       fo.x = x;
       fo.y = y;

       if ((count % 4) == 0)
       {
         food = myFood->megaFood(fo);
       }
       else
       {
         food = myFood->normalFood(fo);
       }

      return;
    }
  }
}

void Game::Update()
{
  if (!snake->alive)
    return;

  snake->Update();

  int new_x = static_cast<int>(snake->head_x);
  int new_y = static_cast<int>(snake->head_y);
  // Check if there's food over here
   for (SDL_Point const fo : food)
   {
    if (fo.x == new_x && fo.y == new_y)
    {
      if(food.size() > 1)
      {
          score = score + 2;
          snake->GrowBody();
      }
      else
      {
          score++;
          snake->GrowBody();
      }

      count++;
      PlaceFood();
      // Grow snake and increase speed.
      if(snake->speed < 0.5) snake->speed += 0.01;
    }
  }
 }
int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake->size; }
