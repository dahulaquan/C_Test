#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void test1(char board[ROW][COL], int row, int col);
void test2(char board[ROW][COL], int row, int col);
void test3(char board[ROW][COL], int row, int col);
void test4(char board[ROW][COL], int row, int col);

//判断输赢
//玩家赢 - *
//电脑赢 - #
//平局   - Q
//继续   - C
char test5(char board[ROW][COL], int row, int col);