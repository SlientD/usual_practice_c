#define _CRT_SECURE_NO_WARNINGS 1
#include "short_distance.h"


int main()

{

	char k;

	init();

	printf("**********************************************************************\n");

	printf("*                                                                    *\n");

	printf("*                                                                    *\n");

	printf("*               欢迎使用西安工程大学临潼校区导游系统 !                   *\n");

	printf("*                                                                    *\n");

	printf("*                                                                    *\n");

	printf("**********************************************************************\n");

	printf("\n");

	while (1)

	{
		printf("请选择您想查询的信息:\n");

		printf("1.景点信息查询;\n");

		printf("2.景点最短路径查询（迪杰斯特拉算法）;\n");

		printf("3.校内景点地图查询;\n");

		printf("4.退出系统;\n");

		printf("请选择: \n");

		scanf("%c", &k);



		switch (k)

		{

		case '1':printf("景点介绍查询（请输入1-13）。\n");

			introduce(); break;


		case '2':printf("景点最短路径(迪杰斯特拉算法）查询。");

			distance(); break;

		case '3':printf("景点地图。\n");

			map(); break;

		case '4':printf("谢谢使用!\n"); exit(0);

		}

	}

	system("pause");

	return 0;

}