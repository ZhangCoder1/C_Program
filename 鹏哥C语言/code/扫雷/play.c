#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("********************\n");
	printf("*****1.开始游戏*****\n");
	printf("*****0.退出游戏*****\n");
	printf("********************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 }; //雷盘
	char show[ROWS][COLS] = { 0 }; //显示盘
	//初始化mine/show数组
	InitBoard(mine, ROWS, COLS, '0');//'0'
	InitBoard(show, ROWS, COLS, '*');//'*'
	//打印排查信息
	PrintBoard(show,ROW,COL);
	//布雷
	SetMine(mine, ROW, COL);
	//排雷
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand(time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
	return 0;
}