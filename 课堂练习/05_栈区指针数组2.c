#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_array(char ** p, int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		printf("%s, ", p[i]);
	}
	printf("\n");
}

void sort_array(char ** p, int n)
{
	int i = 0;
	int j = 0;
	char * tmp;


	//选择法排序
	for (i = 0; i < n - 1; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (strcmp(p[i], p[j]) < 0) //比较，交换
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}

}

int main(void)
{

	char * a[3];

	//数组的每个元素，都指向堆区空间
	int n = sizeof(a) / sizeof(*a);
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		a[i] = (char *)malloc(100);
	}


	strcpy(a[0], "aaaaaaaa");
	strcpy(a[1], "bbbbbb");
	strcpy(a[2], "ccccccc");



	//打印
	print_array(&a[0], n);

	//排序
	sort_array(a, n);

	//打印
	print_array(&a[0], n);

	for (i = 0; i < n; ++i)
	{
		free(a[i]);
	}



	printf("\n");
	system("pause");
	return 0;
}
