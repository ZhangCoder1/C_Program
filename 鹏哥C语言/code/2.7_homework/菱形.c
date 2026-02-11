#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	for (int i = 1; i <=7; i++)
	{
		for (int j = 1; j <= 7 - i; j++) 
		{
			printf(" ");
		}
		for (int j = 1; j <= 2*i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <=i; j++)
		{
			printf(" ");
		}
		for (int j = 1; j <= 2 * (7-i )- 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}