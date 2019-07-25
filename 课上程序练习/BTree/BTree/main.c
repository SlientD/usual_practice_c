#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
int main()
{
	char*  x = "AFG##Q##H##";

	BTNode * res = BinaryTreeCreate1(x);
	printf("前序:");
	BinaryPreorderTraversal(res);
	printf("\n后序:");
	BinaryPostorderTraversal(res);
	printf("\n中序:");
	BinaryInorderTraversal(res);
	printf("\n层序遍历：");
	BinaryLevelorderTraversal(res);
	printf("\n");
	//BinaryTreeDestory(&res);    //要对res进行更改，因而要传他的地址 
	
	system("pause");
	return 0;
}