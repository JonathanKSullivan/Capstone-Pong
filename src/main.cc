#include <stdlib.h>

#include <ctime>
#include <sstream>
#include <iostream>

#include "pong.h"
#include "SDL.h"
#include "SDL_ttf.h"

SDL_Window* screen;
SDL_Event occur;
SDL_Renderer* sdlRenderer;

int main(int argc, char* args[]) {
  if (true) {
  std::cout << "1" << std::endl;
    // Initialize SDL and TTF library.
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    if (TTF_Init() < 0) {
      // Error handling code
      std::cout << "ERROR with TFF" << std::endl;
	}

  std::cout << "2" << std::endl;

    // Initialize and load pong game.
    Pong pong_game = Pong(1, screen, occur, sdlRenderer);

  std::cout << "3" << std::endl;

    // Main Game loop.
    while (pong_game.GetRunningState() == true) {
  std::cout << "a" << std::endl;
    
    
      // Gather all events by polling.
      SDL_PollEvent(&occur);
  std::cout << "b" << std::endl;

      // Set running state to false if SDL is quited.
      if (occur.type == SDL_QUIT) {
        pong_game.ChangeRunningState();
      }

      // Update and render pong game.
  std::cout << "c" << std::endl;
      pong_game.Update();
  std::cout << "d" << std::endl;
      pong_game.Render(sdlRenderer);
    }
  }
  return 0;
}
