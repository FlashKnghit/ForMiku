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
//	PeoInfo data[MAX];//最大数据个数
//	int sz;//有效数据个数
//}Contact;

//初始化通讯录
void InitContact(Contact* pc);
//添加联系人
void AddContact(Contact* pc);
//打印通讯录 
void ShowContact(const Contact* pc);
//删除联系人
void DeleteContact(Contact* pc);
//查找联系人
void SearchContact(Contact* pc);
//修改联系人
void ModifyContact(Contact* pc);
//排序
void SortContact(Contact* pc);
//检查是否存满
int CheckCapacity(Contact* pc);
//保存数据到文件
void SaveContact(Contact* pc);
//加载文件
void LoadContact(Contact* pc);