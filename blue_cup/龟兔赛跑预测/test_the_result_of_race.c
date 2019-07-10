#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int v1, v2, s, t, l;
	int time = 0,l1=0,l2=0;
	printf("请输入兔子和乌龟的速度：");
	scanf("%d%d", &v1, &v2);
	printf("请输入兔子会休息时领先的米数和休息的时间:");
	scanf("%d%d", &s, &t);
	printf("请输入赛跑的长度:");
	scanf("%d", &l);
	while (l1 < l&&l2 < l)
	{
		time++;
		l1 += v1;
		l2 += v2;
		if (l1 ==l2&&l1>=l)
		{
			printf("D\n");
			break;
		}
		if ((l1-l2)>=s)
		{
			l1 -= v1*t;
		}
	}
	if (l1 > l2)
	{
		printf("R\n");
	}
	else if (l1 < l2)
	{
		printf("T\n");
	}
	printf("时间：%d\n", time);
	system("pause");
	return 0;
}