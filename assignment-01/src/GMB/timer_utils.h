#ifndef _TIMER_UTILS_
#define _TIMER_UTILS_

#include "game.h"

void stopSleepTimer();

float sleepTimer(states* state);

float gameTimer(states* state, long time);

float scoreTimer(states* state);

float overTimer(states* state);

#endif