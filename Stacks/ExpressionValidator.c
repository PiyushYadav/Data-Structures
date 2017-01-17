#include "DyStack.h"
#include "ExpressionValidator.h"
#include "ExpressionsOperatorRecogniser.h"

int IsValidExpression(char *expression){

	Stack *a=CreateStack(1);
	int top=0;

	while(*expression!='\0'){

		//For ()(())etc...
		if (*expression=='('||*expression=='{'||*expression=='[')
		{
		push(a,*expression);
		}
		else if((*expression==')'||*expression=='}'||*expression==']') && (IsEmpty(a))){
			push(a,*expression);
		}
		else if((*expression==')' && a->array[a->top]=='(')||(*expression=='}' && a->array[a->top]=='{')||(*expression==']' && a->array[a->top]=='[')){
			pop(a);
		}
		else if(*expression==')'||*expression=='}'||*expression==']'){
			push(a,*expression);
		}
		//................//

		//For a+b+c-d....//
		if (*expression=='('||*expression==')')
		{
			//i.e. skip else part if ( or ) is encountered 
		}
		else{
			if (!IsOperator(*expression))
			{	
				top++;
			}
			else{
				top--;
			}
		}
		//................//
		expression++;
	}

	if (top==1&&a->top==-1)
	{
		PrintStack(a);
		return 1;
	}
	else{
		PrintStack(a);
		return 0;
	}

}
