#include "potentiometer_utils.h"
#include "game.h"
#include "timer_utils.h"
#include "led_utils.h"
#include "button_utils.h"
#include "lcd_utils.h"

#define DEFAULT_TIME 16000
#define DEFAULT_FACTOR 0.95

states state;
difficulties difficulty, prevDifficulty;
Queue* Q;
int num;
char charNum[3];
int score;
char charScore[8];
long time;
float factor;

void gameSetup() {
  // Serial.println("START");
  state = START;
  prevDifficulty = (potentiometerMapRead(POT, 1, 4) + 1) % 4 + 1;
  Q = initialize();
  ledPinSetup();
  fadeInitialize(Lr);
  buttonPinSetup();
  buttonInterruptSetup(Q);
  lcdSetup();
  startScreen();
  srand(micros());
}

void setupInitialTime() {
  time = DEFAULT_TIME - difficulty * 1000;
  factor = -0.05 * difficulty + DEFAULT_FACTOR;
}

void setupScore() {
  score = 0;
}

void scoreIncrement() {
  score++;
}

char* getNextNum() {
  num = rand()%16;
  dtostrf(num, 2, 0, charNum);
  Serial.println(charNum);
  return charNum;
}

bool checkScore() {
  float res = 0;
  for(int i = 0; i < 4; i++) {
    res += isLedOn(i) ? pow(2, 3 - i) : 0;
  }
  return abs(num - res) < 0.001;
}

char* getScore() {
  dtostrf(score, 8, 0, charScore);
  return charScore;
}

void nextGameTime() {
  time *= factor;
}

static void start() {
  difficulty = potentiometerMapRead(POT, 1, 4);
  if(difficulty != prevDifficulty) fadeBlink(difficulty);
  prevDifficulty = difficulty;
  // Serial.print("DIFFICULTY: ");
  // Serial.println(difficulty);
  char charTime[5];
  dtostrf(sleepTimer(&state), 5, 2, charTime);
  printLcd(TIMER_POSITION, charTime);
}

static void begin() {
  scoreTimer(&state);
}

static void play() {
  char charTime[5];
  dtostrf(gameTimer(&state, time), 5, 2, charTime);
  if(state == PLAY) printLcd(TIMER_POSITION, charTime); //per non fare scrivere il tempo quando mostra il punteggio
}

static void showScore() {
  scoreTimer(&state);
}

static void gameOver() {
  overTimer(&state);
}

void executeQueueAction() {
  Node* next = getNext(Q);
  /*Serial.print("dimensione coda: ");
  Serial.println(Q->size);/**/
  if(Q->head != NULL) {
    next->func(&state, next->var);
    dequeue(Q);
  }
}

void gamePlay() {
  /*Serial.print("stato: ");
  Serial.println(state);/**/
  executeQueueAction();
  if(state == START) start();
  else if(state == BEGIN) begin();
  else if(state == PLAY) play();
  else if(state == SHOW_SCORE) showScore();
  else if(state == GAME_OVER) gameOver();
}


switch(state){
  case START: start(); break;
  case START: start(); break;
  case START: start(); break;
  case START: start(); break;
}/**/