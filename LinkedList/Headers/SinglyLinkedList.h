#include <stdio.h>
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

struct SLL_Node
{
	int element;
	struct SLL_Node *next;
};
typedef struct SLL_Node SLL_Node;

SLL_Node *CreateNode(int item);
void PrintList(SLL_Node *InputList);
void Insert(SLL_Node **p2pInputList,int value,int position);
void DeleteNode(SLL_Node **p2pInputList,int position);
SLL_Node *Traverse(SLL_Node *InputList,int position);
int SizeOfList(SLL_Node *InputList);

#endif
