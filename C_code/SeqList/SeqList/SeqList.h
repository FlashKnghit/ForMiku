#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;
typedef struct SeqList {
	SLDataType* n;//˳�������ݱ�ͷ
	int size;//��ʾ˳���ǰ��Ч����
	int capacity;//��ʾ˳�����������
}SL;
//��ʼ��˳���
void SeqListInit(SL* ps);
//���˳�������
void SeqListCheckCapacity(SL* ps);
//˳����ͷβ������ɾ��
void SeqListPopFront(SL* ps);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPushBack(SL* ps, SLDataType x);
//˳���Ĵ�ӡ
void SeqListPrint(SL* ps);
//˳���Ĳ�����ɾ�������
void SeqListInsert(SL* ps, SLDataType x, int pos);
void SeqListErase(SL* ps, int pos);
int SeqListFind(SL* ps, SLDataType x);