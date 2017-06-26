#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NormalStackList.h"

//初始化
VTSL INIT_tstack()
{
	Head * tmp = (Head *)malloc(sizeof(Head));
	if (NULL == tmp)
	{
		return NULL;
	}

	tmp->size = 0;
	tmp->header.next = NULL;

	return tmp;
}

//插入
void PUSH_tstack(VTSL head, void *data)
{
	//数据有效
	if (NULL == head)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	NODE * pCur = (NODE *)head;//指针在第一成员，直接强转类型，不用先转Head类型再转NODE

	NODE * tmp = (NODE *)malloc(sizeof(NODE));//符合先进后出的概念就是栈链类型
	tmp->data = data;

	tmp->next = pCur->next;
	pCur->next = tmp;

	((Head *)head)->size++;
}

//删除
void POP_tstack(VTSL head)
{
	//数据有效
	if (NULL == head)
	{
		return;
	}

	//空链
	if (0 == ((Head*)head)->size)
	{
		return;
	}

	NODE * pCur = (NODE *)head;
	pCur->next = pCur->next->next;

	((Head *)head)->size--;
}

//查询数据
void * SEAR_tstack(VTSL head)
{
	//数据有效
	if (NULL == head)
	{
		return NULL;
	}

	//空链
	if (0 == ((Head*)head)->size)
	{
		return NULL;
	}

	NODE * pCur = ((NODE *)head)->next;

	return pCur->data;
}

//查询大小
int SIZE_tstack(VTSL head)
{
	if (NULL == head)
	{
		return 0;
	}

	return ((Head *)head)->size;
}

//销毁
void DESTR_tstack(VTSL * head)
{
	if (NULL == head)
	{
		return;
	}

	//弹出每个元素，释放空间
	//int index = ((Head*)head)->size;//大小
	NODE * pCur = (NODE *)(*head);//头节点
	NODE * tmp = NULL;

	pCur = pCur->next;//指向首节点
	while (pCur)
	{
		tmp = pCur;
		pCur = pCur->next;
		free(tmp);
	}

	//释放结构体
	free(*head);
	*head = NULL;
}
