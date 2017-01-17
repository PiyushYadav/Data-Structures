#ifndef DYSTACK_H
#define DYSTACK_H
struct Stack{
	int capacity;
	int *array;
	int top;
};

typedef struct Stack Stack;

Stack *CreateStack(int cap);
void DoubleStack(Stack *InputStack);
void push(Stack *InputStack,int NewElementValue);
void pop(Stack *InputStack);
int top(Stack *InputStack);
int size(Stack *InputStack);
int IsEmpty(Stack *InputStack);
int IsFull(Stack *InputStack);
void PrintStack(Stack *InputStack);
#endif