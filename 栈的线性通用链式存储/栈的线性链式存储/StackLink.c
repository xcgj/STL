#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StackLink.h"

//��ͷ��ʼ��
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

//��ջ
void PUSH_ustack(VUSL head, void * data)
{
	//�ж���������
	if (NULL == head)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	LISTNODE * pCur = (LISTNODE *)head;//ָ��ͷ�ڵ�//��������ת�ɣ�
	LISTNODE * pinsert = (LISTNODE *)data;

	pinsert->next = pCur->next;
	pCur->next = pinsert;

	((UNISTACK *)head)->size++;
}

//��ջ
void POP_ustack(VUSL head)
{
	//�ж�ֵ��Ч
	if (NULL == head)
	{
		return;
	}

	//�жϿ�ջ
	if (0 == ((UNISTACK*)head)->size)
	{
		return;
	}
	
	//ɾ��
	LISTNODE * pCur = (LISTNODE *)head;//ͷ�ڵ�
	pCur->next = pCur->next->next;

	((UNISTACK *)head)->size--;
}

//��ѯջ��Ԫ��
void * SEAR_ustack(VUSL head)
{
	//�ж�����
	if (NULL == head)
	{
		return NULL;
	}

	//�ж������С
	if (0 == ((UNISTACK*)head)->size)
	{
		return NULL;
	}

	//����ֵ
	LISTNODE * pCur = ((LISTNODE *)head)->next;//�׽ڵ�
	return pCur;	//((LISTNODE *)head)->next
}

//��ѯ�����С
int SIZE_ustack(VUSL head)
{
	//�ж�����
	if (NULL == head)
	{
		return -1;
	}

	return ((UNISTACK *)head)->size;
}


//����
void DESTR_ustack(VUSL * head)
{
	//�ж�����
	if (NULL == head)
	{
		return;
	}

	//�ж�����
	if (NULL == *head)
	{
		return;
	}

	free(*head);
	*head = NULL;
}
