#ifndef _GAME_UTILS_
#define _GAME_UTILS_

typedef enum states{
  START,
  BEGIN,
  PLAY,
  SHOW_SCORE,
  GAME_OVER,
  SLEEP
} states;

typedef enum difficulties{
  EASY = 1,
  MEDIUM,
  HARD,
  IMPOSSIBLE
} difficulties;

void setupInitialTime();

void setupScore();

void scoreIncrement();

char* getNextNum();

bool checkScore();

char* getScore();

void nextGameTime();

void gameSetup();

void gamePlay();

#endif