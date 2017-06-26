#include <stdio.h>
#include <stdlib.h>

#include "MidToPos.h"

//初始化
void INIT_stack(VMTPS * head)
{
	if (NULL == head)
	{
		return;
	}

	//栈模型在堆中申请一块连续空间
	LINESTACK * tmp = (LINESTACK *)malloc(sizeof(LINESTACK));
	if (NULL == tmp)
	{
		return;
	}

	tmp->size = 0;
	for (int i = 0; i < MAX; i++)//数组每个元素赋值为空
	{
		tmp->stk[i] = NULL;
	}

	*head = tmp;
}

//入栈
void PUSH_stack(VMTPS head, void * data)
{
	if (NULL == head)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}

	LINESTACK * tmp = (LINESTACK *)head;

	//判断满栈
	if (tmp->size == MAX)
	{
		return;
	}

	//入栈
	tmp->stk[tmp->size] = data;
	tmp->size++;
}

//出栈
void POP_stack(VMTPS head) 
{
	if (NULL == head)
	{
		return;
	}

	LINESTACK * tmp = (LINESTACK *)head;

	//判断空栈
	if (0 == tmp->size)
	{
		return;
	}

	//出栈
	tmp->size--;
}

//获取栈顶元素
void * TOPREAD_stack(VMTPS head)
{
	if (NULL == head)
	{
		return NULL;
	}

	LINESTACK * tmp = (LINESTACK *)head;

	//判断空栈
	if (0 == tmp->size)
	{
		return NULL;
	}

	//返回数据
	return tmp->stk[tmp->size - 1];
}

//获取栈大小
int SIZE_stack(VMTPS head)
{
	if (NULL == head)
	{
		return 0;
	}

	return ((LINESTACK *)head)->size;
}

//销毁栈
void DESTR_stack(VMTPS * head)
{
	if (NULL == head)
	{
		return;
	}
	if (NULL == *head)
	{
		return;
	}

	free(*head);
	*head = NULL;
}