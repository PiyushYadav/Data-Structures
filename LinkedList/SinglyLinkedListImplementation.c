#include <stdio.h>
#include <stdlib.h>
#include "Headers/SinglyLinkedList.h"

int main()
{
	SLL_Node *List1=NULL;	//Reason to initialise *List1 is in Insert function of file SinglyLinkedList.c
	SLL_Node **Head=&List1;
	for (int i = -5; i <= 17; i++)
	{
		Insert(Head,i,i);
	}
	printf("Size of list = %d\n",SizeOfList(*Head));
	PrintList(*Head);
	DeleteNode(Head,-2);

	for (int i = -5; i <= 17; i++)
	{
		DeleteNode(Head,i);
	}
	PrintList(*Head);

	return 0;
}
