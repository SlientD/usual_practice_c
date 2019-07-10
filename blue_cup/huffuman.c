#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int a[100];
	int len;
}huf;
int sum=0;
void Select_Sort(huf* Tree, int len)
{
	int i,j,k;
	for (i = 0; i < len; i++)
	{
		k = i;
		for (j = i + 1; j < len; j++)
		{
			if (Tree->a[k]>Tree->a[j])
			{
				k = j;
			}
		}
		if (k != i)
		{
			Tree->a[k] ^= Tree->a[i];
			Tree->a[i] ^= Tree->a[k];
			Tree->a[k] ^= Tree->a[i];
		}
	}	
}
void Chang(huf* Tree, int len, int n)
{
	int i;
	Tree->a[0] = n;
	for (i = 1; i < len - 1; i++)
	{
		Tree->a[i] = Tree->a[i + 1];
	}
	Tree->len--;
}
int main()
{
	huf Tree;
	int n,i;
	printf("���������Ľڵ������");
	scanf("%d", &n);
	Tree.len = n;
	printf("���������ĸ��ڵ��ֵ��");
	for (i = 0; i < Tree.len; i++)
	{
		scanf("%d", &Tree.a[i]);
	}
	for (n; n>1;n--)
	{
		Select_Sort(&Tree, Tree.len);                  //ѡ���ѡ��������Ϊÿ��ֻ�е�һ��ֵ�仯��ֻ��Ը�ֵ���в������򼴿�
		sum = sum + Tree.a[0] + Tree.a[1];
		Chang(&Tree, Tree.len, Tree.a[0] + Tree.a[1]);
	}
	printf("��ͷ��ã�");
	printf("%d\n", sum);
	

	system("pause");
	return 0;
}
