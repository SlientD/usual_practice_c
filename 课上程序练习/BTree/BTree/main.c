#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
int main()
{
	char*  x = "ABD##E#H##CF##G##";

	BTNode * res = BinaryTreeCreate1(x);
	BinaryTreeDestory(&res);    //Ҫ��res���и��ģ����Ҫ�����ĵ�ַ 

	system("pause");
	return 0;
}