#include <stdio.h>

typedef int(*pCompare)(int d1, int d2);

typedef struct A
{
	char name[10];
	int age;
}A;




int compare(int d1, int d2);
int Compare(void *d1, void *d2, pCompare pfunc);




int Compare(void *d1, void *d2, pCompare pfunc)
{
	int res = 0;
	if (NULL == d1)
	{
		res = -100;
		return res;
	}

	if (NULL == d2)
	{
		res = -100;
		return res;
	}

	if (NULL == pfunc)
	{
		res = -100;
		return res;
	}

	A * c1 = (A *)d1;
	A * c2 = (A *)d2;

	res = pfunc(c1->age, c2->age);

	return res;
}


int compare(int d1, int d2)
{
	if (d1 == d2)
	{
		return 0;
	}

	if (d1 > d2)
	{
		return 1;
	}

	return -1;
}

int main1(void)
{
	A a1 = { "aaa", 10 };
	A a2 = { "bbb", 20 };

	int ret = Compare(&a1, &a2, compare);

	if (0 == ret)
	{
		printf("两个数相等\n");
	}

	else if (-1 == ret)
	{
		printf("参数2大\n");
	}

	else if (1 == ret)
	{
		printf("参数1大\n");
	}

	else
	{
		printf("参数错误\n");
	}

	printf("Compelete\n");
	return 0;
}
