#include <stdio.h>
#include <stdlib.h>

typedef struct man
{
	int no;
	struct man *next;
}man_t; 
//实现函数 int insertHeadList(man_t *phead, int newno)头插法插入新节点。
int insertHeadList(man_t *phead, int newno);

int insertHeadList(man_t *phead, int newno)
{
	int ret = 0;
	//判断数据
	if (NULL == phead)
	{
		ret = -1;
		return ret;
	}
	
	//创建新节点空间
	man_t * pnew = (man_t *)malloc(sizeof(man_t));
	if (NULL == pnew)
	{
		ret = -2;
		return ret;
	}

	//赋值衔接
	pnew->no = newno;
	pnew->next = phead->next;
	phead->next = pnew;

	return ret;
}