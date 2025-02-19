#define EI_ARDUINO_INTERRUPTED_PIN
#include <EnableInterrupt.h>
#include "button_utils.h"
#include "timer_utils.h"
#include "led_utils.h"
#include "lcd_utils.h"

#define OFFSET 8
#define DEBOUNCE_TIME 50

extern Queue* Q;
static long prevts = 0;
static short prevIntPin = 0;

void buttonPinSetup() {
  for(int i = 0; i < 4; i++) {
    pinMode(i + OFFSET, INPUT);
  }
}

static void buttonPressed(states* state, short button) {
  if(*state == START && button == B1) {
    // Serial.println("BEGIN");
    *state = BEGIN;
    clear(Q);
    turnAllLedOff();
    setupInitialTime();
    setupScore();
    beginScreen();
    stopSleepTimer();
    scoreTimer(state);
  } else if(*state == PLAY) {
    changeLedState(button - OFFSET);
  } else if(*state == SLEEP) {
    // Serial.println("START");
    *state = START; 
    clear(Q);
    fadeInitialize(Lr);
    startScreen();
    sleepTimer(state);
  }
}

static void buttonInterruptHandler() {
  long ts = millis();
  if (!(ts - prevts < DEBOUNCE_TIME && arduinoInterruptedPin == prevIntPin)) {
    // Serial.print("added button event in queue: ");
    // Serial.println(arduinoInterruptedPin);
    enqueue(Q, buttonPressed, arduinoInterruptedPin);
    prevts = ts; //con il controllo per il bouncing impedisco anche la pressione contemporanea dei bottoni
    prevIntPin = arduinoInterruptedPin; //così permetto la pressione contemporanea dei tasti
  }
}

void buttonInterruptSetup(Queue* queue) {
  for(int i = 0; i < 4; i++) {
    enableInterrupt(i + OFFSET, buttonInterruptHandler, FALLING);
  }
}