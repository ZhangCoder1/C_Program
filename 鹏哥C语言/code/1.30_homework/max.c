#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//求10个数中最大整数
int main()
{
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		printf("请输入第%d个数>", i+1);
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] > arr[i + 1])
			arr[i + 1] = arr[i];
	}
	printf("最大数为%d", arr[9]);
	return 0;
}