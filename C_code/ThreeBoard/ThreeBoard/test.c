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
	//��ʼ������
	Initboard(board, ROW, COL);
	//��ӡ����
	Displayboard(board, ROW, COL);
	while (1)
	{
		//�������
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//�����Ӯ
		if (checkwin(board, ROW, COL))
		{
			break;
		}
		//��������
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//�����Ӯ
		if (checkwin(board, ROW, COL))
		{
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//�����������
	do
	{ 
		menu();
		printf("����������ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ��������������룡\n");
		}
	} while (input);

	return 0;
}