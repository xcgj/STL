#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int(*fu[])(int);
int func0(int);
int func1(int);
extern fu a = { func0, func1 };//����ָ������

int func0(int n)
{
	return n = 0;
}

int func1(int n)
{
	//return n + a[!!n](n - 1);
	return n + a[!!(n - 1)](n - 1);//����д������
}	//!!n������0����1����Ϊa������±꣬���ö�Ӧ�ĺ���

int main(void)
{
	int n = 2;
	int sum = func1(n);
	printf("%d\n",sum);
	return 0;
}
