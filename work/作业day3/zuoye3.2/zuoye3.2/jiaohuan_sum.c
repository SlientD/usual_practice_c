#include <stdio.h>
#include <stdlib.h>
int main(){
	int i;
	double t = 1,sum = 0;
	for (i = 1; i <= 100; i++)
	{
		sum = sum+t/i;
		t =-t;
	}

	printf("%f\n", sum);
	system("pause");
	return 0;
}
#if 0        //���δ���ʧЧ
������������
0000
#endif