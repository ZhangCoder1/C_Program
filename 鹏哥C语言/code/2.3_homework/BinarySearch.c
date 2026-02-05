#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int bin_search(int arr[], int size, int key)
{// arr 是查找的数组
 //size是数组大小
 //key 要查找的数字
	int left = 0, right = size - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] ==key)
		{
			return mid;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return 0;
}
int main()
{
	int arr[10] = { 1,3,5,7,9,11,13,15,17,19 };
	int key, size = sizeof(arr) / sizeof(arr[0]);
	scanf("%d", &key);
	int r = bin_search(arr, size, key);
	if(r)
	{
		printf("元素%d在%d处找到", key, r);
	}
	else
	{
		printf("未找到");
	}
	return 0;
}





