#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//初始化数组
void Init(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}
//打印数组
void Print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	}
}
//反转数组
void Reverse(int arr[], int size)
{
	int mid = size / 2;
	for (int i = 0; i < mid; i++)
	{
		int temp;
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
}
int main()
{
	int arr[10];
	int size = sizeof(arr) / sizeof(arr[0]);
	Init(arr, size);
	Print(arr, size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	Reverse(arr, size);
	Print(arr, size);
}