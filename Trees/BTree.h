#ifndef BTREE_H
#define BTREE_H

struct BTree
{
	int element;
	int freq;
	struct BTree *right;
	struct BTree *left;
};
typedef struct BTree BTree;

struct SLL_Node
{
	BTree *element;
	struct SLL_Node *next;
};
typedef struct SLL_Node SLL_Node;

struct AVLTree
{
	int element;
	int balanceFactor;
	struct AVLTree *right;
	struct AVLTree *left;
};
typedef struct AVLTree AVLTree;

//Linked List Functions
SLL_Node *CreateListNode(BTree *item);
void Insert(SLL_Node **p2pInputList,BTree *value,int position);
void DeleteNode(SLL_Node **p2pInputList,int position);
SLL_Node *Traverse(SLL_Node *InputList,int position);
int SizeOfList(SLL_Node *InputList);

//Queue Functions
void Enqueue(SLL_Node **p2pInputList,BTree *value);
SLL_Node *Dequeue(SLL_Node **p2pInputList);

//Tree Functions
void InsertNode(BTree **p2pInputTree,int item);
BTree *CreateNode(int x);
void BSTsearch(BTree **p2pInputTree,int item);
int HeightOfTree(BTree **p2pInputTree);
int max(int a,int b);
int ReturnLevel(BTree **p2pInputTree, int item);
void LevelOrderTraversal(BTree **p2pInputTree);
void PrintTree(BTree **p2pInputTree);

//AVL (Adelson-Velskii and Landis) Tree Functions
void AVLInsert(AVLTree **p2pInputTree,AVLTree **parent,int item);
AVLTree *CreateAVLNode(int x);
void LLRotation(AVLTree **p2pInputTree);
void RRRotation(AVLTree **p2pInputTree);
void LRRotation(AVLTree **p2pInputTree);
void RLRotation(AVLTree **p2pInputTree);
int HeightOfAVLTree(AVLTree **p2pInputTree);
void PrintAVLTree(AVLTree **p2pInputTree);

#endif
