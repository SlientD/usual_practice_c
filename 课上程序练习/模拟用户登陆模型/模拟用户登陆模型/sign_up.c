#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	//char password[20];
	//printf("%d\n", &password);   //Ԫ���ַ
	//printf("%d", password);      //Ԫ���׵�ַ


	int i = 0;
	char password[20] = { 0 };   //����û�г�ʼ���������ֵ
	printf("������������룺");
	for (i = 0; i < 3; i++)
	{
		scanf("%s", password);//password�Ǵ����׵�ַ��&password��ʾ������׵�ַ
		if ((strcmp(password, "123456")) == 0)  //strcmp �ַ����ȽϺ����������ַ�����ȷ���0��ǰ�ߴ��ں��߷��ش���0���������ߴ���ǰ�߷���С��0����
		{
			printf("��½�ɹ�\n");
			break;
		}
		else printf("���������������������\n");

	}
	if (i == 3)
		printf("�����������������˳���½ϵͳ\n");

	system("pause");
	return 0;
}