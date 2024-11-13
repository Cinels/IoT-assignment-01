#ifndef _LCD_UTILS_
#define _LCD_UTILS_

#define TIMER_POSITION 7, 3
#define NUMBER_POSITION 12, 1
#define SCORE_POSITION 12, 3

void lcdSetup();

void printLcd(int x, int y, char* text);

void startScreen();

void beginScreen();

void playScreen();

void scoreScreen();

void gameOverScreen();

void sleepScreen();

#endif