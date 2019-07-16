#include <stdio.h>  /* defines FILENAME_MAX */
// #define WINDOWS  /* uncomment this line to use it for windows.*/ 
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>

#include "game_obj.h"

#include <sstream>
#include <iostream>
#include "util.h"
#include "SDL.h"
#include "SDL_ttf.h"

namespace {
const SDL_Color getFontColor() {
  SDL_Color Pink = {255, 0, 255};
  return Pink;
}
}  // namespace

std::string GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}

GameObjects::GameObjects()
    : times(TTF_OpenFont(
          "/home/workspace/Capstone-Pong/src/TIMES.TTF", 14)) {
          if(!times) {
            printf("TTF_OpenFont: %s\n", TTF_GetError());
            // handle error
          }
}

void GameObjects::Render(SDL_Surface* screen, Uint32 white) {
  obj.x = x_pos;
  obj.y = y_pos;
  obj.w = width;
  obj.h = height;
  SDL_FillRect(screen, &obj, white);
}

SDL_Rect GameObjects::GetObj() const{ return obj; }

Paddle::Paddle(int player_number) : player_number(player_number) {
  score = 0;
  if (player_number == 1) {
    x_pos = 20;
    y_pos = 250;
    width = 75;
    height = 20;
    ScoreRect.x = 50;
  }
  if (player_number == 2) {
    x_pos = 760;
    y_pos = 250;
    width = 100;
    height = 20;
    ScoreRect.x = 725;
  }
}

void Paddle::Reset() {
  if (player_number == 1) {
    x_pos = 20;
    y_pos = 250;
    width = 75;
    height = 20;
    ScoreRect.x = 50;
  }
  if (player_number == 2) {
    x_pos = 760;
    y_pos = 250;
    width = 100;
    height = 20;
    ScoreRect.x = 725;
  }
}
void Paddle::IncrementScore() { score++; }
void Paddle::Render(SDL_Surface* screen, Uint32 white, SDL_Renderer* sdlRenderer) {
std::cout << "Render Paddle" <<std::endl;
  obj.x = x_pos;
  obj.y = y_pos;
  obj.w = width;
  obj.h = height;
std::cout << "Create obj" <<std::endl;
  SDL_FillRect(screen, &obj, white);
std::cout << "SDL_FillRect" <<std::endl;
  ScoreStr << score;
  std::cout << "score" <<std::endl;
  getFontColor();
  std::cout << "ScoreSurface" <<std::endl;
  if(!times) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
    // handle error
  }
  ScoreSurface =
      TTF_RenderText_Solid(times, ScoreStr.str().c_str(), getFontColor());
  std::cout << "getFontColor()" <<std::endl;
      

      
  SDL_BlitSurface(ScoreSurface, NULL, screen, &ScoreRect);
}

void Paddle::Update(const Uint8* keystates, Ball* ball,
                          SDL_Event& occur) {}

PlayerPaddle::PlayerPaddle(int player_number) : Paddle(player_number) {}
void PlayerPaddle::Update(const Uint8* keystates, Ball* ball,
                          SDL_Event& occur){
  std::cout << "PlayerPaddle::Update" << std::endl;
  if (player_number == 1) {
  std::cout << "PlayerPaddle::Update 1" << std::endl;
  
    if (keystates[SDL_SCANCODE_W] && y_pos > 1) {
  std::cout << "PlayerPaddle::Update 1 up" << std::endl;
    
      y_pos -= 1;
    }
    if (keystates[SDL_SCANCODE_S] && y_pos + height < 599) {
  std::cout << "PlayerPaddle::Update 1 down" << std::endl;
    
      y_pos += 1;
    }
  }
  if (player_number == 2) {
  std::cout << "PlayerPaddle::Update 2" << std::endl;
  
    if (keystates[SDL_SCANCODE_UP] && y_pos > 1) {
  std::cout << "PlayerPaddle::Update 2 up" << std::endl;
    
      y_pos -= 1;
    }
    if (keystates[SDL_SCANCODE_DOWN] && y_pos + height < 599) {
  std::cout << "PlayerPaddle::Update 2 down" << std::endl;
    
      y_pos += 1;
    }
  }
}



void PlayerPaddle::Update(const Uint8* keystates, SDL_Event& occur)  {
  Update(keystates, nullptr, occur);
}

AIPaddle::AIPaddle(int player_number) : Paddle(player_number) {}
void AIPaddle::Update(const Uint8* keystates, Ball* ball, SDL_Event& occur) {
  if (y_pos + 0.5 * width > ball->get_y() + 0.5 * ball->get_height() &&
      y_pos > 1) {
    y_pos--;
  }

  if (y_pos + 0.5 * height < ball->get_y() + 0.5 * ball->get_height() &&
      y_pos + height < 599) {
    y_pos++;
  }
}

void AIPaddle::Update(Ball* ball) {SDL_Event _; Update(nullptr, ball, _); }

Ball::Ball() {
  Reset();
  height = 100;
  width = 20;
}

int Ball::get_height() const { return height; }

int Ball::get_y() const { return y_pos; }

void Ball::Update(Paddle* Paddle1, Paddle* Paddle2) {
  y_pos += y_vel;
  x_pos += x_vel;
  if (y_pos < 1 || y_pos + height > 599) {
    y_vel = -y_vel;
  }

  if (x_pos < 2) {
    Reset();
    Paddle1->IncrementScore();
  }

  if (x_pos + width > 798) {
    Reset();
    Paddle2->IncrementScore();
  }

  if (CheckCollision(this->GetObj(), Paddle1->GetObj()) == true ||
      CheckCollision(Paddle2->GetObj(), this->GetObj()) == true) {
    x_vel = -x_vel;
  }
}

void Ball::Reset() {
  x_pos = kBallX;
  y_pos = kBallY;
  x_vel = GetRandomNumber(2, -2);
  y_vel = GetRandomNumber(2, -2);
}
