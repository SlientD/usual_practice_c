#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
int main()
{
	char*  x = "ABD##E#H##CF##G##";

	BTNode * res = BinaryTreeCreate1(x);
	BinaryTreeDestory(&res);    //要对res进行更改，因而要传他的地址 

	system("pause");
	return 0;
}