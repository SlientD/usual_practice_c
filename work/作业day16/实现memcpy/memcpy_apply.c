#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define N 7
void* My_Memcpy(void *dest, const char *src, int count)     //count ÊÇ×Ö½ÚÊý
{
	assert(dest != NULL&&src != NULL);
	
	while (count--)
	{

		*(char *)dest = *(char *)src;
		((char*)dest)++;
		((char*)src)++;
	}
	return dest;

}

//void My_Memcpy(char *dest, const char *src, int count)
//{
//	assert(dest != NULL&&src != NULL);
//	char * ret = dest;
//	while (count--)
//	{
//		
//		*dest = *src;
//		dest++;
//		src++;
//	}
//
//}

int main()
{
	int a[N] = {1,2,3,4,5,6,7};
	int b[7] = {0};
	int i;
	//int ret = memcmp(a, b,16);         
	//printf("%d\n", ret);                 
	//memcpy(a+2,a,16);
	My_Memcpy(a+2, a, 16);
	//My_Memcpy(b, a, 16);
	for(i=0;i<N;i++)
	{
		printf("%d",a[i]);
	}

	
	system("pause");
	return 0;

}