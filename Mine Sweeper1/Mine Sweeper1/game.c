#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//初始化
//1.全部设置成字符0，代表都无雷
//2.全部设置成字符*，代表未扫过的地区
void InitBoard(char Board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			Board[i][j] = set;
		}
	}
}

//按格式输出排雷的数组
void DisplayBoard(char Board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//输出数组横坐标
	printf("  ");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row+1; i++)
	{
		//输出数组纵坐标
		printf("%d ", i);
		//输出数组内容
		for (j = 1; j < col+1; j++)
		{
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
}
//设置雷
void SetMine(char Board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;

	int count = easy_count;
	while (count)
	{
		x = rand() % row + 1;//横坐标1-9
		y = rand() % col + 1;//纵坐标1-9
		if (Board[x][y] == '0')
		{
			Board[x][y] = '1';
			count--;
		}
		
	}
}
//计算周围的雷数
int Count_Mine(char Mine[ROWS][COLS], int x, int y)
{
	return  Mine[x - 1][y] +
		Mine[x - 1][y - 1] +
		Mine[x][y - 1] +
		Mine[x + 1][y - 1] +
		Mine[x + 1][y] +
		Mine[x + 1][y + 1] +
		Mine[x][y + 1] +
		Mine[x - 1][y + 1] - 8 * '0';
}
//排雷
void FindMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int full = 0;
	while (full < row * col - easy_count)
	{
		printf("请输入坐标进行排雷：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (Mine[x][y] == '0')
			{
				int count = Count_Mine(Mine, x, y);
				Show[x][y] = count + '0';
				DisplayBoard(Show, row, col);
				full++;
			}
			else
			{
				printf("你被炸了！\n");
				printf("该局雷排布情况：\n");
				DisplayBoard(Mine, row, col);
				printf("你可进行下一局或者退出\n");
				break;
			}
		}
		else
		{
			printf("坐标超出范围，请重新输入！\n");
		}
	}
	if (full == row * col - easy_count)
	{
		printf("恭喜你，你赢了！\n");
		printf("该局雷排布情况：\n");
		DisplayBoard(Mine, row, col);
		printf("你可进行下一局或者退出\n");
	}
}