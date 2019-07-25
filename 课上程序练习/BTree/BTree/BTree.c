#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
#include "queue.h"
BTNode* BinaryTreeCreate(BTDataType* a, int n)   //只要给的字符串可以传一个树，就不需要n
{
	BTNode* cur;
	static int i = 0;
	if (a[i] == ENDTYPE)
	{
		i++;
		return NULL;
	}
	cur = (BTNode *)malloc(sizeof(BTNode));
	cur->_data = a[i];
	i++;
	cur->_left = BinaryTreeCreate(a, n);
	cur->_right = BinaryTreeCreate(a, n);
	return cur;
}
BTNode* BinaryTreeCreate1(char * a)
{
	static int i = 0;
	if (a[i] == ENDTYPE)
	{
		i++;
		return NULL;
	}
	else{
		BTNode* cur = (BTNode *)malloc(sizeof(BTNode));
		cur->_data = a[i];
		i++;
		cur->_left = BinaryTreeCreate1(a);       //后序遍历的过程完成树的创建
		cur->_right = BinaryTreeCreate1(a);
		return cur;
	}


}

//前序遍历
void  BinaryPreorderTraversal(BTNode* root)
{
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryPreorderTraversal(root->_left);
		BinaryPreorderTraversal(root->_right);
	}
	
}
//后序遍历
void  BinaryPostorderTraversal(BTNode* root)
{
	if (root != NULL)
	{
		BinaryPostorderTraversal(root->_left);
		BinaryPostorderTraversal(root->_right);
		printf("%c", root->_data);
		
	}
	
}
//中序遍历 
void  BinaryInorderTraversal(BTNode* root)
{
	if (root != NULL)
	{
		BinaryInorderTraversal(root->_left);
		printf("%c", root->_data);
		BinaryInorderTraversal(root->_right);

	}
	
}

void  BinaryLevelorderTraversal(BTNode* root){
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu,root);
	//while (qu.front)
	while (!QueueIsEmpty(&qu))
	{
		if (qu.front->data->_left != NULL)
		{
			QueuePush(&qu, qu.front->data->_left);
		}
		if (qu.front->data->_right!= NULL)
		{
			QueuePush(&qu, qu.front->data->_right);
		}
		QueuePop(&qu);
	}


}

void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL){
		return;
	}

	BinaryTreeDestory(&((*root)->_left));
	(*root)->_left = NULL;

	BinaryTreeDestory(&((*root)->_right));
	(*root)->_right = NULL;


	if ((*root)->_left == NULL && (*root)->_right == NULL)
	{
		free(*root);
		return;
	}

}
//void BinaryTreeDestory1(BTNode** root)         //错误代码
//{
//
//	if ((*root)->_left == NULL && (*root)->_right == NULL)
//	{
//		free(*root);
//		return;
//	} 
//	BinaryTreeDestory(&((*root)->_left));         //错误点：若是left无节点呢？  可加一个判断
//	(*root)->_left = NULL;
//
//	BinaryTreeDestory(&((*root)->_right));
//	(*root)->_right = NULL;
//
//
//	
//
//}