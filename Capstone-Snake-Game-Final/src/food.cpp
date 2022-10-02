#include "food.h"
#include <iostream>

std::vector<SDL_Point> Food::normalFood(SDL_Point fo)
{
    _food.clear();
    _food.push_back(fo);
    return _food;
}

std::vector<SDL_Point> Food::megaFood(SDL_Point fo)
{
    _food.clear();
    SDL_Point f2;
    for(int x = 0; x < 2 ; x++)
    {
        for(int y = 0; y < 2 ; y++)
        {
            f2.x = fo.x + x;
            f2.y = fo.y + y;
            _food.push_back(f2);
        }
    }
    return _food;
}
