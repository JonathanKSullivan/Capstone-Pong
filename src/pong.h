#ifndef PONG_H_
#define PONG_H_

#include "game_obj.h"
#include "SDL.h"
#include "SDL_ttf.h"


// Pong Game Environment
class Pong {
 public:
  // Loads game and initializes game environment.
  Pong(int number_of_players, SDL_Surface* screen, const SDL_Event& occur);

  // Uninitializes game environment.
  ~Pong();
  // Update the value of the pong game objects based on input.
  void Update();

  // Renders pong game objects to screen.
  void Render();

  // Returns true if game is running otherwise false.
  bool GetRunningState() const;

  // Changes running state to false.
  void ChangeRunningState();

 private:
  Paddle* Player1;
  Paddle* Player2;
  Ball* ball;
  Uint32 white;  // Uint32 color
  SDL_Surface* screen;
  SDL_Event occur;
  bool running;
};

#endif  // PONG_H_
