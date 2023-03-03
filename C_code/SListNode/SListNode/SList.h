#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDataType;
typedef struct SListNode {
	SLTDataType data;//数据域
	struct SListNode* next;//指针域
}SLTNode;

//链表的打印
void SLTPrint(SLTNode* phead);
//链表新结点的创建
SLTNode* SLTBuyNode(SLTDataType x);
//链表新结点的头插
void SLTNodePushFront(SLTNode** pphead, SLTDataType x);
//链表新结点的尾插
void SLTNodePushBack(SLTNode** pphead, SLTDataType x);
//链表新结点的头删
void SLTNodePopFront(SLTNode** pphead);
//链表新结点的尾删
void STLNodePopBack(SLTNode** pphead);
//链表的查找——为插入和删除服务
SLTNode* SLTNodeFind(SLTNode* phead, SLTDataType x);
//链表新结点的插入
void SLTNodeInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//链表结点的删除
void SLTNodeErase(SLTNode** pphead, SLTNode* pos);