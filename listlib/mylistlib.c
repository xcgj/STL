#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylistlib.h"

typedef struct Node
{
	int id;				//������
	struct Node *next;	//ָ����
}SLIST;

void SListDestroy(XCGJ * pH)		//�ͷ����нڵ�
{
	SLIST * p = (SLIST*)pH;
	SLIST * temp = NULL;
	while (p)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
}

//ɾ��ֵΪx�����н��
int SListNodeDelPro(XCGJ *pH, int x)
{
	SLIST *pHead = (SLIST*)pH;
	int res = 0;
	if (pHead == NULL)
	{
		printf("err, NULL pointer\n");
		res = -1;
		return res;
	}

	int flag = 0;
	SLIST *pPre = pHead;
	SLIST *pCur = pHead->next;

	while (pCur)
	{
		if (pCur->id == x)
		{
			pCur = pCur->next;
			SLIST *temp = pPre->next;
			temp->next = NULL;
			free(temp);

			pPre->next = pCur;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	return res;
}

//����ڵ����򣬽�������������
int SListNodeSort(XCGJ * pH)
{
	SLIST *pHead = (SLIST*)pH;
	int res = 0;
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("err, NULL pointer\n");
		res = -1;
		return res;
	}

	int index = 1;	//Ԫ�ظ���
	SLIST *pCur = pHead->next->next;
	while (pCur)
	{
		pCur = pCur->next;
		index++;
	}

	SLIST *pPre = pHead->next;
	SLIST * loop = pPre;

	for (int i = 0; i < index - 1; i++)
	{
		pPre = loop;		//�����ѭ����ʼλ��
		pCur = pPre->next;	//�����ѭ����ʼλ��
		for (int j = i + 1; j < index; j++)
		{
			if (pPre->id > pCur->id)
			{
				SLIST temp = *pPre;
				//temp.id = pPre->id;
				pPre->id = pCur->id;	//ֻ����������ֻ��������ֻ��һ����Ա�����
				pCur->id = temp.id;
			}
			pCur = pCur->next;//��ѭ��������
		}
		loop = loop->next;	//ÿ����ѭ����һ��
	}
	/*
	//ע�⣬����nextָ�뻹��Ҫ����
	if (pPre->id > pCur->id) //����
	{
	//�Ƚ����ڵ�����
	SLIST tmp = *pCur;
	*pCur = *pPre;
	*pPre = tmp;

	//�����½���һ��nextָ��������ָ��ָ�
	tmp.next = pCur->next;
	pCur->next = pPre->next;
	pPre->next = tmp.next;
	}*/
	return 0;
}

//����ԭ�������������,��������½ڵ�
//���ܲ���ڵ������������������½ڵ�x
int SListNodeInsertPro(XCGJ * pH, int x, int y)//	x��id��ֵ
{
	SLIST *pHead = (SLIST*)pH;
	int res = 0;
	if (pHead == NULL)
	{
		printf("err, NULL pointer\n");
		res = -1;
		return res;
	}

	SLIST * pPre = pHead;
	SLIST * pCur = pPre->next;

	while (pCur)//pPre��NULLҲ����ѭ��
	{
		if (x == pCur->id)
		{
			break;	//�ҵ��˾�����ѭ��
		}

		pPre = pCur;
		pCur = pCur->next;
	}

	SLIST *temp = (SLIST*)calloc(1, sizeof(SLIST));
	if (temp == NULL)
	{
		printf("err, allacate failed\n");
		res = -2;
		return res;
	}
	temp->id = y;

	temp->next = pPre->next;
	pPre->next = temp;

	return 0;
}

int SListNodeReverse(XCGJ * pH)//ͷ�ڵ㲻����
{
	SLIST *pHead = (SLIST*)pH;
	int res = 0;
	if (pHead == NULL || pHead->next == NULL)//ֻ��һ���ڵ���������
	{
		printf("err, NULL pointer\n");
		res = -1;
		return res;
	}

	SLIST *pPre = pHead;
	SLIST *pCur = pPre->next;
	SLIST *temp = NULL;

	while (pCur)
	{
		temp = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = temp;//��� == NULL
	}

	//����ͷβ�ڵ�
	temp = pHead->next;	//�ڶ����ڵ�
	pHead->next = pPre;
	temp->next = NULL;
	return 0;
}

int SListPrint(XCGJ * pH)//�������нڵ�
{
	SLIST *p = (SLIST *)pH;
	int res = 0;
	if (p == NULL)
	{
		printf("err, NULL pointer\n");
		res = -1;
		return res;
	}

	p = p->next;	//���׽ڵ��ӡ
	for (int i = 0; p; i++)
	{
		printf("��%d���ڵ��ֵΪ��%d\n", i + 1, p->id);
		p = p->next;
		res++;
	}

	return res;	//���سɹ���ӡ�ĸ���
}

void * SListCreat()//�����ڵ�
{
	SLIST *temp = (SLIST*)calloc(1, sizeof(SLIST));
	if (temp == NULL)
	{
		printf("err, allocate failed\n");
		exit(0);
	}

	temp->next = NULL;
	SLIST *t = temp;//����ͷ�ڵ�

	for (int j = 0, k = 0;; j++)
	{
		printf("id of node %d:", j + 1);
		scanf("%d", &k);
		if (k < 0)
			break;
		SLIST *node = (SLIST*)calloc(1, sizeof(SLIST));
		if (node == NULL)
		{
			SListDestroy(t);
			printf("allacate failed\n");
			return NULL;
		}

		node->id = k;
		node->next = NULL;
		temp->next = node;
		temp = node;
	}
	/*
	for (int i = 0; i < 5; i++)
	{
	SLIST *tp = (SLIST*)calloc(1, sizeof(SLIST));
	temp->next = tp;	//�����ڵ�����
	temp = temp->next;	//�����¸��ڵ�
	if (NULL == temp)
	{
	printf("err, allocate failed\n");
	SListDestroy(t);
	return NULL;
	}
	temp->id = 2 * i;
	}
	temp->next = NULL;		//β�ڵ�
	*/
	return t;
}