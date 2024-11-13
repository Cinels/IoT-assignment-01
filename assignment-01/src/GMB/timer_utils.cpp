#include "timer_utils.h"
#include <avr/sleep.h>
#include <Timer.h>
#include "lcd_utils.h"
#include "led_utils.h"

#define TEN_SEC 10000
#define IN_SECOND 1000.0
#define ONE_SEC 1000

Timer sleepT;
Timer gameT;
Timer scoreT;

void stopSleepTimer() {
  sleepT.stop();
}

float sleepTimer(states* state) {
  if(*state == START && sleepT.state() != RUNNING) {
    // Serial.println("sleep timer started");
    sleepT.start();
  }
  if(*state == START && sleepT.read() >= TEN_SEC) {
    sleepT.stop();
    *state = SLEEP;
    turnAllLedOff();
    sleepScreen();

    // Serial.println("SLEEP");
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode();  

    sleep_disable();
    // Serial.println("AWAKE");
    return 0.0;
  }
  return (float)((TEN_SEC - sleepT.read())/IN_SECOND);
}

float gameTimer(states* state, long time) {
  if(*state == PLAY && gameT.state() != RUNNING) {
    // Serial.println("game timer started");
    gameT.start();
  }
  if(*state == PLAY && gameT.read() >= time) {
    gameT.stop();
    if(checkScore()) {
      // Serial.println("SHOW_SCORE");
      *state = SHOW_SCORE;
      scoreIncrement();
      scoreScreen();
      printLcd(SCORE_POSITION, getScore());
      nextGameTime();
    } else {
      // Serial.println("GAME_OVER");
      *state = GAME_OVER;
      lightRedLed();
      gameOverScreen();
      printLcd(SCORE_POSITION, getScore());
    }
    return 0.0;
  }
  return (float)((time - gameT.read())/IN_SECOND);
}

float scoreTimer(states* state) {
  if((*state == SHOW_SCORE || *state == BEGIN) && scoreT.state() != RUNNING) {
    // Serial.println("score timer started");
    scoreT.start();
  }
  if((*state == SHOW_SCORE || *state == BEGIN) && scoreT.read() >= ONE_SEC) {
    scoreT.stop();
    // Serial.println("PLAY");
    *state = PLAY;
    turnAllLedOff();
    playScreen();
    printLcd(NUMBER_POSITION, getNextNum());
    return 0.0;
  }
  return (float)((ONE_SEC - scoreT.read())/IN_SECOND);
}

float overTimer(states* state) {
  if(*state == GAME_OVER && scoreT.state() != RUNNING) {
    // Serial.println("(game over) score timer started");
    scoreT.start();
  }
  if(*state == GAME_OVER && scoreT.read() >= TEN_SEC) {
    scoreT.stop();
    // Serial.println("START");
    *state = START;
    startScreen();
    fadeInitialize(Lr);
    return 0.0;
  } else if(*state == GAME_OVER && scoreT.read() >= ONE_SEC) {
    turnAllLedOff();
  }
  return (float)((TEN_SEC - scoreT.read())/IN_SECOND);
}