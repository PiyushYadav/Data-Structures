#include "Queues.h"
#ifndef DOUBLYENDEDQUEUE_H
#define DOUBLYENDEDQUEUE_H
void EnqueueFromFront(Queue *InputQueue,int value);
void EnqueueFromRear(Queue *InputQueue,int value);
int DequeueFromFront(Queue *InputQueue);
int DequeueFromRear(Queue *InputQueue);
#endif