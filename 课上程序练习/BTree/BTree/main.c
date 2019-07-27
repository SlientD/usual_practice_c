#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
int main()
{
	//char*  x = "ABDF##K###CE#GH##I#J###";
	char*  x = "ABD##E##C##";
	BTNode * res = BinaryTreeCreate1(x);
	printf("前序:");
	BinaryPreorderTraversal(res);
	printf("\n后序:");
	BinaryPostorderTraversal(res);
	printf("\n中序:");
	BinaryInorderTraversal(res);
	printf("\n层序遍历：");
	BinaryLevelorderTraversal(res);
	printf("\n前序非递归遍历：");
	STBinaryPreorderTraversal(res);
	printf("\n中序非递归遍历：");
	STBinaryInorderTraversal(res);
	printf("\n后序非递归遍历：");
	STBinaryTreePostOrder(res);
	printf("\n判断完全二叉树：");
	printf("%d",BinaryTreeComplete(res));
	BinaryTreeDestory(res);    //要对res进行更改，因而要传他的地址 
	system("pause");
	return 0;
}