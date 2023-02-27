#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
char* FindString(char* p1, const char* p2)
{
	const char* ptr1 = p1;
	const char* ptr2 = p2;
	while (*p1)
	{
		ptr1 = p1, ptr2 = p2;
		while (*ptr1 == *ptr2)
		{
			ptr1++;
			ptr2++;
		}
		if (*ptr2 == '\0')
			return p1;
		p1++;
	}
	return NULL;
}
int my_strcmp(const char* p1, const char* p2)
{
	while (*p1 == *p2 && *p1 && *p2)
	{
		p1++, p2++;
	}
	return *p1 - *p2;
}
int main()
{
	char ch[101] = {0};
	int stc = 0;
	int flag;
	int count = 0;
	while (1)
	{
		scanf("%[^\n]", ch);
		getchar();
		if (my_strcmp(ch, ".") == 0)
		{
			break;
		}
		stc++;
		if (FindString(ch, "chi1 huo3 guo1") != NULL)
		{
			count++;
			if (count == 1)
			{
				flag = stc;
			}
		}
	}
	printf("%d\n%d %d\n", stc, flag, count);

	return 0;
}