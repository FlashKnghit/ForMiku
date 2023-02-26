#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define COUNT 10
//9X9的地雷棋盘，并放置10个雷
//初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ch);
//设置雷
void PutMine(char board[ROWS][COLS], int row, int col);
//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//排查雷
void FindMine(char show[ROWS][COLS],char mine[ROWS][COLS], int row, int col);
