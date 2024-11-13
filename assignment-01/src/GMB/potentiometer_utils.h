#ifndef _POTENTIOMETER_UTILS_
#define _POTENTIOMETER_UTILS_

#include <Arduino.h>

#define POT A0

int potentiometerMapRead(int pin, int min, int max);

#endif