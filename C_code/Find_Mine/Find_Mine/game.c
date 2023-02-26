#include "game.h"
//��ʼ������
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
//������
void PutMine(char board[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		//��֤x��y��������ȡֵ��1~row��1~col֮��
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	//��ӡ������
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	//��ӡ�������Լ�����
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
//���㵱ǰ������Χ�м�����
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x + 1][y] + mine[x - 1][y] + mine[x][y - 1] + mine[x][y + 1] + mine[x - 1][y - 1] + mine[x - 1][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y + 1] - 7 * '0';
}
//�Ų���
void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = row*col - COUNT;
	//���̵Ĵ�С��ȥ�׵����� Ϊ�������ӵ�����
	while(win)
	{ 
		printf("��������Ҫ�Ų������(�ո����)>:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					DisplayBoard(mine, row, col);
					printf("���ź�������ը���ˣ�\n");
				}
				else
				{
					show[x][y] = GetMineCount(mine, x, y);//����Χ8�����ӵ��׵������س�ȥ
					DisplayBoard(show, row, col);
					win--;
					//����ʤ������Ҫ�Ų�ĸ���-1
				}
			}
			else printf("�������Ѿ����Ų飡���������룡\n");
		}
		else printf("��������Ƿ���Խ�磡���������룡\n");
	}
	printf("��ϲ��ʤ���ˣ�����ѡ���Ƿ�������棡\n");
}


//void DisplayBoard(char board[ROWS][COLS], int row, int col)
//{
//	int i, j;
//	printf(" ����>:\n");
//	//��ӡ������
//	printf("   ");
//	for (i = 1; i <= row; i++)
//	{
//		printf("%d ", i);
//	}
//	printf("\n");
//	printf("  ");
//	//���Ϸ�����
//	for (i = 0; i <= row; i++)
//	{
//		printf("--");
//	}
//	printf("\n");
//	//��ӡ������ ������ �Լ�����
//	for (i = 1; i <= row; i++)
//	{
//		printf(" %d|", i);
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c ", board[i][j]);
//		}
//		//��ӡ�ҷ�����
//		printf("|");
//		printf("\n");
//	}
//	printf("  ");
//	//��ӡ�·�����
//	for (i = 0; i <= row; i++)
//	{
//		printf("--");
//	}
//	//��ȫ���½ǵ�ȱ��
//	printf("\n");
//}