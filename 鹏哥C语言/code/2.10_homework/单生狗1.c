#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//在一个整型数组中，只有一个数字出现一次，其他数组都是成对出现的，请找出那个只出现一次的数字
int findSingle(int arr[], int size) {
	int result = 0;
	for (int i = 0; i < size; i++) {
		result ^= arr[i]; 
	}
	return result;
}
int main() {
	int arr[] = { 2, 3, 5, 4, 5, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int singleNumber = findSingle(arr, size);
	printf("The single number is: %d\n", singleNumber);
	return 0;
}