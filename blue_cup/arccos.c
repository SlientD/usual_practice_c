#define _CRT_SECURE_NO_WARNINGS 1
//利用标准库中的cos(x)和fabs(x)函数实现arccos(x)函数，x取值范围是[-1, 1]，返回值为[0, PI]。
//要求结果准确到小数点后5位。(PI = 3.1415926)
//提示：要达到这种程度的精度需要使用double类型。
//数据规模和约定 - 1 <= x <= 1, 0 <= arccos(x) <= PI。

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