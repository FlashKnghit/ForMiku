#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
/*
void qsort (void* base, size_t num, size_t size,
			int (*compar)(const void*,const void*));
*/
void Swap(char* p1, char* p2, int size)
{
	while (size--)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++, p2++;
	}
}
int cmp_int(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}
//用冒泡排序的方法来实现的qsort
void bubble_qsort(void* base, int len, int size, int (*cmp)(const void*, const void*))
{
	int i;
	for (i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
			{
				Swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}
int main()
{
	int arr[] = { 5,4,1,3,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//qsort(arr, sz, sizeof(arr[0]), cmp_int);
	bubble_qsort(arr, sz, sizeof(arr[0]), cmp_int);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}