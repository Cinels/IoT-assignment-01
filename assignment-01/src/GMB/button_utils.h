#ifndef _BUTTON_UTILS_
#define _BUTTON_UTILS_

#include "queue_utils.h"

#define B1 8
#define B2 9
#define B3 10
#define B4 11

void buttonPinSetup();

void buttonInterruptSetup(Queue* queue);

#endif