#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Isyear(int n)
{
	return (n % 4 == 0 && n % 100 != 0 || n % 400 == 0);
}
int main()
{
	int n;
	scanf("%d", &n);
	int y = Isyear(n);
	if (y)
		printf("%d是闰年\n", n);
	else
		printf("%d不是闰年\n", n);
	return 0;
}