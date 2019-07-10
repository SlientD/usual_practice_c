#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//
////暴力解法
//void Revolve(char *a, int len)
//{
//	
//	char temp=*a;
//	char *cur=a;        //传的是地址
//	while (*(cur+1))
//	{
//		*cur = *(cur + 1);
//		cur++;
//	}
//		*cur=temp;
//	
//}
//
//
//
//int main()
//{
//	char a[100];
//	int k, len;
//	printf("输入字符串：");
//	gets(a);
//	printf("左移个数：");
//	scanf("%d", &k);
//	len = strlen(a);
//	while (k--)
//	{
//		Revolve(a,len);
//	}
//	printf("%s\n", a);
//	system("pause");
//	return 0;
//}


void revolve( char * low,char * high)
{
	assert(low != NULL&&high != NULL);
	while (low < high)
	{
		*low ^= *high;
		*high ^= *low;
		*low ^= *high;
		low++;
		high--;

	}

}



int main()
{
	char a[100];
	int k,len;
	printf("输入字符串：");
	gets(a);
	printf("左移个数：");
	scanf("%d", &k);
	len = strlen(a);
	
	revolve(a,a+k);
	revolve(a + k + 1, a + len - 1);
	revolve(a, a + len - 1);

	printf("%s\n", a);

	system("pause");
	return 0;

}











//int gys(int m, int n)
//{
//	int r;
//	while (n)
//	{
//		r = m%n;
//		m = n;
//		n = r;
//	}
//	return m;
//}
//
//
//void revolve(char *a, int k,int len)
//{
//	int m = gys(len, k);
//	int num = len / m;
//	int num = num;	
//	char temp;
//	int i,j,t;
//	for (i = 0; i < m;i++)
//	{
//		num = num;
//		t = i ;
//		j = t + k;
//		temp = a[i];
//		while (--num)
//		{
//			a[ t] = a[j];
//			t = j;
//			j = (j + k)%len;
//			
//
//		}
//		a[t] = temp;
//	}
//}
//
//
//
//int main()
//{
//	char a[100];
//	int k,len;
//	printf("输入字符串：");
//	gets(a);
//	printf("左移个数：");
//	scanf("%d", &k);
//	len = strlen(a);
//	
//	revolve(a, k,len);
//	printf("%s\n", a);
//
//	system("pause");
//	return 0;
//
//}