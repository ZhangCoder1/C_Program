#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//递归实现n的阶乘
int fac1(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * fac1(n - 1);
}
//非递归实现n的阶乘
int fac2(int n)
{
	int fac = 1;
	for (int i = 1; i <= n; i++)
		fac *= i;
	return fac;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fac1(n));
	printf("%d\n", fac2(n));
	return 0;
}