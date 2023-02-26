#include "game.h"
//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ch)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ch;
		}
	}
}
//放置雷
void PutMine(char board[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		//保证x，y坐标的随机取值在1~row与1~col之内
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	//打印列坐标
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	//打印行坐标以及棋盘
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//计算当前坐标周围有几颗雷
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x + 1][y] + mine[x - 1][y] + mine[x][y - 1] + mine[x][y + 1] + mine[x - 1][y - 1] + mine[x - 1][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y + 1] - 7 * '0';
}
//排查雷
void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = row*col - COUNT;
	//棋盘的大小减去雷的数量 为正常格子的数量
	while(win)
	{ 
		printf("请输入您要排查的坐标(空格隔开)>:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					DisplayBoard(mine, row, col);
					printf("很遗憾，您被炸死了！\n");
				}
				else
				{
					show[x][y] = GetMineCount(mine, x, y);//将周围8个格子的雷的数返回出去
					DisplayBoard(show, row, col);
					win--;
					//距离胜利所需要排查的格子-1
				}
			}
			else printf("该区域已经被排查！请重新输入！\n");
		}
		else printf("坐标输入非法或越界！请重新输入！\n");
	}
	printf("恭喜您胜利了！请问选择是否继续游玩！\n");
}


//void DisplayBoard(char board[ROWS][COLS], int row, int col)
//{
//	int i, j;
//	printf(" 棋盘>:\n");
//	//打印列坐标
//	printf("   ");
//	for (i = 1; i <= row; i++)
//	{
//		printf("%d ", i);
//	}
//	printf("\n");
//	printf("  ");
//	//打上方横线
//	for (i = 0; i <= row; i++)
//	{
//		printf("--");
//	}
//	printf("\n");
//	//打印行坐标 左方竖线 以及棋盘
//	for (i = 1; i <= row; i++)
//	{
//		printf(" %d|", i);
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c ", board[i][j]);
//		}
//		//打印右方竖线
//		printf("|");
//		printf("\n");
//	}
//	printf("  ");
//	//打印下方横线
//	for (i = 0; i <= row; i++)
//	{
//		printf("--");
//	}
//	//补全右下角的缺角
//	printf("\n");
//}