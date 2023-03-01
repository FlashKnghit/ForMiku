#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;
typedef struct SeqList {
	SLDataType* n;//顺序表的数据表头
	int size;//表示顺序表当前有效数据
	int capacity;//表示顺序表的最大容量
}SL;
//初始化顺序表
void SeqListInit(SL* ps);
//检查顺序表容量
void SeqListCheckCapacity(SL* ps);
//顺序表的头尾插入与删除
void SeqListPopFront(SL* ps);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPushBack(SL* ps, SLDataType x);
//顺序表的打印
void SeqListPrint(SL* ps);
//顺序表的插入与删除与查找
void SeqListInsert(SL* ps, SLDataType x, int pos);
void SeqListErase(SL* ps, int pos);
int SeqListFind(SL* ps, SLDataType x);