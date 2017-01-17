#include <stdio.h>
#include "DyStack.h"

int main(){

	printf("Enter Stack Capacity:\n");
	int n;
	scanf("%d",&n);

	Stack *_Stack1=CreateStack(1);
	printf("Enter Elements:\n");
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d",&a);
		push(_Stack1,a);
	}
	PrintStack(_Stack1);
	
	if (!size(_Stack1))
	{
	}
	else{
		printf("Size of Stack=%d\n",size(_Stack1));
	}

	if (!top(_Stack1))
	{
	}
	else{
		printf("Top Element=%d\n",top(_Stack1));
	}

	return 0;
}


/*------OUTPUT-----------/
Enter Stack Capacity:
5
Enter Elements:
1
2
Stack Doubled.
3
Stack Doubled.
4
5
Stack Doubled.
OUTPUT:
1
2
3
4
5
Size of Stack=8
Top Element=5
------------------------*/
