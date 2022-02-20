#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ʼ��
//1.ȫ�����ó��ַ�0����������
//2.ȫ�����ó��ַ�*������δɨ���ĵ���
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

//����ʽ������׵�����
void DisplayBoard(char Board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//������������
	printf("  ");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row+1; i++)
	{
		//�������������
		printf("%d ", i);
		//�����������
		for (j = 1; j < col+1; j++)
		{
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
}
//������
void SetMine(char Board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;

	int count = easy_count;
	while (count)
	{
		x = rand() % row + 1;//������1-9
		y = rand() % col + 1;//������1-9
		if (Board[x][y] == '0')
		{
			Board[x][y] = '1';
			count--;
		}
		
	}
}
//������Χ������
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
//����
void FindMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int full = 0;
	while (full < row * col - easy_count)
	{
		printf("����������������ף�");
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
				printf("�㱻ը�ˣ�\n");
				printf("�þ����Ų������\n");
				DisplayBoard(Mine, row, col);
				printf("��ɽ�����һ�ֻ����˳�\n");
				break;
			}
		}
		else
		{
			printf("���곬����Χ�����������룡\n");
		}
	}
	if (full == row * col - easy_count)
	{
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
		printf("�þ����Ų������\n");
		DisplayBoard(Mine, row, col);
		printf("��ɽ�����һ�ֻ����˳�\n");
	}
}