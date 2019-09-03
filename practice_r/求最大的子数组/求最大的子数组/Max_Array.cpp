#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//��ĿҪ������һ���������飬������������Ҳ�и�����������һ����������һ�������飬������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n).
//���磺��������{1,-2,3,10,-4,7,2,-5},�����������Ϊ{3,10,-4,7,2}����������������ĺ�18

//����һ��������⣬��������������һ�����ÿ������ʼ��ӵ����ĺͣ�sum����һ�����������������ֵ��final����ֵΪ-MAX����ÿ����ӽ�final��sum�Ƚϣ���sum�������final��ֵ����������
//ʱ�临�Ӷ�O��n^2��
int MaxArray1(int *arr, int len)
{
	int sum, final = INT_MIN;
	int i,j;
	
	for (i = 0; i < len; i++)
	{
		sum = 0;
		for (j = i; j < len; j++)
		{
			sum += arr[j];
			if (final < sum)
			{
				final = sum;
			}
		}
	}
	return final;
}

//��������̰���㷨��sum�б���֮ǰ��ӵģ�final�������ս�����ӿ�ʼ����ǰ���Ӵ����Ϊ����ʱ���ͽ�sum��Ϊ0(��ǰ����Ӵ�ȫ���е����жϺ�����û�г��ָ�����Ӵ�)������ӹ����н�sum��final���Ƚϣ���sum��ֵ����finalʱ���͸���final��ֵ
//ʱ�临�Ӷ�O(N)
int MaxArray2(int *arr, int len)
{
	int sum=0, final = INT_MIN;
	int i;

	for (i = 0; i < len; i++)
	{
		sum += arr[i];
		if (sum>final)
		{
			final = sum;
		}
		if (sum < 0)
		{
			sum = 0;
		}
	}
	return final;
}

//������������+�ݹ鷨
//ʱ�临�Ӷȣ�O��nlog(n)��
int MaxArray3(int *arr, int low,int high)
{
	int  left, right, center = 0,final;
	int sum = 0, max = 0, i, mid;
	if (low == high)
	{
		return arr[low];
	}
	else if (low < high)
	{
		mid = (low + high) / 2;
		left = MaxArray3(arr, low, mid);
		right = MaxArray3(arr, mid + 1, high);
		for (i = mid; i >= low; i--)
		{
			sum += arr[i];
			if (sum>max)
			{
				max = sum;
			}
		}
		center += max;
		max = INT_MIN; sum = 0;
		for (i = mid+1; i < high; i++)
		{
			sum += arr[i];
			if (sum>max)
			{
				max = sum;
			}
		}
		center += max;
		final = left > right ? left : right;
		final = final > center ? final : center;
		return final;
	}
}


int main()
{
	int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int sum = MaxArray3(arr, 0,len-1);
	printf("The sum of max array is %d\n", sum);
	system("pause");
	return 0;

}