#include "SeqList.h"
//初始化数组
void SeqListInit(SL* ps)
{
	ps->n = NULL;
	ps->size = ps->capacity = 0;
}
//检查顺序表容量是否满或为0
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//如果数组容量为0增容4个 否则增容一倍
		SLDataType* tmp = (SLDataType*)realloc(ps->n, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail;\n");
			exit(-1);//空间调整/开辟失败
		}
		//空间调整/开辟成功
		ps->n = tmp;
		ps->capacity = newcapacity;
	}
}
//顺序表的打印
void SeqListPrint(SL* ps)
{
	system("cls");
	int i;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->n[i]);
	}
	printf("\n");
}
//顺序表的头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	//检查空间是否装满
	SeqListCheckCapacity(ps);
	//开始头插
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->n[end + 1] = ps->n[end];
		end--;
	}
	ps->n[0] = x;
	ps->size++;
}
//顺序表的尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	ps->n[ps->size] = x;
	ps->size++;
}
//顺序表的头删
void SeqListPopFront(SL* ps)
{
	assert(ps && ps->size > 0);
	int start = 1;
	while (start < ps->size)
	{
		ps->n[start - 1] = ps->n[start];
		start++;
	}
	ps->size--;
}
//顺序表的尾删
void SeqListPopBack(SL* ps)
{
	assert(ps && ps->size > 0);
	ps->size--;
}
//顺序表的插入
void SeqListInsert(SL* ps, SLDataType x, int pos)
{
	if (pos < 0 || pos > ps->size)
	{
		printf("Pos invalid;\n");
		return;
	}
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->n[end + 1] = ps->n[end];
		end--;
	}
	ps->n[pos] = x;
	ps->size++;
}
//顺序表的删除
void SeqListErase(SL* ps, int pos)
{
	assert(ps->size > 0 && pos < ps->size&& ps);
	SeqListCheckCapacity(ps);
	while (pos < ps->size - 1)
	{
		ps->n[pos] = ps->n[pos + 1];
		pos++;
	}
	ps->size--;
}
//顺序表的查找
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	int low = ps->size;
	while (low--)
	{
		if (ps->n[low] == x)
			return low;
	}
	return -1;
}