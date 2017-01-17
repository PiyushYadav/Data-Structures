#include <stdio.h>
#include <stdlib.h>
#include "Headers/DoublyLinkedList.h"

int main()
{
	DLL_Node *List1=NULL;	//Reason to initialise *List1 is in Insert function of file DoublyLinkedList.c
	DLL_Node **Head=&List1;
	int i=0;
	for (i = -10; i <= 16; i++)
	{
		InsertNode(Head,i,i);
	}
	printf("Size of list = %d\n",SizeOfList(*Head));
	PrintList(*Head);

	DeleteNode(Head,i);

	PrintList(*Head);

	DLL_Node *temp=Traverse(List1,17);
	for (int i = 0; i < 21; i++)
	{
		printf("%d\n",temp->element);
		temp=temp->prev;
		if (temp==NULL)
		{
			break;
		}
	}

	for (int i = -11; i <= 19; i++)
	{
		DeleteNode(Head,i);
	}
	PrintList(*Head);

	return 0;
}
