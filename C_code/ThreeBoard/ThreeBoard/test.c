#include "game.h"

void menu()
{
	printf("***********************\n");
	printf("*** 1.play   0.exit ***\n");
	printf("***********************\n");
}
void game()
{
	char board[ROW][COL];
	//初始化棋盘
	Initboard(board, ROW, COL);
	//打印棋盘
	Displayboard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//检查输赢
		if (checkwin(board, ROW, COL))
		{
			break;
		}
		//电脑下棋
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//检查输赢
		if (checkwin(board, ROW, COL))
		{
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//置随机数种子
	do
	{ 
		menu();
		printf("请输入您的选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新输入！\n");
		}
	} while (input);

	return 0;
}