#include <stdio.h>
//����һ������Ĵ�С�����ƵĴ���
//�������N�ε�������
//�����ö��������ռ� 
//�ƶ������ٵĴ��� 
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
	//���� 
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	m%=n;
	//���� 
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
	//��ӡ 
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


