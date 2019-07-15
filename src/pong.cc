#include "pong.h"

#include "game_obj.h"
#include "SDL.h"
#include "SDL_ttf.h"

Pong::Pong(int number_of_players, SDL_Surface* screen, const SDL_Event& occur) {
  running = true;

  // Format game font.
  white = SDL_MapRGB(screen->format, 255, 255, 255);

  // Unseed random function.
  srand(time(NULL));

  // Create Game window.
  SDL_WM_SetCaption("pong", NULL);
  screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);

  // Create players and NPCS
  if (number_of_players == 0) {
    Player1 = new AIPaddle(1);
    Player2 = new AIPaddle(2);
  } else if (number_of_players == 1) {
    Player1 = new PlayerPaddle(1);
    Player2 = new AIPaddle(2);
  } else if (number_of_players == 2) {
    Player1 = new PlayerPaddle(1);
    Player2 = new PlayerPaddle(2);
  }

  // Create Ball object.
  ball = new Ball();
}

void Pong::Update() {
  Uint8* keystates = SDL_GetKeyState(NULL);
  Player1->Update(keystates, ball, occur);
  Player2->Update(keystates, ball, occur);
  ball->Update(Player1, Player2);
}

void Pong::Render() {
  SDL_FillRect(screen, NULL, 0);
  Player1->Render(screen, white);
  Player2->Render(screen, white);
  ball->Render(screen, white);
  SDL_Flip(screen);
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