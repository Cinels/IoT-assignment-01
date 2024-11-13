#define EI_ARDUINO_INTERRUPTED_PIN
//#include "state_utils.h"
// #include "device_utils.h"
#include <EnableInterrupt.h>
#include "Timer.h"

#define L1 4
#define L2 5
#define L3 6
#define L4 7
#define Lr 3

#define B1 8
#define B2 9
#define B3 10
#define B4 11

#define POT A0

Timer timer;

void b1() {
  Serial.println("B1");
}

void b2() {
  Serial.println("B2");
}

void b3() {
  Serial.println("B3");
}

void b4() {
  Serial.println("B4");
}

void b() {
  char text[] = {'B', 'X'};
  if(arduinoInterruptedPin == B1) text[1] = '1';
  else if(arduinoInterruptedPin == B2) text[1] = '2';
  else if(arduinoInterruptedPin == B3) text[1] = '3';
  else if(arduinoInterruptedPin == B4) text[1] = '4';
  else text[1] = 'R';
  Serial.println(text);
}

void setup() {
  // state = START;
  // currIntensity = 0;
  // fadeAmount = 5;
  // fadeTime = 15;
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
  pinMode(B3, INPUT);
  pinMode(B4, INPUT);
  pinMode(Lr, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  Serial.begin(9600);
  enableInterrupt(B1, b, FALLING);
  enableInterrupt(B2, b, FALLING);
  enableInterrupt(B3, b, FALLING);
  enableInterrupt(B4, b, FALLING);

  double n = 456321.7651234; 
  // char str[100]; 
  // String(n, 4);
  Serial.println(String(n, 4));

}

void loop() {
}