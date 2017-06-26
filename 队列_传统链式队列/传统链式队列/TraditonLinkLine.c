#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TraditonLinkLine.h"

//��ʼ��
void INIT_line(VTLL * line)//����ָ���Ӹ�ֵ
{
	//�ж�����
	if (NULL == line)
	{
		return;
	}

	//�����ͷ�ռ�
	LINE * tmp = (LINE *)malloc(sizeof(LINE));
	if (NULL == tmp)
	{
		return;
	}

	//�����Ա����
	tmp->size = 0;

	tmp->head.next = NULL;
	tmp->head.data = NULL;

	tmp->tail = &(tmp->head);//β�ڵ��ʶָ��ָ��ͷ�ڵ�

	//��Ӹ�ֵ
	*line = tmp;
}

//β�ڵ����
void PUSH_line(VTLL line, void * data)
{
	//�ж�����
	if (NULL == line)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	LINE * list = (LINE *)line;
	NODE *tmp = (NODE *)malloc(sizeof(NODE));
	if (NULL == tmp)
	{
		return;
	}

	//����ڵ�
	tmp->data = data;
	tmp->next = NULL;

	list->tail->next = tmp;//����β�ڵ�nextָ���ָ��
	list->tail = tmp;		//����β�ڵ��ʶָ��ָ��

	//�����СΪ0����Ҫ����ͷ�ڵ�
	if (0 == list->size)
	{
		list->head.next = tmp;//ͷ�ڵ�ָ��Ψһһ����Ч�ڵ�
	}

	//���´�С
	list->size++;
}

//ͷ�ڵ���ӣ�ע���СΪ1ʱβ�ڵ��ʶ��ָ��
void POP_line(VTLL line)
{
	//�ж�������Ч
	if (NULL == line)
	{
		return;
	}

	LINE * list = (LINE *)line;
	NODE * tmp = list->head.next;//�����ɾ���ڵ㣬�׽ڵ�

	//�жϿ���
	if (0 == list->size)
	{
		return;
	}

	//ͷ�ڵ�ı�ָ��
	list->head.next = tmp->next;
	free(tmp);

	if (1 == list->size)
	{
		list->tail = &(list->head);
	}

	//���´�С
	list->size--;
}

//��ѯ��ͷ�Ͷ�β������
void READ_line(VTLL line, void ** data1, void ** data2)//����ָ���Ӹ�ֵ
{
	//�ж�������Ч��
	if (NULL == line)
	{
		return;
	}

	if (NULL == data1 || NULL == *data1)
	{
		return;
	}

	if (NULL == data2 || NULL == *data2)
	{
		return;
	}

	LINE * list = (LINE *)line;

	//�жϿ���
	if (0 == list->size)
	{
		return;
	}

	//��Ӹ�ֵ
	*data1 = list->head.next->data;
	*data2 = list->tail->data;
}

//���ٶ���
void DESTR_line(VTLL * line)
{
	//�ж�����
	if (NULL == line || NULL == *line)
	{
		return;
	}
	
	LINE * list = (LINE *)(*line);
	NODE * pCur = list->head.next;
	NODE * tmp = NULL;

	while (NULL != pCur)
	{
		tmp = pCur->next;
		free(pCur);
		pCur = tmp;
	}

	free(list);
	*line = NULL;
	printf("�ͷųɹ�\n");
}