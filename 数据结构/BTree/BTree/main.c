#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
int main()
{
	//char*  x = "ABDF##K###CE#GH##I#J###";
	char*  x = "ABD##E##C##";
	BTNode * res = BinaryTreeCreate1(x);
	printf("ǰ��:");
	BinaryPreorderTraversal(res);
	printf("\n����:");
	BinaryPostorderTraversal(res);
	printf("\n����:");
	BinaryInorderTraversal(res);
	printf("\n���������");
	BinaryLevelorderTraversal(res);
	printf("\nǰ��ǵݹ������");
	STBinaryPreorderTraversal(res);
	printf("\n����ǵݹ������");
	STBinaryInorderTraversal(res);
	printf("\n����ǵݹ������");
	STBinaryTreePostOrder(res);
	printf("\n�ж���ȫ��������");
	printf("%d",BinaryTreeComplete(res));
	BinaryTreeDestory(res);    //Ҫ��res���и��ģ����Ҫ�����ĵ�ַ 
	system("pause");
	return 0;
}