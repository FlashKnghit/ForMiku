#include "SList.h"
//打印链表
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
//创建一个新结点
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
//结点的头插
void SLTNodePushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//结点的尾插	
void SLTNodePushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = SLTBuyNode(x);
	SLTNode* cur = *pphead;
	if (cur == NULL)
	{
		//没有结点时 直接插入
		cur = newnode;
		return;
	}
	//有结点时，找出最后一个结点，在其后面连接
	while (cur->next)
	{
		cur = cur->next;
	}
	//当cur->next==NULL时 cur为最后一个结点，开始尾插
	cur->next = newnode;
}
//头删
void SLTNodePopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* next = ( * pphead)->next;
	free(*pphead);//避免内存泄露
	*pphead = next;
}
//尾删
void STLNodePopBack(SLTNode** pphead)
{
	assert(*pphead);
	//如果只有一个元素
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	//不止一个元素
	SLTNode* cur = *pphead;
	SLTNode* prev = NULL;
	while (cur->next)
	{
		prev = cur;//指向前驱
		cur = cur->next;//指向后继
	}
	free(cur);//释放最后一个元素
	cur = NULL;//cur指针置空
	prev->next = NULL;//尾删后的最后一个元素（尾删前的倒数第二个元素）的next域置空
}
//链表的插入
//在前一个位置插入
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
//链表的删除
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
//查找
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