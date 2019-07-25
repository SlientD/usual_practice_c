#ifndef _BTREE_H_
#define _BTREE_H_
#include <stdio.h>
#include <stdlib.h>

#define	ENDTYPE '#'
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
BTNode* BinaryTreeCreate1(char * a);
void  BinaryPreorderTraversal(BTNode* root);
void  BinaryPostorderTraversal(BTNode* root);
void  BinaryInorderTraversal(BTNode* root);
void  BinaryLevelorderTraversal(BTNode* root);



#endif