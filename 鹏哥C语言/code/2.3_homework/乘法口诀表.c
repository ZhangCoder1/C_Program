#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//打印乘法口诀表，口诀表的行数和列数自己指定
//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表
void Print(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d\t", i, j, i * j);
		}
		printf("\n");
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	Print(n);
	return 0;
}