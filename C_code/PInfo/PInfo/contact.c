#include "contact.h"
//初始化
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
// 动态版本：
void LoadContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
}

void InitContact(Contact* pc)
{
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->data == NULL)
		printf("初始化失败！>:%s\n", strerror(errno));
	LoadContact(pc);
}
//销毁通讯录
void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
}
//检测容量
int CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("扩容失败！>:%s\n", strerror(errno));
			return 0;
		}
		pc->data = ptr;
		pc->capacity += INC_SZ;
		return 1;
	}
}
//增加指定联系人
void AddContact(Contact* pc)
{
	//if (pc->sz == MAX)
	//{
	//	printf("通讯录已满,无法增加\n");
	//	return;
	//}
	//动态：
	if (CheckCapacity(pc) == 0)
	{
		printf("扩容失败！\n");
		return;
	}
	printf("请输入名字>:");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄>:");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别>:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话>:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址>:");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("添加成功！\n");
}
//显示联系人信息
void ShowContact(const Contact* pc)
{
	//格式化打印 左对齐
	printf("%-10s%-6s%-6s%-12s%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-10s%-4d%-5s%-12s%-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex,
			pc->data[i].tele, pc->data[i].addr);
	}
}
//删除联系人
void DeleteContact(Contact* pc)
{
	char name[20];
	if (pc->sz == 0)
	{
		printf("通讯录为空！\n");
		return;
	}
	printf("请输入删除名字>：");
	scanf("%s", name);
	int pos = FindByName(pc ,name);
	if (pos == -1)
	{
		printf("需要删除的数据不存在！\n");
		return;
	}
	for (int i = pos; i < pc->sz - 1; i++)
		pc->data[i] = pc->data[i + 1];
	pc->sz--;
	printf("删除成功！\n");
	//scanf("%s", name);
	//int pos = -1;
	//int i;
	//for (i = 0; i < pc->sz; i++)
	//{
	//	if (strcmp(pc->data[i].name, name) == 0)
	//	{
	//		pos = i;
	//		break;
	//	}
	//}
	//if (i == pc->sz)
	//{
	//	printf("需要删除的数据不存在！\n");
	//	return;
	//}
	//for (i = pos; i < pc->sz - 1; i++)
	//	pc->data[i] = pc->data[i + 1];
	//pc->sz--;
	//printf("删除成功！\n");
}

static int FindByName(const Contact* pc, char name[])
{
	int i;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	return -1;
}

//查找联系人
void SearchContact(const Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找的名字>:");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("此信息不存在！\n");
		return;
	}
	printf("%-10s%-6s%-6s%-12s%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-10s%-4d%-5s%-12s%-30s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex,
		pc->data[pos].tele, pc->data[pos].addr);
}
//修改联系人
void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = {0};
	printf("请输入要修改的联系人姓名>:");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("无此人信息！\n");
		return;
	}
	printf("请输入名字>:");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄>:");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别>:");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话>:");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址>:");
	scanf("%s", pc->data[pos].addr);
	printf("修改成功！\n");
}
//排序算法
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//排序
void SortContact(Contact* pc)
{
	qsort(pc->data, pc->sz,sizeof(PeoInfo), cmp_by_name);
	printf("排序成功！\n");
}
//存储到文件
void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "wb");
	if (pf == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	//写数据
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(&pc->data[i], sizeof(struct PeoInfo), 1, pf);
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
	printf("保存成功！\n");
}