#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UniverseLinkLine.h"

//��ʼ��
void INIT_line(VULL * lin)
{
	//�ж�����
	if (NULL == lin)
	{
		return;
	}

	LINE * tmp = (LINE *)malloc(sizeof(LINE));
	if (NULL == tmp)
	{
		return;
	}

	//��ʼ��
	tmp->size = 0;
	tmp->head.next = NULL;
	tmp->tail = &(tmp->head);

	//��Ӹ�ֵ
	*lin = tmp;
}

//���
void PUSH_line(VULL lin, void *data)
{
	//�ж�����
	if (NULL == lin)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	LINE * list = (LINE *)lin;
	NODE * tmp = (NODE *)data;

	//��������
	list->tail->next = tmp;
	tmp->next = NULL;
	list->tail = tmp;

	//��СΪ0�����⴦��	//������Ҫ��

	//��С��һ
	list->size++;
}

//����
void POP_line(VULL lin)
{
	//�ж�����
	if (NULL == lin)
	{
		return;
	}

	LINE * list = (LINE *)lin;

	//�жϴ�С
	if (0 == list->size)
	{
		return;
	}

	//ɾ������
	NODE * tmp = list->head.next;//�׽ڵ�
	list->head.next = tmp->next;

	//����Ϊ1�����
	if (1 == list->size)
	{
		list->tail = &(list->head);//��β��ʶָ�����ָ��ͷ�ڵ�
	}

	//���´�С
	list->size--;
}
//��ѯͷ
void * HEAD_line(VULL lin)
{
	//�ж�����
	if (NULL == lin)
	{
		return NULL;
	}

	return ((NODE *)lin)->next;
}

//��ѯβ
void * END_line(VULL lin)
{
	//�ж�����
	if (NULL == lin)
	{
		return NULL;
	}

	return ((LINE *)lin)->tail;
}

//����
void DESTR_line(VULL * lin)
{
	//�ж�����
	if (NULL == lin || NULL == *lin)
	{
		return;
	}

	//�ͷ�
	free(*lin);
	*lin = NULL;
}