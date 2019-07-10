#define _CRT_SECURE_NO_WARNINGS 1
//���ñ�׼���е�cos(x)��fabs(x)����ʵ��arccos(x)������xȡֵ��Χ��[-1, 1]������ֵΪ[0, PI]��
//Ҫ����׼ȷ��С�����5λ��(PI = 3.1415926)
//��ʾ��Ҫ�ﵽ���̶ֳȵľ�����Ҫʹ��double���͡�
//���ݹ�ģ��Լ�� - 1 <= x <= 1, 0 <= arccos(x) <= PI��

#include <stdio.h>
#include <Windows.h>
#include <math.h>
int main()
{
	double x;
	double result;
	scanf("%lf", &x);
	double PI = atan(1) * 4;
	
	printf("%lf\n", PI);
	for (result = PI; result >= 0; result = result - 1e-5)
	{
		if (fabs(x - cos(result)) <= 1e-5)
		{
			printf("%.5lf", result);
			break;
		}
	}
	system("pause");
	return 0;

}