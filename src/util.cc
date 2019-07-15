#include "util.h"

#include "SDL.h"

bool PointInRect(int x, int y, SDL_Rect rec) {
  if (x > rec.x && y > rec.y && x < rec.x + rec.w && y < rec.y + rec.h) {
    return true;
  }
  return false;
}

bool CheckCollision(SDL_Rect r1, SDL_Rect r2) {
  if (PointInRect(r1.x, r1.y, r2) == true ||
      PointInRect(r1.x + r1.w, r1.y, r2) == true ||
      PointInRect(r1.x, r1.y + r1.h, r2) == true ||
      PointInRect(r1.x + r1.w, r1.y + r1.h, r2) == true) {
    return true;
  }
  return false;
}

int GetRandomNumber(int high, int low) {
  return rand() % (high - low + 1) + low;
}
