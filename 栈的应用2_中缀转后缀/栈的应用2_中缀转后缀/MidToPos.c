#include <stdio.h>
#include <stdlib.h>

#include "MidToPos.h"

//��ʼ��
void INIT_stack(VMTPS * head)
{
	if (NULL == head)
	{
		return;
	}

	//ջģ���ڶ�������һ�������ռ�
	LINESTACK * tmp = (LINESTACK *)malloc(sizeof(LINESTACK));
	if (NULL == tmp)
	{
		return;
	}

	tmp->size = 0;
	for (int i = 0; i < MAX; i++)//����ÿ��Ԫ�ظ�ֵΪ��
	{
		tmp->stk[i] = NULL;
	}

	*head = tmp;
}

//��ջ
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

	//�ж���ջ
	if (tmp->size == MAX)
	{
		return;
	}

	//��ջ
	tmp->stk[tmp->size] = data;
	tmp->size++;
}

//��ջ
void POP_stack(VMTPS head) 
{
	if (NULL == head)
	{
		return;
	}

	LINESTACK * tmp = (LINESTACK *)head;

	//�жϿ�ջ
	if (0 == tmp->size)
	{
		return;
	}

	//��ջ
	tmp->size--;
}

//��ȡջ��Ԫ��
void * TOPREAD_stack(VMTPS head)
{
	if (NULL == head)
	{
		return NULL;
	}

	LINESTACK * tmp = (LINESTACK *)head;

	//�жϿ�ջ
	if (0 == tmp->size)
	{
		return NULL;
	}

	//��������
	return tmp->stk[tmp->size - 1];
}

//��ȡջ��С
int SIZE_stack(VMTPS head)
{
	if (NULL == head)
	{
		return 0;
	}

	return ((LINESTACK *)head)->size;
}

//����ջ
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