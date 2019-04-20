#define _CRT_SECURE_NO_WARNINGS 1     //#prama warning(disable:4996£¨¾¯¸æ´úÂë£©)
#include "three_chess.h"

int main()
{
	int select;  
	ShowUI();
	
	do{
		scanf("%d", &select);
		switch (select){
		case 1:
			Game();
			break;
		case 0:
			printf("bye!!\n");
			break;
		default:
			printf("please printf agin:");
			break;
		}
	} while(select);
	













	system("pause");
	return 0;



}