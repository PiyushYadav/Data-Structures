#include <stdio.h>
#include "Queues.h"
#include "DoublyEndedQueue.h"

void EnqueueFromFront(Queue *InputQueue,int value){
	
	if (InputQueue->front<=InputQueue->rear){
		if (IsFullQueue(InputQueue))
		{
			printf("Queue is Full\n");
		}
		else if (InputQueue->front==0 && InputQueue->rear<InputQueue->capacity-1)
		{
			for (int i = InputQueue->rear; i <= InputQueue->front ; i--)
			{
				InputQueue->array[i+1]=InputQueue->array[i];
			}
			InputQueue->rear++;
			InputQueue->array[InputQueue->front]=value;
		}

		else
		{
			InputQueue->array[--InputQueue->front]=value;
		}
	}
	else{
		printf("Queue is Circular.\n");
	}
}

void EnqueueFromRear(Queue *InputQueue,int value){
	
	if (InputQueue->front<=InputQueue->rear){
		if (IsFullQueue(InputQueue))
		{
			printf("Queue is Full\n");
		}
		else if (InputQueue->rear==InputQueue->capacity-1 && InputQueue->front>0)
		{
			for (int i = InputQueue->front; i <= InputQueue->rear ; i++)
			{
				InputQueue->array[i-1]=InputQueue->array[i];
			}
			InputQueue->front--;
			InputQueue->array[InputQueue->rear]=value;
		}

		else
		{
			InputQueue->array[++InputQueue->rear]=value;
		}
	}
	else{
		printf("Queue is Circular.\n");
	}
}

int DequeueFromFront(Queue *InputQueue){
	if (InputQueue->front<=InputQueue->rear)
	{
		if (IsEmptyQueue(InputQueue))
		{
			printf("Queue is Empty.\n");
			return 0;
		}
		else if(InputQueue->front==InputQueue->rear)
		{
			InputQueue->front=-1;
			return InputQueue->array[InputQueue->rear--];
		}
		else{
			return InputQueue->array[InputQueue->front++];
		}
	}
	else{
		printf("Queue is Circular.\n");
		return 0;
	}
}

int DequeueFromRear(Queue *InputQueue){
	if (InputQueue->front<=InputQueue->rear)
	{
		if (IsEmptyQueue(InputQueue))
		{
			printf("Queue is Empty.\n");
			return 0;
		}
		else if(InputQueue->front==InputQueue->rear)
		{
			InputQueue->front=-1;
			return InputQueue->array[InputQueue->rear--];
		}
		else{
			return InputQueue->array[InputQueue->rear--];
		}
	}
	else{
		printf("Queue is Circular.\n");
		return 0;
	}
}
