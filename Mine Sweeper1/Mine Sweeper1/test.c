#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("******1.play   0.exit******\n");
	printf("***************************\n");
}

void game()
{
	printf("Mine Sweeper\n");
	//设置雷的数组
	char Mine[ROWS][COLS] = { 0 };
	//排雷的数组
	char Show[ROWS][COLS] = { 0 };
	//初始化数组
	InitBoard(Mine, ROWS, COLS, '0');
	InitBoard(Show, ROWS, COLS, '*');
	//输出排雷的数组
	//DisplayBoard(Mine, ROW, COL);
	DisplayBoard(Show, ROW, COL);
	//设置雷
	SetMine(Mine, ROW, COL);
	DisplayBoard(Mine, ROW, COL);
	//排雷
	FindMine(Mine, Show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入你的操作：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出程序\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}

//主函数
int main()
{
	test();
	return 0;
}