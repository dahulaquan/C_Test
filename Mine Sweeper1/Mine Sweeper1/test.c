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
	//�����׵�����
	char Mine[ROWS][COLS] = { 0 };
	//���׵�����
	char Show[ROWS][COLS] = { 0 };
	//��ʼ������
	InitBoard(Mine, ROWS, COLS, '0');
	InitBoard(Show, ROWS, COLS, '*');
	//������׵�����
	//DisplayBoard(Mine, ROW, COL);
	DisplayBoard(Show, ROW, COL);
	//������
	SetMine(Mine, ROW, COL);
	DisplayBoard(Mine, ROW, COL);
	//����
	FindMine(Mine, Show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��������Ĳ�����");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�����\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
}

//������
int main()
{
	test();
	return 0;
}