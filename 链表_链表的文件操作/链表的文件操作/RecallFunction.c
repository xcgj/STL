#include <stdio.h>

#include "RecallFunction.h"
#include "List.h"

//====================回调函数实现====================
int compare(void * data1, void * data2)
{
	if (NULL == data1)
	{
		return 0;
	}
	if (NULL == data2)
	{
		return 0;
	}

	ND * d1 = (ND *)data1;
	ND * d2 = (ND *)data2;

	return d1->dat->a < d2->dat->a ? 1 : 0;
}

int isequal(void * data1, void * data2)//相等
{
	if (NULL == data1)
	{
		return 0;
	}
	if (NULL == data2)
	{
		return 0;
	}

	ND * d1 = (ND *)data1;
	ND * d2 = (ND *)data2;

	return d1->dat->a == d2->dat->a ? 1 : 0;
}

void print(void * data)
{
	if (NULL == data)
	{
		return;
	}

	printf("%d ", ((ND *)data)->dat->a);
}

void exchange(void *data1, void *data2)//交换数据域
{
	if (NULL == data1)
	{
		return;
	}
	if (NULL == data2)
	{
		return;
	}

	ND * d1 = (ND *)data1;
	ND * d2 = (ND *)data2;

	void * tmp = d1->dat;
	d1->dat = d2->dat;
	d2->dat = tmp;
}