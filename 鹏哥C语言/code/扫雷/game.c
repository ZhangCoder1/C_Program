#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	printf("-------扫雷-------\n");
	int i = 0;
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

static int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y + 1] + mine[x + 1][y + 1] + mine[x + 1][y] + mine[x + 1][y - 1] +
		mine[x][y - 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	{
		int x = 0;
		int y = 0;
		int win = 0;
		while (win < row * col - EASY_COUNT)
		{
			printf("请输入要排查的坐标:");
			scanf("%d%d", &x, &y);
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (show[x][y] != '*')
				{
					printf("该坐标已经被排查过，请重新输入坐标\n");
					continue;
				}
				//坐标是雷
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					PrintBoard(mine, ROW, COL);
					break;
				}
				else //不是雷，统计这个坐标周围的雷的个数
				{
					int c = GetMineCount(mine, x, y);
					show[x][y] = c + '0';
					PrintBoard(show, ROW, COL);
					win++;
				}
			}
			else
			{
				printf("坐标非法，重新输入\n");
			}
		}
		if (win == row * col - EASY_COUNT)
		{
			printf("恭喜你，排雷成功\n");
			PrintBoard(mine, ROW, COL);
		}
	}
}
