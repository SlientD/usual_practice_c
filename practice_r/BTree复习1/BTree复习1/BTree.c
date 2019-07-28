#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
#include "Queue.h"
#include "Stack.h"
BTreeNode*  BTreeCreat(char* x)
{
	static int i = 0;
	BTreeNode* cur = (BTreeNode*)malloc(sizeof(BTreeNode));
	
	if (x[i] == ENDTYPE)
	{
		i++;
		return (BTreeNode*)0;
	}
	else{
		cur->data = x[i];
		i++;
		cur->left = BTreeCreat(x);
		cur->right = BTreeCreat(x);
	}
	return cur;
}

void BTreePreOrder(BTreeNode* root){
	if (root)
	{
		printf("%c", root->data);
		BTreePreOrder(root->left);
		BTreePreOrder(root->right);
	}
}

void BTreeInOrder(BTreeNode* root)
{
	if (root){
		BTreeInOrder(root->left);
		printf("%c", root->data);
		BTreeInOrder(root->right);
	}
}

void BTreePostOrder(BTreeNode* root)
{
	if (root){
		BTreePostOrder(root->left);
		BTreePostOrder(root->right);
		printf("%c", root->data);
	}
}

void BTreeLevelOrder(BTreeNode* root)
{
	BTreeNode* cur;
	Queue qu;
	
	QueueInit(&qu);
	QuPush(&qu, root);
	while (!QuIsEmpty(&qu))
	{
		cur = QuFront(&qu);
		printf("%c", cur->data);
		QuPop(&qu);
		if (cur->left)
		{
			QuPush(&qu, cur->left);
		}
		if (cur->right)
		{
			QuPush(&qu, cur->right);
		}
		
	}
}

void BTreePreOrderNR(BTreeNode* root){
	Stack st;
	BTreeNode* cur=root;
	StackInite(&st,3);
	
	while (cur)
	{
		for (; cur; cur = cur->left)
		{
			printf("%c", cur->data);
			if (cur->right)              //һ��Ҫ�пգ����򾡹��ǿգ�Ҳ�ᱻѹ��ȥ��ȡ������ʱ��cur����ֿգ��ͻ�����ѭ��
			{
				StackPush(&st, cur->right);    
			}
			
		}

		if (!StackIsEmpty(&st))
		{
			cur = StackFront(&st);
			StackPop(&st);
		}
	}



}

void BTreeInOrderNR(BTreeNode* root){
	Stack st;
	BTreeNode* cur=root;
	StackInite(&st,3);
	while (cur || !StackIsEmpty(&st))    //Ҫ����ջ���жϣ���curΪ��ʱ��������ջ��Ԫ�ظպ�û�������������������ջ����Ȼ���ж�����
		                                 //Ҫ����cur�жϣ���ջ��ʱ���������һ����㻹����������cur����ջ��Ԫ�ص��ҽڵ㣬Ȼ����ʱջ�ǿյġ����Զ���ȱһ����
	{
		for (; cur; cur = cur->left)
		{
			StackPush(&st, cur);
		}
		if (!StackIsEmpty(&st))
		{
			cur = StackFront(&st);
			printf("%c", cur->data);
			StackPop(&st);
			cur = cur->right;
		}
		
	}

}

//void BTreePostOrderNR(BTreeNode* root){
//	Stack st;
//	BTreeNode* cur=root;
//	int flag[32] = { 0};
//	StackInite(&st,3);
//	while (cur)
//	{
//		while (cur)
//		{
//			for (; cur; cur = cur->left)
//			{
//				StackPush(&st, cur);
//				if (cur->right)
//				{
//					StackPush(&st, cur->right);
//				}
//
//			}
//
//			if (cur->right)
//			{
//				StackPush(&st, cur->right);
//				cur = cur->right;
//			}
//
//		}
//		
//		cur = StackFront(&st);
//		printf("%c", cur->data);
//		StackPop(&st);
//		
//
//
//
//	}
//
//
//
//
//}

//int BTreeIsCompete(BTreeNode* root){
//	int flag = 0;
//	BTreeNode* cur;
//	Queue qu ;
//	QueueInit(&qu);
//	QuPush(&qu, root);
//	while ( !QuIsEmpty(&qu))
//	{
//		cur = QuFront(&qu);
//		QuPop(&qu);
//		printf("%c", cur->data);
//		
//		if (flag)
//		{
//			if (cur->left || cur->right)
//			{
//				return 0;
//			}
//			continue;
//			
//		}
//		if (cur->right&&cur->left)
//		{
//			
//				QuPush(&qu, cur->left);
//			
//				QuPush(&qu, cur->right);
//		}
//		else if (cur->right&&!cur->left)
//		{
//			return 0;
//		}
//		else if (!cur->right)
//		{
//			flag = 1;
//			if (cur->left)
//			{
//				QuPush(&qu, cur->left);
//			}
//		}
//	}
//	return 1;
//}

int BTreeIsCompete(BTreeNode* root){
	int flag = 0;
	BTreeNode* cur;
	Queue qu ;
	QueueInit(&qu);
	QuPush(&qu, root);
	while ( !QuIsEmpty(&qu))
	{
		cur = QuFront(&qu);
		QuPop(&qu);
		printf("%c", cur->data);
		if (cur->left)
			QuPush(&qu, cur->left);
		if (cur->right)
			QuPush(&qu, cur->right);
		if (flag && (cur->left || cur->right))
		{
			return 0;
		}
		if (cur->right&&!cur->left)
		{
			return 0;
		}
		if (!cur->right)
		{
			flag = 1;
		}
	}
	QuDestroy(&qu);
	return 1;
}



