#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char ch;
	     
	while ((ch = getchar()) != EOF)  //getchar �ķ���ֵΪʲô��int�ͣ�         EOF ��һ����=-1 ctrl+z��������     ��ѭ��ctrl+c������ѭ��
	{
		;
		if (ch >= 'A' && ch <= 'Z')       //A->65
			printf("%c", ch + 32);

		if (ch >= 'a' && ch <= 'z')      //a->97
			printf("%c", ch - 32);
		//if (ch >= '0' && ch <= '9')       //'0'->48

	}
	

	system("pause");
	return 0;
}