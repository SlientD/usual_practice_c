#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _BTREE_H_
#define _BTREE_H_


#include <stdio.h>
#include <stdlib.h>
#define ENDTYPE '#'


typedef char BTreeDataType;
typedef struct BTreeNode{
	BTreeDataType data;
	struct BTreeNode* left;
	struct BTreeNode* right;
}BTreeNode;


BTreeNode* BTreeCreat(char* x);
void BTreePreOrder(BTreeNode* root);
void BTreeInOrder(BTreeNode* root);
void BTreePostOrder(BTreeNode* root);
void BTreeLevelOrder(BTreeNode* root);
void BTreePreOrderNR(BTreeNode* root);
void BTreeInOrderNR(BTreeNode* root);
//void BTreePostOrderNR(BTreeNode* root);
int BTreeIsCompete(BTreeNode* root);



#endif