#include "Headers/SinglyLinkedList.h"

void PrintNthFromLast(SLL_Node *InputList, int n);
int j=0;

int main()
{
	SLL_Node *List1=NULL;
	SLL_Node **Head=&List1;
	for (int i = 1; i <=10 ; i++)
	{
		Insert(Head,i,i);
	}
	printf("SizeOfList=%d\n",SizeOfList(List1));

	for (int i = 1; i <= 10; i++)
	{
		PrintNthFromLast(List1,i);
		j=0;	//Bug. But i caught ya.
	}

	printf("SizeOfList=%d\n",SizeOfList(List1));

	return 0;
}

void PrintNthFromLast(SLL_Node *InputList, int n){

	SLL_Node *temp=InputList;
	if (temp==NULL)
	{
		j++;
		return ;
	}
	PrintNthFromLast(temp->next,n);
	if (j!=0)
	{
		j++;
	}
	if (j==n+1)
	{
		printf("%d\n",temp->element);
	}

}