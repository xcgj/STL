#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StackLink.h"

//表头初始化
VUSL INIT_USL()
{
	UNISTACK * tmp = (UNISTACK *)malloc(sizeof(UNISTACK));
	if (NULL == tmp)
	{
		return NULL;
	}

	tmp->size = 0;
	tmp->header.next = NULL;

	return tmp;
}

//入栈
void PUSH_ustack(VUSL head, void * data)
{
	//判断输入数据
	if (NULL == head)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	LISTNODE * pCur = (LISTNODE *)head;//指向头节点//可以这样转吧？
	LISTNODE * pinsert = (LISTNODE *)data;

	pinsert->next = pCur->next;
	pCur->next = pinsert;

	((UNISTACK *)head)->size++;
}

//出栈
void POP_ustack(VUSL head)
{
	//判断值有效
	if (NULL == head)
	{
		return;
	}

	//判断空栈
	if (0 == ((UNISTACK*)head)->size)
	{
		return;
	}
	
	//删除
	LISTNODE * pCur = (LISTNODE *)head;//头节点
	pCur->next = pCur->next->next;

	((UNISTACK *)head)->size--;
}

//查询栈顶元素
void * SEAR_ustack(VUSL head)
{
	//判断数据
	if (NULL == head)
	{
		return NULL;
	}

	//判断链表大小
	if (0 == ((UNISTACK*)head)->size)
	{
		return NULL;
	}

	//返回值
	LISTNODE * pCur = ((LISTNODE *)head)->next;//首节点
	return pCur;	//((LISTNODE *)head)->next
}

//查询链表大小
int SIZE_ustack(VUSL head)
{
	//判断数据
	if (NULL == head)
	{
		return -1;
	}

	return ((UNISTACK *)head)->size;
}


//销毁
void DESTR_ustack(VUSL * head)
{
	//判断数据
	if (NULL == head)
	{
		return;
	}

	//判断数据
	if (NULL == *head)
	{
		return;
	}

	free(*head);
	*head = NULL;
}
