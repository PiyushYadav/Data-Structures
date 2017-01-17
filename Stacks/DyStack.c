#include <stdio.h>
#include <stdlib.h>
#include "DyStack.h"
void push(Stack *InputStack,int NewElementValue){
	if(IsFull(InputStack)){
		DoubleStack(InputStack);
		InputStack->array[++(InputStack->top)]=NewElementValue;
	}
	else{
		InputStack->array[++(InputStack->top)]=NewElementValue;
	}

}

void pop(Stack *InputStack){
	if (IsEmpty(InputStack))
	{
		printf("Stack is Empty.\n");
	}
	else{
		--(InputStack->top);
	}
}

int top(Stack *InputStack){
	if (IsEmpty(InputStack))
	{
		printf("Stack is Empty.\n");
		return 0;
	}
	else{
		return (InputStack->array[InputStack->top]);
	}
}

int size(Stack *InputStack){
	if (IsEmpty(InputStack))
	{
		printf("Stack is Empty.\n");
		return 0;
	}
	else{
		return (InputStack->capacity);
	}
}

int IsEmpty(Stack *InputStack){
	return (InputStack->top<=-1);
}

int IsFull(Stack *InputStack){
	return (InputStack->top==(InputStack->capacity)-1);
}

void PrintStack(Stack *InputStack){
	printf("Print Stack:\n");
	if (IsEmpty(InputStack))
	{
		printf("Stack is Empty\n");
	}
	else{
		for (int j = 0; j <= InputStack->top; j++)
		{
			printf("%d\n",InputStack->array[j]);
		}
	}
}

Stack *CreateStack(int cap){
	Stack *S = (Stack *)malloc(sizeof(Stack));
	if (S==NULL)
	{
		printf("Stack Not Allocated Space.\n");
		return NULL;
	}
	S->top=-1;
	S->array=(int *)malloc(cap*sizeof(int));
	if (S->array==NULL)
	{
		printf("Stack Array Not Allocated Space.\n");
		return NULL;
	}
	S->capacity=cap;
	return S;
}

void DoubleStack(Stack *InputStack){
	int cap=InputStack->capacity;
	int arr[cap];
	for (int i = 0; i < cap; i++)
	{
		arr[i]=InputStack->array[i];
	}
	InputStack->array=(int *)malloc(2*sizeof(InputStack->array));
	InputStack->capacity=2*InputStack->capacity;
	for (int i = 0; i < cap; i++)
	{
		InputStack->array[i]=arr[i];
	}
	printf("Stack Doubled.\n");
}