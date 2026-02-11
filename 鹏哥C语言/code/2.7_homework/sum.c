#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字
int main()
{
	int i = 0;
	scanf("%d", &i);
	int sum = 0;
	int term = 0; 
	for (int k = 0; k < 5; ++k) {
		term = term * 10 + i;
		sum += term;
	}
	printf("%d\n", sum);
	return 0;
}