#include <stdio.h>
#include "Headers/CircularLinkedList.h"

int main()
{
	SLL_Node *List1=NULL;
	SLL_Node **Head=&List1;
	for (int i = 1; i <= 10; i++)
	{
		Insert(Head,i,i);
	}
	printf("Size of list = %d\n",SizeOfList(List1));
	PrintList(List1);

	for (int i = 1; i <= 12; i++)
	{
		DeleteNode(Head,i);
	}

	PrintList(List1);
	return 0;
}
