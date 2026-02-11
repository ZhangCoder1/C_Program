#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，
//如:153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。
int Is(int n)
{
	int i = n;
	int sum = 0;
	int c = 0;
	while (i > 0)
	{
		i /= 10;
		c++;
	}
	i = n;
	while (i > 0)
	{
		int r = i % 10;
		sum += pow(r,c);
		i /= 10;
	}
	if (n == sum)
		printf("%d ", n);
}
int main()
{
	for (int i = 0; i < 100000; i++)
	{
		Is(i);
	}
}