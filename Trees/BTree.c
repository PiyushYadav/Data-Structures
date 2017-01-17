#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BTree.h"

		//Linked List Functions
//**************************************************************//
SLL_Node *CreateListNode(BTree *item){
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

void Insert(SLL_Node **p2pInputList,BTree *value,int position){
	SLL_Node *temp1=*p2pInputList;
	if (temp1==NULL&&position!=1)
	{
		printf("List is Empty and wrong Input.\n");
	}
	
	else if (position==1)
	{
		SLL_Node *temp2=CreateListNode(value);
		temp2->next=temp1;	//At this line if the variable temp1 contains some garbage value, it will be assigned to temp2->next which will create further complications. So, *List1 is assigned NULL beforehand.
		*p2pInputList=temp2;
	}
	else if (position>1&&position<=SizeOfList(temp1)+1)
	{
		temp1=Traverse(temp1,position);
		SLL_Node *temp2=CreateListNode(value);
		temp2->next=temp1->next;
		temp1->next=temp2;
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
	}
	else if (position>1&&position<=SizeOfList(temp)){
		temp=Traverse(temp,position);
		SLL_Node *temp2=temp->next;
		temp->next=temp->next->next;
		free(temp2);
	}
	else{
		printf("Wrong input position.\n");
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
//**************************************************************//

		//Queue Functions
//**************************************************************//
void Enqueue(SLL_Node **p2pInputList,BTree *value){
	SLL_Node *temp=*p2pInputList;
	Insert(p2pInputList,value,SizeOfList(temp)+1);
}

SLL_Node *Dequeue(SLL_Node **p2pInputList){
	SLL_Node *temp=*p2pInputList;
	DeleteNode(p2pInputList,1);
	return temp;
}

//**************************************************************//

			//BTree Functions
//**************************************************************//
void InsertNode(BTree **p2pInputTree,int item){

	BTree *InputTree=*p2pInputTree;
	BTree *temp=InputTree;
	BTree *temp2=NULL;

	if (InputTree==NULL)
	{
		BTree *New=CreateNode(item);
		*p2pInputTree=New;
	}
	else{
		
		while(temp!=NULL){
			if (item > (temp->element))
			{
				temp2=temp;
				temp=temp->right;
			}
			else if(item < (temp->element)){
				temp2=temp;
				temp=temp->left;
			}
			else{
				temp2=temp;
				temp=NULL;
			}
		}
		
		BTree *New=CreateNode(item);
		
		if (item > (temp2->element))
		{
			temp2->right=New;
		}
		else if(item < (temp2->element)){
			temp2->left=New;
		}
		else{
			(temp2->freq)++;
		}
	}

}

BTree *CreateNode(int x){
	BTree *New=(BTree *)malloc(sizeof(BTree));
	New->element=x;
	New->freq=1;
	New->left=NULL;
	New->right=NULL;
	return New;
}

int lev=0;
void BSTsearch(BTree **p2pInputTree,int item){
	BTree *InputTree=*p2pInputTree;
	BTree *temp = InputTree;
	if (temp==NULL)
	{
		printf("Item not found.\n");
		return ;
	}
	if (item==temp->element)
	{
		printf("Item found at height %d.\n",lev);
		return ;
	}
	if (item<(temp->element))
	{
		lev++;
		BSTsearch(&temp->left,item);
	}
	else{
		lev++;
		BSTsearch(&temp->right,item);
	}
	
}

int HeightOfTree(BTree **p2pInputTree){
	BTree *InputTree=*p2pInputTree;
	BTree *temp = InputTree;
	if (temp==NULL)
	{
		return -1;
	}
	int height;
	int lHeight=HeightOfTree(&(temp->left));
	int rHeight=HeightOfTree(&(temp->right));
	height=max(lHeight,rHeight)+1;
	return height;
}

int max(int a,int b){
	if (a>b)
	{
		return a;
	}
	else{
		return b;
	}
}

int ReturnLevel(BTree **p2pInputTree, int item){
	BTree *InputTree=*p2pInputTree;
	BTree *temp = InputTree;
	int level=0;
	while(temp!=NULL){
		if (item==temp->element)
		{
			printf("Level:%d\n",level);
			return level;
		}
		else if (item>(temp->element))
		{
			temp=temp->right;
			level++;
		}
		else{
			temp=temp->left;
			level++;
		}
	}
	printf("Item not present.\n");
	return -1;
}

void LevelOrderTraversal(BTree **p2pInputTree){
	BTree *InputTree=*p2pInputTree;
	BTree *temp = InputTree;
	if (temp==NULL)
	{
		return ;
	}
	SLL_Node *Q=CreateListNode(temp);

	while(Q!=NULL){

		for (int i = 0; i < Q->element->freq; i++)
		{
			printf("%d   ",Q->element->element);
		}
		printf("\n");

		if (Q->element->left!=NULL)
		{
			Enqueue(&Q,Q->element->left);
		}

		if (Q->element->right!=NULL)
		{
			Enqueue(&Q,Q->element->right);
		}

		Dequeue(&Q);
	}
	free(Q);
}

void PrintTree(BTree **p2pInputTree){

	BTree *InputTree=*p2pInputTree;
	BTree *temp=InputTree;

	if (temp==NULL)
	{
		return ;
	}

	BTree **tempL=&(temp->left);
	BTree **tempR=&(temp->right);
	PrintTree(tempL);
	for (int i = 0; i < temp->freq; i++)
	{
		printf("%d\n",temp->element);	//Elements printed in ascending order.
	}
	PrintTree(tempR);
}
//**************************************************************//
				
		//AVL (Adelson-Velskii and Landis) Tree Functions
//**************************************************************//
void AVLInsert(AVLTree **p2pInputTree,int item){

}

void LLRotation(AVLTree **p2pInputTree){
	AVLTree *InputTree=*p2pInputTree;
	AVLTree *temp1=InputTree;

	AVLTree *temp2=temp1->left;
	temp1->left=temp2->right;
	temp2->right=temp1;

	temp1->balanceFactor=max(HeightOfAVLTree(&(temp1->left)),HeightOfAVLTree(&(temp1->right)))+1;
	temp2->balanceFactor=max(HeightOfAVLTree(&(temp2->left)),HeightOfAVLTree(&(temp2->right)))+1;

	*p2pInputTree=temp1;
}

void RRRotation(AVLTree **p2pInputTree){
	AVLTree *InputTree=*p2pInputTree;
	AVLTree *temp1=InputTree;
	
	AVLTree *temp2=temp1->right;
	temp1->right=temp2->left;
	temp2->left=temp1;
	
	temp1->balanceFactor=max(HeightOfAVLTree(&(temp1->left)),HeightOfAVLTree(&(temp1->right)))+1;
	temp2->balanceFactor=max(HeightOfAVLTree(&(temp2->left)),HeightOfAVLTree(&(temp2->right)))+1;
	
	*p2pInputTree=temp2;
}

void LRRotation(AVLTree **p2pInputTree){
	RRRotation(&((*p2pInputTree)->left));
	LLRotation(p2pInputTree);
}

void RLRotation(AVLTree **p2pInputTree){
	LLRotation(&((*p2pInputTree)->left));
	RRRotation(p2pInputTree);
}

AVLTree *CreateAVLNode(int x){
	AVLTree *New=(AVLTree *)malloc(sizeof(AVLTree));
	New->balanceFactor=0;
	New->right=NULL;
	New->left=NULL;
	New->element=x;
	return New;
}

int HeightOfAVLTree(AVLTree **p2pInputTree){
	AVLTree *InputTree=*p2pInputTree;
	AVLTree *temp = InputTree;
	if (temp==NULL)
	{
		return -1;
	}
	int height;
	int lHeight=HeightOfAVLTree(&(temp->left));
	int rHeight=HeightOfAVLTree(&(temp->right));
	height=max(lHeight,rHeight)+1;
	return height;
}

void PrintAVLTree(AVLTree **p2pInputTree){

	AVLTree *InputTree=*p2pInputTree;
	AVLTree *temp=InputTree;

	if (temp==NULL)
	{
		return ;
	}

	AVLTree **tempL=&(temp->left);
	AVLTree **tempR=&(temp->right);

	PrintAVLTree(tempL);
	printf("%d\n",temp->element);	//Always Ascending order.
	PrintAVLTree(tempR);
}
//**************************************************************//
