#include "arthmaths.h"
#include "DyStack.h"
int IsOperator(char InputValue){
	char b=InputValue;
	return (b=='+'||b=='-'||b=='*'||b=='/'||b=='^'||b=='|'||b=='&');
}

int OperateOnLastTwo(Stack *p,char InputValue){
	int x = 0;

   int l=p->array[(p->top)-1];
   int m=p->array[(p->top)];

   	switch(InputValue){
   		case '+': x=add(l,m);break;
   		case '-': x=sub(l,m);break;
   		case '*': x=mul(l,m);break;
   		case '/': x=div(l,m);break;
        case '|': x=or(l,m);break;
        case '&': x=and(l,m);break;
   	}
   	return x;
}
