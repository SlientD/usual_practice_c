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
