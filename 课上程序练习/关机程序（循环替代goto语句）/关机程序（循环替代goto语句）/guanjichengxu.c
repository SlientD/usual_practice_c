#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[20] = { 0 };
	system("shutdown -s -t 10000");
	printf("�����룺���������� ��ȡ���ػ�\n");


	while (1)
	{
		scanf("%s", a);
		if (strcmp(a, "����������") == 0)
		{
			system("shutdown -a");
			break;
		}
		else printf("��������\n");
	}


	return 0;
}
//int main()
//{
//	char a[20] = { 0 };
//	system("shutdown -s -t 10000");
//agin:	printf("�����룺���������� ��ȡ���ػ�\n");
//
//	scanf("%s", a);
//	if (strcmp(a, "����������")==0)
//		system("shutdown -a");
//	else{
//		printf("��������\n");
//		goto agin;
//	}
//
//	
//	return 0;
//}