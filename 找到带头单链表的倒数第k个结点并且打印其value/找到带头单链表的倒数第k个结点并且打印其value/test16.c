#include <stdio.h>
#include <stdlib.h>

typedef struct man
{
	int no;
	struct man *next;
}man_t; 
//ʵ�ֺ��� int insertHeadList(man_t *phead, int newno)ͷ�巨�����½ڵ㡣
int insertHeadList(man_t *phead, int newno);

int insertHeadList(man_t *phead, int newno)
{
	int ret = 0;
	//�ж�����
	if (NULL == phead)
	{
		ret = -1;
		return ret;
	}
	
	//�����½ڵ�ռ�
	man_t * pnew = (man_t *)malloc(sizeof(man_t));
	if (NULL == pnew)
	{
		ret = -2;
		return ret;
	}

	//��ֵ�ν�
	pnew->no = newno;
	pnew->next = phead->next;
	phead->next = pnew;

	return ret;
}