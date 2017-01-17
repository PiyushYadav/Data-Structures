#include <stdio.h>
#include "BTree.h"

int main()
{
	AVLTree **head;

	for (int i = 0; i < 100; i++)
	{
		AVLInsert(head,NULL,i);
	}

	printf("Sorted Tree is:\n");
	PrintAVLTree(head);
	printf("Height=%d\n",HeightOfAVLTree(head));
	return 0;
}
