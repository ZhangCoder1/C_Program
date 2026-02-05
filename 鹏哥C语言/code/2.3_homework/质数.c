#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int IsPrime(n)
{
	int flag = 1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
int main()
{
	for (int i = 100; i <= 200; i++)
	{
		if (IsPrime(i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}