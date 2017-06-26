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

void free_array(char***a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		free((*a)[i]);
		(*a)[i] = NULL;
	}

	free(*a);
	*a = NULL;
}
int main(void)
{
	//char str1[100] = { 0 };
	//char str2[100] = { 0 };
	//char str3[100] = { 0 };

	char *str1 = (char*)malloc(100);
	char *str2 = (char*)malloc(100);
	char *str3 = (char*)malloc(100);

	//char * a[3];
	//char * a[3] = { str1, str2, str3 };
	char **a = (char**)malloc(100 * sizeof(char*));


	a[0] = str1;
	a[1] = str2;
	a[2] = str3;

	strcpy(a[0], "aaaaaaaa");
	strcpy(a[1], "bbbbbb");
	strcpy(a[2], "ccccccc");

	int n = 3;

	//打印
	print_array(&a[0], n);

	//排序
	sort_array(a, n);

	//打印
	print_array(&a[0], n);

	free_array(&a, n);

	printf("\n");
	system("pause");
	return 0;
}
