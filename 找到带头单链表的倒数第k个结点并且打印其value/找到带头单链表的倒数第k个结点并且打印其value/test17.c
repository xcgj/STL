//ʵ��int Compare(void *d1, void *d2, pCompare pfunc); ����
//ʵ�ֱȽϺ��� �� �Դ������ݵıȽ�
#include <stdio.h>
#include <stdlib.h>

#include "test17.h"

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