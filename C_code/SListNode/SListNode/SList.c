#include "SList.h"
//��ӡ����
void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//����һ���½��
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode) * 1);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
//����ͷ��
void SLTNodePushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//����β��	
void SLTNodePushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = SLTBuyNode(x);
	SLTNode* cur = *pphead;
	if (cur == NULL)
	{
		//û�н��ʱ ֱ�Ӳ���
		cur = newnode;
		return;
	}
	//�н��ʱ���ҳ����һ����㣬�����������
	while (cur->next)
	{
		cur = cur->next;
	}
	//��cur->next==NULLʱ curΪ���һ����㣬��ʼβ��
	cur->next = newnode;
}
//ͷɾ
void SLTNodePopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* next = ( * pphead)->next;
	free(*pphead);//�����ڴ�й¶
	*pphead = next;
}
//βɾ
void STLNodePopBack(SLTNode** pphead)
{
	assert(*pphead);
	//���ֻ��һ��Ԫ��
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	//��ֹһ��Ԫ��
	SLTNode* cur = *pphead;
	SLTNode* prev = NULL;
	while (cur->next)
	{
		prev = cur;//ָ��ǰ��
		cur = cur->next;//ָ����
	}
	free(cur);//�ͷ����һ��Ԫ��
	cur = NULL;//curָ���ÿ�
	prev->next = NULL;//βɾ������һ��Ԫ�أ�βɾǰ�ĵ����ڶ���Ԫ�أ���next���ÿ�
}
//����Ĳ���
//��ǰһ��λ�ò���
void SLTNodeInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == pos)
	{
		newnode->next = pos;
		*pphead = newnode;
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		newnode->next = cur->next;
		cur->next = newnode;
	}
}
//�����ɾ��
void SLTNodeErase(SLTNode** pphead, SLTNode* pos)
{
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}
//����
SLTNode* SLTNodeFind(SLTNode* phead, SLTDataType x)
{
	while (phead)
	{
		if (phead->data != x)
			phead = phead->next;
		else return phead;
	}
	return NULL;
}