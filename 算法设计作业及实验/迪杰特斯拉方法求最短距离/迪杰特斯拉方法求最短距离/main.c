#define _CRT_SECURE_NO_WARNINGS 1
#include "short_distance.h"


int main()

{

	char k;

	init();

	printf("**********************************************************************\n");

	printf("*                                                                    *\n");

	printf("*                                                                    *\n");

	printf("*               ��ӭʹ���������̴�ѧ����У������ϵͳ !                   *\n");

	printf("*                                                                    *\n");

	printf("*                                                                    *\n");

	printf("**********************************************************************\n");

	printf("\n");

	while (1)

	{
		printf("��ѡ�������ѯ����Ϣ:\n");

		printf("1.������Ϣ��ѯ;\n");

		printf("2.�������·����ѯ���Ͻ�˹�����㷨��;\n");

		printf("3.У�ھ����ͼ��ѯ;\n");

		printf("4.�˳�ϵͳ;\n");

		printf("��ѡ��: \n");

		scanf("%c", &k);



		switch (k)

		{

		case '1':printf("������ܲ�ѯ��������1-13����\n");

			introduce(); break;


		case '2':printf("�������·��(�Ͻ�˹�����㷨����ѯ��");

			distance(); break;

		case '3':printf("�����ͼ��\n");

			map(); break;

		case '4':printf("ллʹ��!\n"); exit(0);

		}

	}

	system("pause");

	return 0;

}