#include "SeqList.h"

void menu()
{
	printf("***********************************\n");
	printf("*** 1.InitSeqList 2.FindSeqList ***\n");
	printf("*** 3.PushFront   4.PushBack    ***\n");
	printf("*** 5.PopFront    6.PopBack     ***\n");
	printf("*** 7.Insert      8.Erase       ***\n");
	printf("*** 9.Print       0.Exit        ***\n");
	printf("***********************************\n");
}
SLDataType option_data()
{
	SLDataType x;
	printf("Please enter the SLdata>:");
	if(scanf("%d", &x)!=EOF)
		return x;
	else
	{
		printf("Scan Fail;\n");
		exit(-1);
	}
}
int option_pos()
{
	int pos;
	printf("Please enter the pos you want to insert or erase>:");
	if (scanf("%d", &pos) != EOF)
		return pos;
	else
	{
		printf("Scan Fail;\n");
		exit(-1);
	}
}
int main()
{
	SL seqlist = { 0 };
	SL* ps = &seqlist;
	SLDataType x;
	int pos;
	int input;
	do
	{
		menu();
		printf("Please Enter Your Option>:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			SeqListInit(ps);
			break;
		case 2:
		{
			printf("Please enter the data you want to find>:");
			scanf("%d", &x);
			pos = SeqListFind(ps, x);
			if (pos != -1)
			{
				printf("The SLdata:%d 's pos is %d\n", x, pos);
			}
			else printf("Find Failed;\n");
			break;
		}
		case 3:
			x = option_data();
			SeqListPushFront(ps, x);
			break;
		case 4:
			x = option_data();
			SeqListPushBack(ps, x);
			break;
		case 5:
			SeqListPopFront(ps);
			break;
		case 6:
			SeqListPopBack(ps);
			break;
		case 7:
			x = option_data();
			pos = option_pos();
			SeqListInsert(ps, x, pos);
			break;
		case 8:
			pos = option_pos();
			SeqListErase(ps, pos);
			break;
		case 9:
			SeqListPrint(ps);
			break;
		default:
			printf("Input Error,plese re-enter;\n");
			break;
		}
	} while (input);
	return 0;
}