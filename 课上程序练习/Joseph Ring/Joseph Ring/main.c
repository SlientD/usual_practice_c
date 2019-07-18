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
	plast->next = pfront;
	cur = plast;
	for (; m > 1; m--)
	{
		for (i = 1; i < n; i++)
		{
			cur = cur->next;
		}
		SListEraseAfter(cur);
	}
	printf("%d\n", cur->date);





	system("pause");
	return 0;
}