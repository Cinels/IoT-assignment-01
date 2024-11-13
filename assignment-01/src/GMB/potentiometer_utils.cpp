#include "potentiometer_utils.h"

int potentiometerMapRead(int pin, int min, int max) {
  int sensorValue = analogRead(pin);
  int outputValue = map(sensorValue, 0, 1023, min, max + 1); 
  return outputValue;
} 