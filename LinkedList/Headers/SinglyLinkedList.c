#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

SLL_Node *CreateNode(int item){
	SLL_Node *temp=(SLL_Node *)malloc(sizeof(SLL_Node));
	if (temp==NULL)
	{
		printf("List Not Allocated Space.\n");
		return NULL;
	}
	else{
		temp->element=item;
		temp->next=NULL;
		return temp;
	}
}

void Insert(SLL_Node **p2pInputList,int value,int position){
	SLL_Node *temp1=*p2pInputList;
	if (temp1==NULL&&position!=1)
	{
		printf("List is Empty and wrong Input.\n");
	}
	
	else if (position==1)
	{
		SLL_Node *temp2=CreateNode(value);
		temp2->next=temp1;	//At this line if the variable temp1 contains some garbage value, it will be assigned to temp2->next which will create further complications. So, *List1 is assigned NULL beforehand.
		printf("Element Added.\n");
		*p2pInputList=temp2;
	}
	else if (position>1&&position<=SizeOfList(temp1)+1)
	{
		temp1=Traverse(temp1,position);
		SLL_Node *temp2=CreateNode(value);
		temp2->next=temp1->next;
		temp1->next=temp2;
		printf("Element Added.\n");
	}
	else{
		printf("Wrong Position Input.\n");
	}
}

void DeleteNode(SLL_Node **p2pInputList, int position){
	SLL_Node *temp=*p2pInputList;
	if (temp==NULL)
	{
		printf("List Empty.\n");
	}
	else if(position==1){
		//p2pInputList=&(temp->next); Isn't working
		*p2pInputList=temp->next;
		free(temp);
		printf("Element Deleted.\n");
	}
	else if (position>1&&position<=SizeOfList(temp)){
		temp=Traverse(temp,position);
		SLL_Node *temp2=temp->next;
		temp->next=temp->next->next;
		free(temp2);
		printf("Element Deleted.\n");
	}
	else{
		printf("Wrong input position.\n");
	}
}

void PrintList(SLL_Node *InputList){
	SLL_Node *temp=InputList;
	if (temp==NULL)
	{
		printf("List is Empty.\n");
	}
	else
	{
		while(temp!=NULL){
			printf("%d\n",temp->element);
			temp=temp->next;
		}
	}
}

SLL_Node *Traverse(SLL_Node *InputList,int position){
	SLL_Node *temp=InputList;
	if (position==1||position==2)
	{
		return temp;
	}
	else if (position>SizeOfList(InputList)+1)
	{
		printf("Bad position Input\n");
		return temp;
	}
	else{
		for (int i = 1; i <=position-2 ; i++)
		{
			temp=temp->next;
		}
		return temp;
	}
}

int SizeOfList(SLL_Node *InputList){
	int count=0;
	SLL_Node *temp=InputList;
	if (InputList==NULL)
	{
		printf("Wrong Input.\n");
	}
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}
