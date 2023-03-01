#include "SeqList.h"
//��ʼ������
void SeqListInit(SL* ps)
{
	ps->n = NULL;
	ps->size = ps->capacity = 0;
}
//���˳��������Ƿ�����Ϊ0
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//�����������Ϊ0����4�� ��������һ��
		SLDataType* tmp = (SLDataType*)realloc(ps->n, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail;\n");
			exit(-1);//�ռ����/����ʧ��
		}
		//�ռ����/���ٳɹ�
		ps->n = tmp;
		ps->capacity = newcapacity;
	}
}
//˳���Ĵ�ӡ
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
//˳����ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
	//���ռ��Ƿ�װ��
	SeqListCheckCapacity(ps);
	//��ʼͷ��
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->n[end + 1] = ps->n[end];
		end--;
	}
	ps->n[0] = x;
	ps->size++;
}
//˳����β��
void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	ps->n[ps->size] = x;
	ps->size++;
}
//˳����ͷɾ
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
//˳����βɾ
void SeqListPopBack(SL* ps)
{
	assert(ps && ps->size > 0);
	ps->size--;
}
//˳���Ĳ���
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
//˳����ɾ��
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
//˳���Ĳ���
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