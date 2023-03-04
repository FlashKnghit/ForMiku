#include <stdio.h>
//输入一个数组的大小和右移的次数
//输出右移N次的新数组
//不适用额外的数组空间 
//移动尽量少的次数 
reverse(int* x, int* y)
{
	(*x)^=(*y);
	(*y)^=(*x);
	(*x)^=(*y);
}
int main(void)
{
	int m,n;
	scanf("%d%d",&n,&m); 
	int arr[n];
	//输入 
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	m%=n;
	//逆序 
	int i = 0,j = n - m - 1;
	while(i<j)
	{
		reverse(&arr[i++],&arr[j--]);
	}
	i = n - m, j = n - 1;
	while(i<j)
	{
		reverse(&arr[i++],&arr[j--]);
	}
	i = 0, j = n - 1;
	while(i<j)
	{
		reverse(&arr[i++],&arr[j--]);
	}
	//打印 
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


