#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[20] = { 0 };
	system("shutdown -s -t 10000");
	printf("请输入：张于欣是猪 可取消关机\n");


	while (1)
	{
		scanf("%s", a);
		if (strcmp(a, "张于欣是猪") == 0)
		{
			system("shutdown -a");
			break;
		}
		else printf("别想蒙我\n");
	}


	return 0;
}
//int main()
//{
//	char a[20] = { 0 };
//	system("shutdown -s -t 10000");
//agin:	printf("请输入：张于欣是猪 可取消关机\n");
//
//	scanf("%s", a);
//	if (strcmp(a, "张于欣是猪")==0)
//		system("shutdown -a");
//	else{
//		printf("别想蒙我\n");
//		goto agin;
//	}
//
//	
//	return 0;
//}