#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//从用户输入中读取10个整数并存储在一个数组中。然后，计算并输出这些整数的平均值。
int main()
{
	int arr[10],sum=0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	double avg = sum / 10.0;
	printf("%f", avg);
	return 0;
}