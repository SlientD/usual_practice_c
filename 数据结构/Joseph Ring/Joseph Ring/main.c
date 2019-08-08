#define _CRT_SECURE_NO_WARNINGS 1
#include "func.h"
int main()
{
	SListNode* pfront;
	SListNode* plast;
	SListNode* cur;
	//SListInit(&pfront);
	int m, n;
	int i = 0;
	printf("输入人数和号码:");
	scanf("%d%d", &m, &n);
	SListInit(&pfront);
	SListPush(&pfront, m);
	plast = pfront;
	for (i = m - 1; i > 0; i--)
	{
		SListPush(&pfront, i);
	}
	plast->next = pfront;        //变循环单链表
	cur = plast;                //保证跳两次删人，所以从-1开始 ，可以画图。当从-1开始时，第一次才满足for (i = 1; i < n; i++)这个for循环
	for (; m > 1; m--)
	{
		for (i = 1; i < n; i++)
		{
			cur = cur->next;
			printf("第%d报数%d\n", cur->date, i);
		}
		printf("%d号出\n", cur->next->date);
		SListEraseAfter(cur);
		
	}
	printf("存活的人：%d号\n", cur->date);





	system("pause");
	return 0;
}