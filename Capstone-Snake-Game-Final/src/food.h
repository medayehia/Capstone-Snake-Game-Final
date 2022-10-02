#ifndef FOOD_H
#define FOOD_H

#include<vector>
#include<memory>
#include<SDL.h>

class Food
{
public:
//    Food(std::vector<SDL_Point> food): _food(food){};

    std::vector<SDL_Point> normalFood(SDL_Point fo);

    std::vector<SDL_Point> megaFood(SDL_Point fo);

private:

// SDL_Point _food;
std::vector<SDL_Point> _food;
//    std::shared_ptr<SDL_Point> _food;

};

#endif
