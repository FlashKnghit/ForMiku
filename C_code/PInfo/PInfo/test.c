#include "contact.h"
void menu()
{
	printf("******************************\n");
	printf("***     1.add    2.del     ***\n");
	printf("***     3.search 4.modify  ***\n");
	printf("***     5.show   6.sort    ***\n");
	printf("***     0.exit             ***\n");
	printf("******************************\n");

}
enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
};
int main()
{
	int input;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DeleteContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			printf("已安全退出！\n");
			break;
		default:
			printf("选择错误！\n");
			break;
		}
	} while (input);
}