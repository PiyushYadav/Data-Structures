#ifndef QUEUES_H
#define QUEUES_H

struct Queue
{
	int front;
	int rear;
	int capacity;
	int *array;
};

typedef struct Queue Queue;

Queue *CreateQueue(int cap);
void Dynamically_Allocate_Memory(Queue *InputQueue);
void EnQueue(Queue *InputQueue,int data);
int DeQueue(Queue *InputQueue);
int Front(Queue *InputQueue);
int QueueSize(Queue *InputQueue);
int IsFullQueue(Queue *InputQueue);
int IsEmptyQueue(Queue *InputQueue);
void PrintQueue(Queue *InputQueue);

#endif
