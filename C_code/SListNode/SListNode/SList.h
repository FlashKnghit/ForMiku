#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDataType;
typedef struct SListNode {
	SLTDataType data;//������
	struct SListNode* next;//ָ����
}SLTNode;

//����Ĵ�ӡ
void SLTPrint(SLTNode* phead);
//�����½��Ĵ���
SLTNode* SLTBuyNode(SLTDataType x);
//�����½���ͷ��
void SLTNodePushFront(SLTNode** pphead, SLTDataType x);
//�����½���β��
void SLTNodePushBack(SLTNode** pphead, SLTDataType x);
//�����½���ͷɾ
void SLTNodePopFront(SLTNode** pphead);
//�����½���βɾ
void STLNodePopBack(SLTNode** pphead);
//����Ĳ��ҡ���Ϊ�����ɾ������
SLTNode* SLTNodeFind(SLTNode* phead, SLTDataType x);
//�����½��Ĳ���
void SLTNodeInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//�������ɾ��
void SLTNodeErase(SLTNode** pphead, SLTNode* pos);