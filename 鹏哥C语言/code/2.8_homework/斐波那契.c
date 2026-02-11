#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//递归和非递归分别实现求第n个斐波那契数
//递归实现
int fib1(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib1(n - 1) + fib1(n - 2);
}
//非递归实现
int fib2(int n)
{
	int a = 1, b = 1, c;
	if (n <= 2)
		return 1;
	else
	{
		for (int i = 3; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n",fib1(n));
	printf("%d\n",fib2(n));
	return 0;
}