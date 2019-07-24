#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
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