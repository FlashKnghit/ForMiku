#include "game.h"

//初始化棋盘
void Initboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void Displayboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("----");
			}
			printf("\n");
		}
	}
}
//玩家下棋
void Playermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("请输入要下的坐标>:");
		scanf("%d%d", &x, &y);
		if (board[x-1][y-1] == ' ' && x>=1 && x<=3 && y>=1 && y<=3)
		{
			board[x-1][y-1] = '*';
			break;
		}
		else printf("坐标输入有误，请重新输入！\n");
	}
}
//电脑下棋
void Computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋中......\n");
	Sleep(800);
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//判断棋盘是否为满
char Isfull(char board[ROW][COL], int row, int col)
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
//判断输赢
char Iswin(char board[ROW][COL], int row, int col)
{
	int x,y;
	//列是否一样
	for (x = 0; x < row; x++)
	{
		if (board[x][0] == board[x][1] && board[x][1] == board[x][2])
		{
			return board[x][1];
		}
	}
	//行是否一样
	for (y = 0; y < col; y++)
	{
		if (board[0][y] == board[1][y] && board[1][y] == board[2][y])
		{
			return board[1][y];
		}
	}
	//对角线是否一样
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return board[1][1];
	}
	//判断是否为平局
	if (Isfull(board, row, col))
	{
		return 'p';
	}
	//以上情况都不是，游戏继续
	else return 0;
}
//打印谁输谁赢
int checkwin(char board[ROW][COL], int row, int col)
{
	char ret = Iswin(board, ROW, COL);
	if (ret == '*')
	{
		printf("玩家胜利！\n");
		return 1;
	}
	else if (ret == '#')
	{
		printf("电脑胜利！\n");
		return 1;
	}
	else if (ret == 'p')
	{
		printf("本场平局！\n");
		return 1;
	}
	return 0;
}