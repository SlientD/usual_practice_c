#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//���Ͷ��壺typedef ��һ�����������
//����typedef�����ɱ�������Ϊ�������͡�
typedef define const  ������    
//typedef int INT;
//typedef unsigned int UNIT;
//typedef int Arr[10];
//typedef int(*PFUN)[10]; //ָ�������ָ��--������ָ��
//typedef int(*PFUN)(int, int); //����ָ��





void star()
{
	printf("********************************\n");
	printf("*******     1.play      ********\n");
	printf("*******     0.exit      ********\n");
	printf("********************************\n");


}
void play()
{
	int ret = rand()%100+1;            //����1-100�����
	int guss;
	printf("�����������µ�����");
//	printf("%d\n", ret);               �鿴���������
	while (1)
	{
		scanf("%d", &guss);
		if (guss > ret)
		{
			printf("�´��ˣ�������\n");
		}
		else if (guss < ret)
		{
			printf("��С�ˣ�������\n");
		}
		     else
		    {
			printf("�¶��ˣ��ٺٺ�\n");
			break;
		     }
	}


}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));        //������ʼ������������������һ�ξ͹���
	do{
		star();                          //��ӡ��ʼ����
		printf("��Ҫ����Ϸ��\n");
		scanf("%d", &input);             //ѡ��Ҫ��Ҫ����Ϸ
		switch (input)
		{
		case 1: play(); break; 
		case 0: printf("��Ϸ����\n"); break;
		default:printf("�����������������\n"); break;
			      
		}
			
		    
	} while (input);                       //input=0ʱֱ�ӽ��������������㻹�����棬������input��Ϊ����ѭ�������ܺ�


	system("pause");
	return 0;
}