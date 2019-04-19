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
#if 0        //Õû¶Î´úÂëÊ§Ð§
À²À²À²À²À²À²
0000
#endif