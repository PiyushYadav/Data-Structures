#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

DLL_Node *CreateNode(int InputValue){
	DLL_Node *temp=(DLL_Node *)malloc(sizeof(DLL_Node));
	if (temp==NULL)
	{
		printf("Memory not Allocated to the Node\n");
		return NULL;
	}
	else{
		temp->element=InputValue;
		temp->next=NULL;
		temp->prev=NULL;
		return temp;
	}

}

void InsertNode(DLL_Node **p2pInputList,int InputValue,int position){
	DLL_Node *temp1=*p2pInputList;
	if (temp1==NULL&&position!=1)
	{
		printf("List is Empty and wrong Input.\n");
	}
	
	else if (position==1)
	{
		DLL_Node *temp2=CreateNode(InputValue);
		if (temp1==NULL)
		{
		}
		else{
			temp2->next=temp1;	//At this line if the variable temp1 contains some garbage value, it will be assigned to temp2->next which will create further complications. So, *List1 is assigned NULL beforehand.
			temp1->prev=temp2;	//If temp1 is NULL then temp1->prev will have no significance. So, List1 cant be NULL;
		}
		*p2pInputList=temp2;
		printf("Element Added.\n");
	}
	else if (position>1&&position<=SizeOfList(temp1)+1)
	{
		temp1=Traverse(temp1,position);
		DLL_Node *temp2=CreateNode(InputValue);
		temp2->next=temp1->next;
		if (temp1->next==NULL)
		{
		}
		else{
			temp1->next->prev=temp2;
		}
		temp1->next=temp2;
		temp2->prev=temp1;
		printf("Element Added.\n");
	}
	else{
		printf("Wrong Position Input.\n");
	}
}

void DeleteNode(DLL_Node **p2pInputList,int position){
	DLL_Node *temp=*p2pInputList;
	if (temp==NULL)
	{
		printf("List Empty.\n");
	}
	else if(position==1){
		//p2pInputList=&(temp->next); Isn't working
		*p2pInputList=temp->next;
		if (temp->next==NULL)
		{
		}
		else{
			temp->next->prev=NULL;
		}
		free(temp);
		printf("Element Deleted.\n");
	}
	else if (position>1&&position<=SizeOfList(temp))
	{
		DLL_Node *temp2;
		temp=Traverse(temp,position);
		if (temp->next==NULL)
		{
			temp->prev=NULL;
			free(temp);
			printf("Element Deleted.\n");
		}
		else{
			temp2=temp->next;
			temp->next=temp->next->next;
			// Took me 5 hours to recognise the need of following if statement and the logical error.
			if (temp->next==NULL)
			{
			}
			else{
				temp->next->prev=temp; 
			}
			free(temp2);
			printf("Element Deleted.\n");
		}
	}
	else{
		printf("Wrong input position.\n");
	}
}

DLL_Node *Traverse(DLL_Node *InputList,int position){
	DLL_Node *temp=InputList;
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

void PrintList(DLL_Node *InputList){
	DLL_Node *temp=InputList;
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

int SizeOfList(DLL_Node *InputList){
	if (InputList==NULL)
	{
		printf("Wrong Input.\n");
		return -1;
	}
	int count=0;
	DLL_Node *temp=InputList;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;	
}
