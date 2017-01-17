#include <stdio.h>
#include "Headers/DoublyLinkedList.h"

void push(DLL_Node **p2pInputList,int value);
void pop(DLL_Node **p2pInputList);

int main(){

	DLL_Node *List1=CreateNode(0);
	DLL_Node **Head=&List1;
	for (int i = 1; i <= 10; i++)
	{
		push(Head,i);
	}
	PrintList(List1);
	for (int i = 1; i <= 10; i++)
	{
		pop(Head);
	}
	PrintList(List1);
	
	return 0;
}

void push(DLL_Node **p2pInputList,int value){
	InsertNode(p2pInputList,value,1);
}

void pop(DLL_Node **p2pInputList){
	DeleteNode(p2pInputList,1);
}
