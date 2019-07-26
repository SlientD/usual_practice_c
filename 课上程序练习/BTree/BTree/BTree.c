#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
#include "queue.h"
#include  "Stack.h"

//数的构建
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
//层序遍历
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


//前序遍历--非递归
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

//中序遍历--非递归
void STBinaryInorderTraversal(BTNode* root)
{
	Stack st;
	BTNode* cur = root;
	StackInit(&st);
	while (!StackIsEmpty(&st) || cur)    //当cur为空且栈为空时，循环跳出，代表树遍历完了
	{
		for (; cur; cur = cur->_left)    //1、把所有的左孩子压榨   2、以目前右孩子为根，继续将他的左孩子门压栈
		{
			StackPush(&st, cur);
		}
		if (!StackIsEmpty(&st)){
			cur = StackFront(&st);     //1、遍历完后，第一个没有左孩子的结点，就是要打印的第一个结点   2、如果右孩子为空，则取出来上一层结点（栈里的下一个）
			putchar(cur->_data);        //1、由于没有左孩子，所以打印根             
			StackPop(&st);
			cur = cur->_right;       //1、左孩子和根遍历完后遍历它的右子树。在此右结点还未进栈，存在栈为空的现象
		}
	}
	StackDestory(&st);
}

//后序遍历--非递归
//void BinaryTreePostOrderNonR(BTNode* root)
//{
//	BTNode * cur = root;
//
//	Stack st;
//	int tag[32] = { 0 };                                //左孩子遍历标签
//
//	StackInit(&st, 100);
//
//	while (cur || !StackIsEmpty(&st))
//	{
//		for (; cur; cur = cur->_left)                //类似中序，让左孩子入栈，cur为空时，代表上一次没有
//		{
//			StackPush(&st, cur);
//			tag[st.size] = 0;                        //由于入栈的是左孩子，所以这里的左孩子遍历标签置0
//		}
//		//只要上面的for执行过哪怕一次循环，这个while后半部分条件都不能进入
//		while (!StackIsEmpty(&st) && tag[st.size] == 1)    //左孩子还没遍历完成时，不能进入打印
//		{
//			cur = StackFront(&st);
//			putchar(cur->_data);
//			StackPop(&st);
//			cur = NULL;
//		}
//
//		if (!StackIsEmpty(&st))
//		{
//			tag[st.size] = 1;
//			cur = StackFront(&st)->_right;
//		}
//	}
//	StackDestory(&st);
//}
void STBinaryInorderTraversal(BTNode* root)
{
	Stack st;
	BTNode* cur = root;
	StackPush(&st, cur);
	while (!StackIsEmpty(&st)||cur)
	{
		for (; cur; cur = cur->_left)
		{
			StackPush(&st, cur);
		}
		while (StackIsEmpty(&st)){
			cur = StackFront(&st);
			putchar(cur->_data);
			StackPop(&st);
			if (cur->_right)
			{
				cur = cur->_right;       //在此右结点还未进栈，存在栈为空的现象
				break;
			}
			if (StackIsEmpty(&st))
			{
				StackDestory(&st);
				return;

			}
		}
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