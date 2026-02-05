#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 3
//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
int main()
{
	int arr1[N], arr2[N],i;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr2[i]);
	}
	for (i = 0; i < N; i++)
	{
		int temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
	for (i = 0; i < N; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (i = 0; i < N; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}