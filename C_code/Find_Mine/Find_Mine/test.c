#include "game.h"

//菜单
void menu()
{
	printf("****************************\n");
	printf("***** 1.play    0.exit *****\n");
	printf("****************************\n");
}
void game()
{
	//创建棋盘 用于展示和埋雷
	char show[ROWS][COLS];
	char mine[ROWS][COLS];
	//初始化棋盘
	InitBoard(show, ROWS, COLS, '*');
	InitBoard(mine, ROWS, COLS, '0');
	//放置雷
	PutMine(mine, ROW, COL);
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	//printf("\n");
	DisplayBoard(show, ROW, COL);
	//排查雷
	FindMine(show, mine, ROW,COL);
}
int main()
{
	int input = 0;
	//置随机数种子
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
	return 0;
}