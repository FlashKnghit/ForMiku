#include "contact.h"
//��ʼ��
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
// ��̬�汾��
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
		printf("��ʼ��ʧ�ܣ�>:%s\n", strerror(errno));
	LoadContact(pc);
}
//����ͨѶ¼
void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
}
//�������
int CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("����ʧ�ܣ�>:%s\n", strerror(errno));
			return 0;
		}
		pc->data = ptr;
		pc->capacity += INC_SZ;
		return 1;
	}
}
//����ָ����ϵ��
void AddContact(Contact* pc)
{
	//if (pc->sz == MAX)
	//{
	//	printf("ͨѶ¼����,�޷�����\n");
	//	return;
	//}
	//��̬��
	if (CheckCapacity(pc) == 0)
	{
		printf("����ʧ�ܣ�\n");
		return;
	}
	printf("����������>:");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������>:");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�>:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰>:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ>:");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ���\n");
}
//��ʾ��ϵ����Ϣ
void ShowContact(const Contact* pc)
{
	//��ʽ����ӡ �����
	printf("%-10s%-6s%-6s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-10s%-4d%-5s%-12s%-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex,
			pc->data[i].tele, pc->data[i].addr);
	}
}
//ɾ����ϵ��
void DeleteContact(Contact* pc)
{
	char name[20];
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("������ɾ������>��");
	scanf("%s", name);
	int pos = FindByName(pc ,name);
	if (pos == -1)
	{
		printf("��Ҫɾ�������ݲ����ڣ�\n");
		return;
	}
	for (int i = pos; i < pc->sz - 1; i++)
		pc->data[i] = pc->data[i + 1];
	pc->sz--;
	printf("ɾ���ɹ���\n");
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
	//	printf("��Ҫɾ�������ݲ����ڣ�\n");
	//	return;
	//}
	//for (i = pos; i < pc->sz - 1; i++)
	//	pc->data[i] = pc->data[i + 1];
	//pc->sz--;
	//printf("ɾ���ɹ���\n");
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

//������ϵ��
void SearchContact(const Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ���ҵ�����>:");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("����Ϣ�����ڣ�\n");
		return;
	}
	printf("%-10s%-6s%-6s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-10s%-4d%-5s%-12s%-30s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex,
		pc->data[pos].tele, pc->data[pos].addr);
}
//�޸���ϵ��
void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = {0};
	printf("������Ҫ�޸ĵ���ϵ������>:");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("�޴�����Ϣ��\n");
		return;
	}
	printf("����������>:");
	scanf("%s", pc->data[pos].name);
	printf("����������>:");
	scanf("%d", &(pc->data[pos].age));
	printf("�������Ա�>:");
	scanf("%s", pc->data[pos].sex);
	printf("������绰>:");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ>:");
	scanf("%s", pc->data[pos].addr);
	printf("�޸ĳɹ���\n");
}
//�����㷨
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//����
void SortContact(Contact* pc)
{
	qsort(pc->data, pc->sz,sizeof(PeoInfo), cmp_by_name);
	printf("����ɹ���\n");
}
//�洢���ļ�
void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "wb");
	if (pf == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	//д����
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(&pc->data[i], sizeof(struct PeoInfo), 1, pf);
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	printf("����ɹ���\n");
}