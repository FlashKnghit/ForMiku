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
//9X9�ĵ������̣�������10����
//��ʼ��
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ch);
//������
void PutMine(char board[ROWS][COLS], int row, int col);
//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//�Ų���
void FindMine(char show[ROWS][COLS],char mine[ROWS][COLS], int row, int col);
