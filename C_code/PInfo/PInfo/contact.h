#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3
#define INC_SZ 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
typedef struct PeoInfo
{
	int age;
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data;
	int sz;
	int capacity;
}Contact, * pConctact;

//typedef struct Contact
//{
//	PeoInfo data[MAX];//������ݸ���
//	int sz;//��Ч���ݸ���
//}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//�����ϵ��
void AddContact(Contact* pc);
//��ӡͨѶ¼ 
void ShowContact(const Contact* pc);
//ɾ����ϵ��
void DeleteContact(Contact* pc);
//������ϵ��
void SearchContact(Contact* pc);
//�޸���ϵ��
void ModifyContact(Contact* pc);
//����
void SortContact(Contact* pc);
//����Ƿ����
int CheckCapacity(Contact* pc);
//�������ݵ��ļ�
void SaveContact(Contact* pc);
//�����ļ�
void LoadContact(Contact* pc);