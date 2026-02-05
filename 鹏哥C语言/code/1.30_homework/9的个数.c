#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//编写程序数一下 1到 100 的所有整数中出现多少个数字9
int main()
{
	int count = 0;
	for (int i = 1; i <= 100; i++)
	{
		int n = i;
		while (n > 0)
		{
			if (n % 10 == 9)
			{
				count++;
			}
			n = n / 10;
		}
	}
	printf("%d", count);
	return 0;
}