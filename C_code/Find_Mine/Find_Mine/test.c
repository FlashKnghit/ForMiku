#include "game.h"

//�˵�
void menu()
{
	printf("****************************\n");
	printf("***** 1.play    0.exit *****\n");
	printf("****************************\n");
}
void game()
{
	//�������� ����չʾ������
	char show[ROWS][COLS];
	char mine[ROWS][COLS];
	//��ʼ������
	InitBoard(show, ROWS, COLS, '*');
	InitBoard(mine, ROWS, COLS, '0');
	//������
	PutMine(mine, ROW, COL);
	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	//printf("\n");
	DisplayBoard(show, ROW, COL);
	//�Ų���
	FindMine(show, mine, ROW,COL);
}
int main()
{
	int input = 0;
	//�����������
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}