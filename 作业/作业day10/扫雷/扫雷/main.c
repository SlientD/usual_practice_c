#define _CRT_SECURE_NO_WARNINGS 1
#include "mine_clear.h"
int main()
{
	int select;
	
	do{
		ShowUI();
		scanf("%d", &select);
		switch (select)
		{
		case 1:Game(); break;
		case 0:printf("bey...\n"); break;
		default:printf("Please input right number:"); break;
		}
	} while (select);



	system("pause");
	return 0;
}
