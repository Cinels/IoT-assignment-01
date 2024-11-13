#ifndef _QUEUE_UTILS_
#define _QUEUE_UTILS_

#include "game.h"

typedef struct Node{
  struct Node *next;
  void (*func)(states* state, short var);
  short var;
} Node;

typedef struct Queue{
  Node *head;
  Node *tail;
  short size;
} Queue;

Queue* initialize();

void clear(Queue* Q);

void enqueue(Queue* Q, void(*func)(states* state, short var), short var);

void dequeue(Queue* Q);

Node* getNext(Queue* Q);

#endif