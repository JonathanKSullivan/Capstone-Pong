#include <stdlib.h>

#include <ctime>
#include <sstream>

#include "pong.h"
#include "SDL.h"
#include "SDL_ttf.h"

SDL_Surface* screen;
SDL_Event occur;

SDL_Surface* screen;
SDL_Event occur;

int main(int argc, char* args[]) {
  if (true) {
    // Initialize SDL and TTF library.
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    // Initialize and load pong game.
    Pong pong_game = Pong(1, screen, occur);

    // Main Game loop.
    while (pong_game.GetRunningState() == true) {
      // Gather all events by polling.
      SDL_PollEvent(&occur);

      // Set running state to false if SDL is quited.
      if (occur.type == SDL_QUIT) {
        pong_game.ChangeRunningState();
      }

      // Update and render pong game.
      pong_game.Update();
      pong_game.Render();
    }
  }
  return 0;
}
