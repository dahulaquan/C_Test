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
	//��ʼ������
	test1(board, ROW, COL);
	//�������
	test2(board, ROW, COL);
	while (1)
	{
		//�û�����
		test3(board, ROW, COL);
		test2(board, ROW, COL);
		//�ж���Ӯ
		ret = test5(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		test4(board, ROW, COL);
		test2(board, ROW, COL);
		//�ж���Ӯ
		ret = test5(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
	else
	{
		printf("�����޷��ж���Ӯ��\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		welcome();
		printf("��ѡ����Ĳ�����");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ����!\n");
			game();
			break;
		case 0:
			printf("�����˳�!\n");
			break;
		default:
			printf("�����������������!\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}