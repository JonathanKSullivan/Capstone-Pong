#include "pong.h"

#include <sstream>
#include <iostream>

#include "game_obj.h"
#include "SDL.h"
#include "SDL_ttf.h"

Pong::Pong(int number_of_players, SDL_Window* screen, const SDL_Event& occur, SDL_Renderer* sdlRenderer) {
  running = true;

  // Format game font.
  white = SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);

  // Unseed random function.
  srand(time(NULL));

  // Create Game window.
  screen = screen = SDL_CreateWindow("Pong Clone",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          800, 600,
                          SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
  SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &screen, &sdlRenderer);
  
  // Create players and NPCS
  Player1 = new PlayerPaddle(1);
  Player2 = new AIPaddle(2);

  // Create Ball object.
  ball = new Ball();
}

void Pong::Update() {
std::cout << "Got KeysState"<< std::endl;
  const Uint8* keystates =  SDL_GetKeyboardState(NULL);
std::cout << "Player1 update"<< std::endl;
  Player1->Update(keystates, ball, occur);
std::cout << "Player2 update"<< std::endl;
  Player2->Update(keystates, ball, occur);
std::cout << "ball update"<< std::endl;
  ball->Update(Player1, Player2);
}

void Pong::Render(SDL_Renderer* sdlRenderer) {
std::cout << "Pong::Render"<< std::endl;

  SDL_FillRect(screen, NULL, 0);
std::cout << "SDL_FillRect"<< std::endl;
  
  Player1->Render(screen, white, sdlRenderer);
std::cout << "Player1->Render"<< std::endl;
  
  Player2->Render(screen, white, sdlRenderer);
std::cout << "Player2->Render"<< std::endl;
  
  ball->Render(screen, white);
std::cout << "ball->Render"<< std::endl;
  
  SDL_RenderPresent(sdlRenderer);
std::cout << "SDL_RenderPresent"<< std::endl;
  
}

Pong::~Pong() {
  TTF_Quit();
  SDL_Quit();
  delete ball;
  delete Player1;
  delete Player2;
}

bool Pong::GetRunningState() const { return running; }

void Pong::ChangeRunningState() { running = !running; }