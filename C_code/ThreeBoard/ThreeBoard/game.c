#include "game.h"

//��ʼ������
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
//��ӡ����
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
//�������
void Playermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("������Ҫ�µ�����>:");
		scanf("%d%d", &x, &y);
		if (board[x-1][y-1] == ' ' && x>=1 && x<=3 && y>=1 && y<=3)
		{
			board[x-1][y-1] = '*';
			break;
		}
		else printf("���������������������룡\n");
	}
}
//��������
void Computermove(char board[ROW][COL], int row, int col)
{
	printf("����������......\n");
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
//�ж������Ƿ�Ϊ��
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
//�ж���Ӯ
char Iswin(char board[ROW][COL], int row, int col)
{
	int x,y;
	//���Ƿ�һ��
	for (x = 0; x < row; x++)
	{
		if (board[x][0] == board[x][1] && board[x][1] == board[x][2])
		{
			return board[x][1];
		}
	}
	//���Ƿ�һ��
	for (y = 0; y < col; y++)
	{
		if (board[0][y] == board[1][y] && board[1][y] == board[2][y])
		{
			return board[1][y];
		}
	}
	//�Խ����Ƿ�һ��
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return board[1][1];
	}
	//�ж��Ƿ�Ϊƽ��
	if (Isfull(board, row, col))
	{
		return 'p';
	}
	//������������ǣ���Ϸ����
	else return 0;
}
//��ӡ˭��˭Ӯ
int checkwin(char board[ROW][COL], int row, int col)
{
	char ret = Iswin(board, ROW, COL);
	if (ret == '*')
	{
		printf("���ʤ����\n");
		return 1;
	}
	else if (ret == '#')
	{
		printf("����ʤ����\n");
		return 1;
	}
	else if (ret == 'p')
	{
		printf("����ƽ�֣�\n");
		return 1;
	}
	return 0;
}