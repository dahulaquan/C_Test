#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 11
#define COLS 11
#define ROW ROWS-2
#define COL COLS-2

#define easy_count 80

void InitBoard(char Board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char Board[ROWS][COLS], int row, int col);
void SetMine(char Board[ROWS][COLS], int row, int col);
void FindMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int row, int col);