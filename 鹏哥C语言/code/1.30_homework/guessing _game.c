#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void game()
{
	printf("请输入最大猜测次数,猜数范围a-b>\n");
	int n,a,b,num;
	scanf("%d%d%*c%d", &n, &a, &b);
	srand(time(NULL));
	int c = a + rand() % (b - a + 1);
	for (n; n>0; n--)
	{
		printf("请输入猜测数字\n");
		scanf("%d", &num);
		if (num > c)
			printf("猜大了\n");
		else if (num < c)
			printf("猜小了\n");
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}
int main()
{
	int input=0;
	do
	{
		printf("**************************\n");
		printf("**************************\n");
		printf("********* 1.Play *********\n");
		printf("********* 0.Exit *********\n");
		printf("**************************\n");
		printf("**************************\n");
		printf("请选择>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("玩游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("非法输入，请重选\n");
			break;
		}
	} while (input);
	return 0;
}