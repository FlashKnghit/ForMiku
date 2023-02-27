#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
//³õÊ¼»¯ÆåÅÌ
void Initboard(char board[ROW][COL], int row, int col);
//´òÓ¡ÆåÅÌ
void Displayboard(char board[ROW][COL], int row, int col);
//Íæ¼ÒÏÂÆå
void Playermove(char board[ROW][COL], int row, int col);
//µçÄÔÏÂÆå
void Computermove(char board[ROW][COL], int row, int col);
//ÅĞ¶ÏÆåÅÌÊÇ·ñÏÂÂú
char Isfull(char board[ROW][COL], int row, int col);
//ÅĞ¶ÏË­ÊäË­Ó®
char Iswin(char board[ROW][COL], int row, int col);
//´òÓ¡Ë­ÊäË­Ó®
int checkwin(char board[ROW][COL], int row, int col);