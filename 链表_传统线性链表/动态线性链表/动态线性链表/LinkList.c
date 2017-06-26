#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkList.h"

//��ʼ��
LinkInfo * INIT_link()
{
	LinkInfo * Head = (LinkInfo *)malloc(sizeof(LinkInfo));
	if (NULL == Head)
	{
		return NULL;
	}

	Head->head.next= NULL;
	Head->size = 0;

	return Head;
}

//ָ��λ�ò������ݣ�ͷ�ڵ����һ���ڵ㣨�׽ڵ㣩���0��Ԫ��
int INSERT_link(void * head, int pos, void * data)
{
	//�ж��������ݵĺϷ���
	if (NULL == head || NULL == data)
	{
		return -1;
	}

	LinkInfo * pHead = (LinkInfo *)head;

	//�ж�λ�õĺϷ���
	if (pos < 0 || pos > pHead->size)
	{
		pos = pHead->size;
	}

	//��������ֱ������ָ��λ��
	LinkNode * pCur = &(pHead->head);//��ͷ�ڵ�ĵ�ַ��ֵ��pCur��pCur����ͷ�ڵ����±���
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;	//��0��Ԫ�ص�λ�����׽ڵ��λ�ã�pCur->next��
	}

	LinkNode * tmp = (LinkNode *)malloc(sizeof(LinkNode));
	tmp->data = data;
	tmp->next = NULL;

	tmp->next = pCur->next;
	pCur->next = tmp;

	pHead->size++;

	return 0;
}

//��λ��ɾ��
int DELPOS_link(void * head, int pos)
{
	//�ж�λ�úϷ���
	if (NULL == head)
	{
		return -1;
	}

	LinkInfo * pHead = (LinkInfo *)head;

	//�ж�λ�õĺϷ���
	if (pos < 0 || pos > pHead->size - 1)
	{
		return -1;
	}
	
	//�жϿ�����
	if (0 == pHead->size)
	{
		return -1;
	}

	LinkNode * pCur = &(pHead->head);//ͷ�ڵ�

	for (int i = 0; i < pos; i++)	//ѭ������ʱ��pCur���ڵ�pos��Ԫ�ص�λ��
	{
		pCur = pCur->next;
	}

	LinkNode * tmp = pCur->next;	//�����ɾ���ڵ�
	pCur->next = tmp->next;			//�ν�ǰ��ڵ�

	tmp->next = NULL;
	free(tmp);

	pHead->size--;

	return 0;
}

//����
//int ERGODIC_link(void * head, void(*PRINT)(void * data));
int ERGODIC_link(void * head, PRINT pri)
{
	if (NULL == head || NULL == pri)
	{
		return -1;
	}

	LinkInfo * pHead = (LinkInfo *)head;
	LinkNode * pCur = &(pHead->head);

	for (int i = 0; i < pHead->size; i++)
	{
		pCur = pCur->next;
		pri(pCur->data);
	}

	return 0;
}

//��ֵɾ��
//int DELVAL_link(void * head, void * data, void(*COMPARE)(void * data1, void * data2));
int DELVAL_link(void * head, void * data, COMPARE com)
{
	if (NULL == head || NULL == data || NULL == com)
	{
		return -1;
	}

	LinkInfo * pHead = (LinkInfo *)head;
	LinkNode * pPre = &(pHead->head);	//ͷ�ڵ�
	LinkNode * pCur = pPre->next; ;		//�׽ڵ�

	for (int i = 0; i < pHead->size; i++)
	{
		if ((com(pCur->data, data)))
		{
			//break;			//�˳�ѭ��ʱ��pCur�ڴ�ɾ���ڵ㣬pPre��ǰһ���ڵ�
			LinkNode * tmp = pCur;	//����ɾ���ڵ�
			pCur = pCur->next;		//�����¸��ڵ�
			pPre->next = pCur;		//�νӽڵ�

			tmp->next = NULL;
			free(tmp);

			pHead->size--;

			continue;
		}
		pPre = pCur;
		pCur = pCur->next;
	}

	return 0;
}

//�ͷ�
int FREE_link(void ** head)
{
	if (NULL == head)
	{
		return -1;
	}

	LinkInfo * pHead = (LinkInfo *)(*head);

	LinkNode * pCur = pHead->head.next;
	LinkNode * tmp = pCur;

	while (pCur != NULL)
	{
		pCur = pCur->next;
		free(tmp);
		tmp = pCur;
	}
	
	free(pHead);
	*head = NULL;

	printf("�ڴ��ͷųɹ�\n");

	return 0;
}