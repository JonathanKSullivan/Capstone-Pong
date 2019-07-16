#ifndef GAME_OBJ_H_
#define GAME_OBJ_H_

#include <sstream>

#include "util.h"
#include "SDL.h"
#include "SDL_ttf.h"

class GameObjects {
 public:
  GameObjects();
  virtual void Render(SDL_Surface* screen, Uint32 white);
  SDL_Rect GetObj() const;
  virtual ~GameObjects() = default;

 protected:
  int x_pos;
  int y_pos;
  int width;
  int height;
  SDL_Rect obj;
  TTF_Font* times;
};
class Ball;
class Paddle : public GameObjects {
 public:
  Paddle(int player_number);
  void Reset();
  virtual void IncrementScore();
  virtual void Render(SDL_Surface* screen, Uint32 white, SDL_Renderer* sdlRenderer);
  virtual void Update(const Uint8* keystates, Ball* ball,
                          SDL_Event& occur);

 protected:
  int score;
  SDL_Rect ScoreRect;
  std::stringstream ScoreStr;
  SDL_Surface* ScoreSurface;
  int player_number;
};

class Ball : public GameObjects {
 public:
  Ball();
  virtual ~Ball() = default;

  int get_height() const;
  int get_y() const;

  void Update(Paddle* Paddle1, Paddle* Paddle2);
  virtual void Reset();

 private:
  static const int kBallX = 390;
  static const int kBallY = 290;
  int x_vel;
  int y_vel;
};

class PlayerPaddle : public Paddle {
 public:
  PlayerPaddle(int player_number);
  void Update(const Uint8* keystates, Ball* ball, SDL_Event& occur) 
    override;
  void Update(const Uint8* keystates, SDL_Event& occur);
};

class AIPaddle : public Paddle {
 public:
  AIPaddle(int player_number);
  void Update(const Uint8* keystates, Ball* ball, SDL_Event& occur)
    override;
  void Update(Ball* ball);
};


#endif  // GAME_OBJ_H_
