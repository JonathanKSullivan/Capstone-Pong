#include "game_obj.h"

#include <sstream>

#include "util.h"
#include "SDL.h"
#include "SDL_ttf.h"

namespace {
static const SDL_Color getFontColor() {
  SDL_Color Pink = {255, 0, 255};
  return Pink;
}
}  // namespace

GameObjects::GameObjects()
    : times(TTF_OpenFont(
          "third_party/googlefonts/api/monotype/timesnewroman/times.ttf", 14)) {
}

void GameObjects::Render(SDL_Surface* screen, Uint32 white) {
  obj.x = x_pos;
  obj.y = y_pos;
  obj.w = width;
  obj.h = height;
  SDL_FillRect(screen, &obj, white);
}

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
void Paddle::Render(SDL_Surface* screen, Uint32 white) {
  obj.x = x_pos;
  obj.y = y_pos;
  obj.w = width;
  obj.h = height;
  SDL_FillRect(screen, &obj, white);
  ScoreStr << score;
  ScoreSurface =
      TTF_RenderText_Solid(times, ScoreStr.str().c_str(), getFontColor());
  SDL_BlitSurface(ScoreSurface, NULL, screen, &ScoreRect);
}

PlayerPaddle::PlayerPaddle(int player_number) : Paddle(player_number) {}
void PlayerPaddle::Update(Uint8* keystates, Ball* ball,
                          const SDL_Event& occur) {
  if (player_number == 1) {
    if (keystates[SDLK_w] && y_pos > 1) {
      y_pos -= 1;
    }
    if (keystates[SDLK_s] && y_pos + height < 599) {
      y_pos += 1;
    }
  }
  if (player_number == 2) {
    if (keystates[SDLK_UP] && y_pos > 1) {
      y_pos -= 1;
    }
    if (keystates[SDLK_DOWN] && y_pos + height < 599) {
      y_pos += 1;
    }
  }
}

void PlayerPaddle::Update(Uint8* keystates, const SDL_Event& occur) {
  Update(keystates, nullptr, occur);
}

AIPaddle::AIPaddle(int player_number) : Paddle(player_number) {}
void AIPaddle::Update(Uint8* keystates, Ball* ball, const SDL_Event& occur) {
  if (y_pos + 0.5 * width > ball->get_y() + 0.5 * ball->get_height() &&
      y_pos > 1) {
    y_pos--;
  }

  if (y_pos + 0.5 * height < ball->get_y() + 0.5 * ball->get_height() &&
      y_pos + height < 599) {
    y_pos++;
  }
}

void AIPaddle::Update(Ball* ball) { Update(nullptr, ball, NULL); }

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

  if (CheckCollision(this, Paddle1) == true ||
      CheckCollision(Paddle2, this) == true) {
    x_vel = -x_vel;
  }
}
void Ball::Reset() {
  x_pos = kBallX;
  y_pos = kBallY;
  x_vel = GetRandomNumber(2, -2);
  y_vel = GetRandomNumber(2, -2);
}
