#include "lcd_utils.h"
#include <LiquidCrystal_I2C.h>

#define WELCOME_POSITION 2, 0
#define START_POSITION 8, 1
#define INFO_POSITION 0, 1
#define SCORE_POSITION 5, 3

#define WELCOME_MESSAGE "Welcome to GMB!"
#define START_MESSAGE "Press B1 to Start"
#define BEGIN_MESSAGE "Go!"
#define PLAY_MESSAGE "Number:"
#define SCORE_MESSAGE "GOOD!"
#define SCORE_MESSAGE_2 "Score:"
#define GAME_OVER_MESSAGE "Game Over!"
#define FINAL_SCORE_MESSAGE "Final Score:"
#define SLEEP_MESSAGE "Press ANY button"
#define SLEEP_MESSAGE_2 "to Awake"

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4); 

void lcdSetup() {
  lcd.init();
  lcd.clear();
}

void printLcd(int x, int y, char* text) {
  lcd.setCursor(x, y);
  lcd.print(text);
}

void startScreen() {
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print(WELCOME_MESSAGE);
  lcd.setCursor(1, 2);
  lcd.print(START_MESSAGE);
}

void beginScreen() {
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(8, 1);
  lcd.print(BEGIN_MESSAGE);
}

void playScreen() {
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(4, 1);
  lcd.print(PLAY_MESSAGE);
}

void scoreScreen() {
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(7, 1);
  lcd.print(SCORE_MESSAGE);
  lcd.setCursor(0, 3);
  lcd.print(SCORE_MESSAGE_2);
}

void gameOverScreen() {
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(4, 1);
  lcd.print(GAME_OVER_MESSAGE);
  lcd.setCursor(0, 3);
  lcd.print(FINAL_SCORE_MESSAGE);
}

void sleepScreen() {
  lcd.clear();
  lcd.noBacklight();
  lcd.setCursor(2, 0);
  lcd.print(WELCOME_MESSAGE);
  lcd.setCursor(1, 2);
  lcd.print(SLEEP_MESSAGE);
  lcd.setCursor(5, 3);
  lcd.print(SLEEP_MESSAGE_2);
}