#include "Headers/SinglyLinkedList.h"

void Enqueue(SLL_Node **p2pInputList,int value);
void Dequeue(SLL_Node **p2pInputList);

int main(){
	SLL_Node *List1=NULL;
	SLL_Node **Head=&List1;
	for (int i = 1; i <=10 ; i++)
	{
		Enqueue(Head,i);
	}
	PrintList(List1);
	for (int i = 1; i <= 8; i++)
	{
		Dequeue(Head);
	}
	PrintList(List1);

	return 0;
}

void Enqueue(SLL_Node **p2pInputList,int value){
	SLL_Node *temp=*p2pInputList;
	Insert(p2pInputList,value,SizeOfList(temp)+1);
}

void Dequeue(SLL_Node **p2pInputList){
	SLL_Node *temp=*p2pInputList;
	DeleteNode(p2pInputList,1);
}
