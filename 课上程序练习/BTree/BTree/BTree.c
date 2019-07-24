#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
BTNode* BinaryTreeCreate(BTDataType* a, int n)   //ֻҪ�����ַ������Դ�һ�������Ͳ���Ҫn
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
		cur->_left = BinaryTreeCreate1(a);       //��������Ĺ���������Ĵ���
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
//void BinaryTreeDestory1(BTNode** root)         //�������
//{
//
//	if ((*root)->_left == NULL && (*root)->_right == NULL)
//	{
//		free(*root);
//		return;
//	} 
//	BinaryTreeDestory(&((*root)->_left));         //����㣺����left�޽ڵ��أ�  �ɼ�һ���ж�
//	(*root)->_left = NULL;
//
//	BinaryTreeDestory(&((*root)->_right));
//	(*root)->_right = NULL;
//
//
//	
//
//}