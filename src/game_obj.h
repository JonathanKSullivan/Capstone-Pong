#ifndef GAME_OBJ_H_
#define GAME_OBJ_H_

#include "experimental/users/jonsullivan/util.h"
#include "third_party/SDL/include/third_party/SDL/SDL.h"
#include "third_party/SDL_ttf/SDL_ttf.h"

class GameObjects {
 public:
  GameObjects();
  virtual void Render(SDL_Surface* screen, Uint32 white);
  virtual ~GameObjects() = default;

 protected:
  int x_pos;
  int y_pos;
  int width;
  int height;
  SDL_Rect obj;
  TTF_Font* times;
};

class Paddle : public GameObjects {
  using GameObjects::Update;

 public:
  Paddle(int player_number);
  void Reset();
  virtual void IncrementScore();
  virtual void Render(SDL_Surface* screen, Uint32 white);

 protected:
  int score;
  SDL_Rect ScoreRect;
  std::stringstream ScoreStr;
  SDL_Surface* ScoreSurface;
  int player_number;
};

class PlayerPaddle : public Paddle {
  PlayerPaddle(int player_number);
  void Update(Uint8* keystates, Ball* ball, const SDL_Event& occur);
  void Update(Uint8* keystates, const SDL_Event& occur);
};

class AIPaddle : public Paddle {
 public:
  AIPaddle(int player_number);
  void Update(Uint8* keystates, Ball* ball, const SDL_Event& occur);
  void Update(Ball* ball);
};

class Ball : public GameObjects {
 public:
  Ball();
  virtual ~Ball() = default;

  int get_height() const;

  int get_y() const;

  void Update(Paddle* Paddle1, Paddle* Paddle2) override;
  virtual void Reset();

 private:
  static const int kBallX = 390;
  static const int kBallY = 290;
  int x_vel;
  int y_vel;
};

#endif  // GAME_OBJ_H_
