#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NormalStackList.h"

//��ʼ��
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

//����
void PUSH_tstack(VTSL head, void *data)
{
	//������Ч
	if (NULL == head)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	NODE * pCur = (NODE *)head;//ָ���ڵ�һ��Ա��ֱ��ǿת���ͣ�������תHead������תNODE

	NODE * tmp = (NODE *)malloc(sizeof(NODE));//�����Ƚ�����ĸ������ջ������
	tmp->data = data;

	tmp->next = pCur->next;
	pCur->next = tmp;

	((Head *)head)->size++;
}

//ɾ��
void POP_tstack(VTSL head)
{
	//������Ч
	if (NULL == head)
	{
		return;
	}

	//����
	if (0 == ((Head*)head)->size)
	{
		return;
	}

	NODE * pCur = (NODE *)head;
	pCur->next = pCur->next->next;

	((Head *)head)->size--;
}

//��ѯ����
void * SEAR_tstack(VTSL head)
{
	//������Ч
	if (NULL == head)
	{
		return NULL;
	}

	//����
	if (0 == ((Head*)head)->size)
	{
		return NULL;
	}

	NODE * pCur = ((NODE *)head)->next;

	return pCur->data;
}

//��ѯ��С
int SIZE_tstack(VTSL head)
{
	if (NULL == head)
	{
		return 0;
	}

	return ((Head *)head)->size;
}

//����
void DESTR_tstack(VTSL * head)
{
	if (NULL == head)
	{
		return;
	}

	//����ÿ��Ԫ�أ��ͷſռ�
	//int index = ((Head*)head)->size;//��С
	NODE * pCur = (NODE *)(*head);//ͷ�ڵ�
	NODE * tmp = NULL;

	pCur = pCur->next;//ָ���׽ڵ�
	while (pCur)
	{
		tmp = pCur;
		pCur = pCur->next;
		free(tmp);
	}

	//�ͷŽṹ��
	free(*head);
	*head = NULL;
}
