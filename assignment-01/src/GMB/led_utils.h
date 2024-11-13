#ifndef _LED_UTILS_
#define _LED_UTILS_

#define Lr 3
#define L1 4
#define L2 5
#define L3 6
#define L4 7

void ledPinSetup();

void fadeBlink(int speed);

void fadeInitialize(int pin);

void lightRedLed();

void changeLedState(int pin);

void turnAllLedOff();

bool isLedOn(int pin);

#endif