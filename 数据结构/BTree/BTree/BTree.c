#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
#include "queue.h"
#include  "Stack.h"

//���Ĺ���
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



//ǰ�����
void  BinaryPreorderTraversal(BTNode* root)
{
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryPreorderTraversal(root->_left);
		BinaryPreorderTraversal(root->_right);
	}
	
}

//�������
void  BinaryPostorderTraversal(BTNode* root)
{
	if (root != NULL)
	{
		BinaryPostorderTraversal(root->_left);
		BinaryPostorderTraversal(root->_right);
		printf("%c", root->_data);
		
	}
	
}

//������� 
void  BinaryInorderTraversal(BTNode* root)
{
	if (root != NULL)
	{
		BinaryInorderTraversal(root->_left);
		printf("%c", root->_data);
		BinaryInorderTraversal(root->_right);

	}
	
}

//�������
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
	/*while (!QueueIsEmpty(&qu))
	{
		BTNode*  tmp;.......
		tmp = qu.front->data;
		if (tmp->_left != NULL)
		{
			QueuePush(&qu, tmp->_left);
		}
		if (tmp->_right != NULL)
		{
			QueuePush(&qu, tmp->_right);
		}
		QueuePop(&qu);

	}*/

}




//ǰ�����--�ǵݹ�
void STBinaryPreorderTraversal(BTNode* root)
{
	Stack st;
	BTNode* cur = root;
	StackInit(&st);
	while (!StackIsEmpty(&st)||cur){
		while (cur){
			printf("%c", cur->_data);
			StackPush(&st, cur->_right);
			cur = cur->_left;
		}
		cur = StackFront(&st);
		StackPop(&st);
	}
	
}

//�������--�ǵݹ�
void STBinaryInorderTraversal(BTNode* root)
{
	Stack st;
	BTNode* cur = root;
	StackInit(&st);
	while (!StackIsEmpty(&st) || cur)    //��curΪ����ջΪ��ʱ��ѭ����������������������
	{
		for (; cur; cur = cur->_left)    //1�������е�����ѹե   2����Ŀǰ�Һ���Ϊ��������������������ѹջ
		{
			StackPush(&st, cur);
		}
		if (!StackIsEmpty(&st)){
			cur = StackFront(&st);     //1��������󣬵�һ��û�����ӵĽ�㣬����Ҫ��ӡ�ĵ�һ�����   2������Һ���Ϊ�գ���ȡ������һ���㣨ջ�����һ����
			putchar(cur->_data);        //1������û�����ӣ����Դ�ӡ��             
			StackPop(&st);
			cur = cur->_right;       //1�����Ӻ͸������������������������ڴ��ҽ�㻹δ��ջ������ջΪ�յ�����
		}
	}
	StackDestory(&st);
}
//void STBinaryInorderTraversal(BTNode* root)
//{
//	Stack st;
//	BTNode* cur = root;
//	StackPush(&st, cur);
//	while (!StackIsEmpty(&st) || cur)
//	{
//		for (; cur; cur = cur->_left)
//		{
//			StackPush(&st, cur);
//		}
//		while (StackIsEmpty(&st)){
//			cur = StackFront(&st);
//			putchar(cur->_data);
//			StackPop(&st);
//			if (cur->_right)
//			{
//				cur = cur->_right;       //�ڴ��ҽ�㻹δ��ջ������ջΪ�յ�����
//				break;
//			}
//			if (StackIsEmpty(&st))
//			{
//				StackDestory(&st);
//				return;
//
//			}
//		}
//	}
//
//}

//�������--�ǵݹ�
void STBinaryTreePostOrder(BTNode* root){
	BTNode* cur=root;
	Stack st;
	int flag[32] = { 0 };
	StackInit(&st);
	while (!StackIsEmpty(&st)||cur){
		for (; cur; cur = cur->_left)
		{
			StackPush(&st, cur);
			flag[st.size] = 0;
		}
		while (!StackIsEmpty(&st) && flag[st.size])
		{
			cur = StackFront(&st);
			printf("%c", cur->_data);
			StackPop(&st);
			cur = NULL;
		}
		if (!StackIsEmpty(&st)){
			flag[st.size] = 1;
			cur = StackFront(&st)->_right;
		}
	}
}





//�ж��ǲ��Ƕ�������������ȫ�����������������һ����һ���ڵ���������һ����һ���ڵ��������󣬺���Ľ�㲻��Ҷ�ӽ�㡣
int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, root);
	BTNode* tmp;
	int flag = 0;
	while (!QueueIsEmpty(&qu))
	{
		tmp = qu.front->data;
		QueuePop(&qu);
		if (flag == 1 && (tmp->_left || tmp->_right))
		{
			return 0;
		}
		if (tmp->_left&&tmp->_right)
		{
			
			QueuePush(&qu, tmp->_left);
			QueuePush(&qu, tmp->_right);
		}
		else if (!(tmp->_left) && tmp->_right)
		{
			return 0;
		}
		else if (!tmp->_right)
		{
			flag = 1;
			if (tmp->_left)
			{
				QueuePush(&qu, tmp->_left);
			}
		}
		
	}
	return 1;

}


//������������
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL){
		return;
	}

	BinaryTreeDestory(root->_left);
	root->_left = NULL;

	BinaryTreeDestory(root->_right);
	root->_right = NULL;


	if (root->_left == NULL && root->_right == NULL)
	{
		free(root);
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
//void BinaryTreeDestory(BTNode* root){
//	BTNode *left, *right;
//	if (root)
//	{
//		left = root->_left;
//		right = root->_right;
//		BinaryTreeDestory(left);
//		BinaryTreeDestory(right);
//		free(root);
//	}
//}