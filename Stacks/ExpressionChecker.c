#include "ExpressionValidator.h"
#include <stdio.h>

int main()
{
	
	char expression[1000];
	printf("Enter the expression:\n");
	scanf("%s",expression);
	if (IsValidExpression(expression))
	{
		printf("Expression Valid.\n");
	}
	else{
		printf("Expression Invalid.\n");
	}

	return 0;
}
