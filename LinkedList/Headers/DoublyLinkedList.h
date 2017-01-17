#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

struct DLL_Node
{
	int element;
	struct DLL_Node *next;
	struct DLL_Node *prev;
};

typedef struct DLL_Node DLL_Node;

DLL_Node *CreateNode(int InputValue);
void InsertNode(DLL_Node **p2pInputList,int InputValue,int position);
void DeleteNode(DLL_Node **p2pInputList,int position);
DLL_Node *Traverse(DLL_Node *InputList,int position);
void PrintList(DLL_Node *InputList);
int SizeOfList(DLL_Node *InputList);

#endif
