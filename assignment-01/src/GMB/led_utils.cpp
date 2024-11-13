#include "led_utils.h"
#include "TimerOne.h"

#define OFFSET 4
#define SPEED 10000l

int currIntensity;
int pin;
int fadeAmount = 5;

bool led[4];

void ledPinSetup() {
  pinMode(Lr, OUTPUT);
  for(int i = 0; i < 4; i++) {
    pinMode(i + OFFSET, OUTPUT);
    led[i] = false;
  }
}

static void fade() {
  analogWrite(pin, currIntensity);
  currIntensity = currIntensity + fadeAmount;
  if (currIntensity == 0 || currIntensity == 255) fadeAmount = -fadeAmount;
}

void fadeBlink(int speedFade) {
  Timer1.initialize(SPEED/speedFade); 
}

void fadeInitialize(int pinFade) {
  pin = pinFade;
  Timer1.initialize(SPEED);
  Timer1.attachInterrupt(fade);
}

void lightRedLed() {
  currIntensity = 255;
  fadeAmount = -5;
  analogWrite(Lr, currIntensity);
}

void changeLedState(int pin) {
  // Serial.print("led ");
  // Serial.print(pin + 1);
  // Serial.print(led[pin] ? " ON -" : " OFF -");
  led[pin] = !led[pin];
  // Serial.println(led[pin] ? "> ON" : "> OFF");
  digitalWrite(pin + OFFSET, led[pin]);
}

void turnAllLedOff() {
  for(int i = 0; i < 4; i++) {
    digitalWrite(i + OFFSET, LOW);
    led[i] = false;
  }
  Timer1.detachInterrupt();
  currIntensity = 0;
  fadeAmount = 5;
  analogWrite(pin, currIntensity);
}

bool isLedOn(int pin) {
  return led[pin];
}