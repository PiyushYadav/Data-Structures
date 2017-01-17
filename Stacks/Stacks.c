#include <stdio.h>
#include <stdlib.h>
#define Max 5

struct Stack{
	int array[Max];
	int top;
};

typedef struct Stack Stack;


void push(Stack *InputStack,int NewElementValue);
void pop(Stack *InputStack);
int top(Stack *InputStack);
int size(Stack *InputStack);
int IsEmpty(Stack *InputStack);
int IsFull(Stack *InputStack);
void PrintStack(Stack *InputStack);

int main(){

	Stack _Stack1;
	Stack *PointerTo_Stack1=&_Stack1;
	PointerTo_Stack1->top=-1;

	for (int i = 0; i < Max; i++){
		int a;
		scanf("%d",&a);
		push(PointerTo_Stack1,a);
	}
	PrintStack(PointerTo_Stack1);

	for (int i = 0; i < Max; i++){
		pop(PointerTo_Stack1);
	}
	PrintStack(PointerTo_Stack1);
	
	if (!size(PointerTo_Stack1))
	{
	}
	else{
		printf("Number of elements in Stack=%d\n",size(PointerTo_Stack1));
	}

	if (!top(PointerTo_Stack1))
	{
	}
	else{
		printf("Top Element=%d\n",top(PointerTo_Stack1));
	}

	return 0;
}

void push(Stack *InputStack,int NewElementValue){
	if(IsFull(InputStack)){
		printf("Stack is Full.\n");
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
		return ((InputStack->top)+1);
	}
}

int IsEmpty(Stack *InputStack){
	return (InputStack->top<=-1);
}

int IsFull(Stack *InputStack){
	return (InputStack->top==Max-1);
}

void PrintStack(Stack *InputStack){
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
