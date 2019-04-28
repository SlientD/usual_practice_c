#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *strcpy2(char *strDestination, const char *strSource)
{
	assert(strDestination != NULL && strSource != NULL);
	char*ret = strDestination;
	/*while (*strSource)
	{
		*strDestination = *strSource;
		strDestination++;
		strSource++;
	}
	*strDestination = '\0';*/
	while ((*strDestination++ = *strSource++)!=0);
	return ret;

}


//void my_srycyp1(char *destination, const char *source)
//{
//	assert(destination != NULL&&source != NULL);
//	int i;
//	while (*(source+i))
//	{
//		*(destination + i) = *(source + i);
//		i++;
//	}
//	*(destination + i) = '\0';
//}

int main()
{
	char *a = "abcdef";
	char b[5]="abcde";
	strcpy2(b, a);
	//my_srycyp1(b, a);
	//strcpy(b,a);
	printf("%s\n", b);
	//printf("%c", b[4]);


	system("pause");
	return 0;
}