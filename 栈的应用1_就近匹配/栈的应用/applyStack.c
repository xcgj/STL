#include <stdio.h>
#include <stdlib.h>
#include "applyStack.h"

//初始化
void INIT_stack(VLS * head)
{
	if (NULL == head)
	{
		return;
	}

	//LISTSTACK * tmp = (LISTSTACK *)head;	出错原因
	LISTSTACK * tmp = (LISTSTACK *)malloc(sizeof(LISTSTACK));
	if (NULL == tmp)
	{
		return;
	}
	
	tmp->node.next = NULL;
	tmp->size = 0;

	*head = tmp;
}

VLS INIT_stack2()
{
	LISTSTACK * tmp = (LISTSTACK *)malloc(sizeof(LISTSTACK));
	if (NULL == tmp)
	{
		return NULL;
	}

	tmp->node.next = NULL;
	tmp->size = 0;

	return tmp;
}

//压栈
void PUSH_stack(VLS head, void * data)
{
	if (NULL == head)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}

	LISTSTACK * tmp = (LISTSTACK *)head;
	SNODE * dtmp = (SNODE *)data;
	
	dtmp->next = tmp->node.next;
	tmp->node.next = dtmp;

	tmp->size++;
}

//出栈
void POP_stack(VLS head)
{
	if (NULL == head)
	{
		return;
	}
	
	LISTSTACK * tmp = (LISTSTACK *)head;
	if (0 == tmp->size)
	{
		return;
	}

	tmp->node.next = tmp->node.next->next;
	tmp->size--;
}

//查询栈顶元素
void * SEAR_stack(VLS head)
{
	if (NULL == head)
	{
		return NULL;
	}

	LISTSTACK * tmp = (LISTSTACK *)head;
	if (0 == tmp->size)
	{
		return NULL;
	}

	return tmp->node.next;
}

//查询栈大小
int SIZE_stack(VLS head)
{
	if (NULL == head)
	{
		return 0;
	}

	LISTSTACK * tmp = (LISTSTACK *)head;

	return tmp->size;
}

//销毁栈
void DESTR_stack(VLS * head)
{
	if (NULL == head)
	{
		return;
	}
	if (NULL == * head)
	{
		return;
	}

	free(*head);
	*head = NULL;
}
