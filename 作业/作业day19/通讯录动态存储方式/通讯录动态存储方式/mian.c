#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void Menu()
{
	printf("###########################\n");
	printf("#1.SHOW   2.ADD   3.DEL####\n");
	printf("#4.MOD  5.SEARCH  6SORT###\n");
	printf("#7.CLEAR  8.SAVE  9.EXIT###\n");
	printf("###########################\n");


}
int main()
{
	volatile int quit = 0;      //volatile���ױ�ؼ��֣�һ��������ɼ��������ڴ�Ŀɼ��ԡ�ʹ�䲻׼ֱ�Ӽ��ص��Ĵ�����ȡ����ֻ�����ڴ�����ء������ڴ����ֵ��Ĵ�����ֵһ��
	              //ΪʲôquitҪ�������Σ���Ϊ����һ��ʼֱ�Ӽ��ڵ��Ĵ����У��м�ı�quitֵ�ڴ��е�ֵ��Ĵ������ֵ���䣬ѭ��ͣ������
	int select = 0;
	contact_p ct;
	Lord(&ct);             //ʹct����ָ��һ���ռ䣬��Ϊct�������һ���ռ�ĵ�ַ���ı���ct��ֵ����������ַ
	while (!quit)
	{
		Menu();
		
		scanf("%d", &select);
		switch (select)
		{
		case 1:Show(ct); break;   //չʾct��ʾ�ռ����ֵ �����ı������ʾ�Ŀռ�
		case 2:ADD(&ct); break;    //���ʾ�Ŀռ������ֵ�������漰�����ݣ������ݿ��ܸı���ָ��Ŀռ䣬��������ַ
		case 3:DEL(ct); break;    //���ʾ�Ŀռ���ɾ��ֵ�������ı������ʾ�Ŀռ䣬���Ҳ��ct��ֵ
		case 4:MOD(ct); break;
		case 5:SEARCH(ct); break;
		case 6:SORT(ct); break;
		case 7:CLEAR(ct); break;
		case 8:Save(ct); break;
		case 9:quit=1; break;
		}


	}



	system("pause");
	return 0;
}