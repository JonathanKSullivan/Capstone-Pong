#ifndef UTIL_H_
#define UTIL_H_
#include "SDL.h"

// Checks if point (x,y) is located in Rectangle rec
bool PointInRect(int x, int y, SDL_Rect rec);

// Checks if the is a collision between Rectangle r1 and Rectangle r2.
bool CheckCollision(SDL_Rect r1, SDL_Rect r2);

// Generate a random number between low and high.
int GetRandomNumber(int high, int low);

#endif  // UTIL_H_
