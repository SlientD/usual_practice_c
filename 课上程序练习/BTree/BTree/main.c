#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
int main()
{
	char*  x = "AFG##Q##H##";

	BTNode * res = BinaryTreeCreate1(x);
	printf("ǰ��:");
	BinaryPreorderTraversal(res);
	printf("\n����:");
	BinaryPostorderTraversal(res);
	printf("\n����:");
	BinaryInorderTraversal(res);
	printf("\n���������");
	BinaryLevelorderTraversal(res);
	printf("\n");
	//BinaryTreeDestory(&res);    //Ҫ��res���и��ģ����Ҫ�����ĵ�ַ 
	
	system("pause");
	return 0;
}