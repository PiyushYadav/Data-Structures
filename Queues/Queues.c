#include <stdio.h>
#include <stdlib.h>
#include "Queues.h"

Queue *CreateQueue(int cap){
	Queue *p=(Queue *)malloc(sizeof(Queue));
	if (p==NULL)
	{
		printf("Queue Not Allocated Memory.\n");
		return NULL;
	}
	else{
		p->front=-1;
		p->rear=-1;
		p->capacity=cap;
		p->array=(int *)malloc(cap*sizeof(int));
		if (p->array==NULL)
		{
			printf("Queue Array Not Allocated Space.\n");
			return NULL;
		}
		else{
			return p;
		}
	}
}

void Dynamically_Allocate_Memory(Queue *InputQueue){
	if (IsFullQueue(InputQueue))
	{
		int size=InputQueue->capacity;
		InputQueue->capacity=2*InputQueue->capacity;
		InputQueue->array=realloc(InputQueue->array,InputQueue->capacity);
		if (InputQueue->array==NULL)
		{
			printf("Queue Array Not Allocated Space Dynamically.\n");
			return ;
		}
		else if (InputQueue->front>InputQueue->rear)
		{			
			for (int i = 0; i <= InputQueue->rear; i++)
			{
				InputQueue->array[i+size]=InputQueue->array[i];
			}
			InputQueue->rear+=size;
		}		
	}
	else{
		printf("Queue is not full.\n");
		return ;
	}

}

void EnQueue(Queue *InputQueue,int data){
	if (IsEmptyQueue(InputQueue))
	{
		InputQueue->rear=0;
		InputQueue->front=0;
		InputQueue->array[InputQueue->rear]=data;
	}
	else if (IsFullQueue(InputQueue))
	{
		printf("Queue is Full.\n");
	}
	else if ((InputQueue->front!=0)&&(InputQueue->rear==InputQueue->capacity-1))
	{
		InputQueue->rear=0;
		InputQueue->array[InputQueue->rear]=data;
	}
	else{
		InputQueue->rear++;
		InputQueue->array[InputQueue->rear]=data;
	}
}

int DeQueue(Queue *InputQueue){
	if (IsEmptyQueue(InputQueue))
	{
		printf("Queue is Empty\n");
		return 0;
	}
	else if (InputQueue->front==InputQueue->capacity-1)
	{
		InputQueue->front=0;
		return InputQueue->array[InputQueue->capacity-1];
	}
	else{
		printf("DeQueued %d\n",InputQueue->array[InputQueue->front++]);
		if (InputQueue->rear==InputQueue->front-1)
		{
			InputQueue->front=-1;
			InputQueue->rear=-1;
		}
		return InputQueue->array[InputQueue->front];
	}
}

int Front(Queue *InputQueue){
	if (IsEmptyQueue(InputQueue))
	{
		printf("Queue is Empty.\n");
		return 0;
	}
	else{
		return InputQueue->array[InputQueue->front];
	}
}

int QueueSize(Queue *InputQueue){
	int count=0;
	if (IsEmptyQueue(InputQueue))
	{
		printf("Queue is Empty\n");
		return 0;
	}

	else if (IsFullQueue(InputQueue))
	{
		return InputQueue->capacity;
	}

	else if (InputQueue->front<InputQueue->rear)
	{
		return (InputQueue->rear-InputQueue->front+1);
	}
	else if (InputQueue->front>InputQueue->rear)
	{
		for (int i = 0; i < InputQueue->rear; i++)
		{
			count++;
		}
		for (int i = InputQueue->front; i <= InputQueue->capacity-1; i++)
		{
			count++;
		}
		return count;
	}
	else{
		return 0;
	}
}

int IsFullQueue(Queue *InputQueue){
	if (IsEmptyQueue(InputQueue))
	{
		return 0;
	}
	else if (InputQueue->front==0)
	{
		if (InputQueue->rear==InputQueue->capacity-1)
		{
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		if (InputQueue->front==InputQueue->rear+1)
		{
			return 1;
		}
		else{
			return 0;
		}
	}
}

int IsEmptyQueue(Queue *InputQueue){
	if (InputQueue->front==-1)
	{
		return 1;
	}
	else{
		return 0;
	}
}

void PrintQueue(Queue *InputQueue){
	if (InputQueue->front==-1)
	{
		printf("Queue is empty.\n");
	}
	else if (InputQueue->front==InputQueue->rear)
	{
		printf("%d\n",InputQueue->array[InputQueue->rear]);
	}

	else if (InputQueue->front<InputQueue->rear)
	{
		for (int i = InputQueue->front; i <= InputQueue->rear; i++)
		{
			printf("%d\n",InputQueue->array[i]);
		}
	}
	else{
		for (int i = InputQueue->front; i <= InputQueue->capacity-1; i++)
		{
			printf("%d\n",InputQueue->array[i]);
		}
		for (int i = 0; i <= InputQueue->rear; i++)
		{
			printf("%d\n",InputQueue->array[i]);
		}
	}
}
