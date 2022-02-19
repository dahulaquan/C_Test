#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void welcome()
{
	printf("*********************\n");
	printf("****1.play 0.exit****\n");
	printf("*********************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化数组
	test1(board, ROW, COL);
	//输出数组
	test2(board, ROW, COL);
	while (1)
	{
		//用户输入
		test3(board, ROW, COL);
		test2(board, ROW, COL);
		//判断输赢
		ret = test5(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑输入
		test4(board, ROW, COL);
		test2(board, ROW, COL);
		//判断输赢
		ret = test5(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢！\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
	else
	{
		printf("错误！无法判断输赢！\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		welcome();
		printf("请选择你的操作：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始进入!\n");
			game();
			break;
		case 0:
			printf("正在退出!\n");
			break;
		default:
			printf("输入错误，请重新输入!\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}