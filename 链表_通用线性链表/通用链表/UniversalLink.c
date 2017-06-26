#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UniversalLink.h"

//��ʼ����ͷ
LinkList * INIT_list()
{
	LinkList * list = (LinkList *)malloc(sizeof(LinkList));
	if (NULL == list)
	{
		return NULL;
	}

	list->size = 0;
	list->header.next = NULL;

	return list;
}

//ָ��λ�ò���
void INSERT_list(VList head, int pos, void * data)
{
	//�ж�����Ϸ���
	if (NULL == head)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	LinkList * list = (LinkList *)head;

	//�ж�λ�úϷ���
	if (pos < 0 || pos > list->size)
	{
		pos = list->size;
	}

	//����λ��
	LinkNode * pCur = &(list->header);//��&(list->header)��LinkNode�ṹ���ַ��ֵ��pCur, pCurָ����ͷ�ڵ�
	for (int i = 0; i < pos; i++)//ͷ�ڵ������0��Ԫ��
	{
		pCur = pCur->next;
	}

	//��Ϊ�û���������ݵ��׵�ַҲ�ǽڵ���׵�ַ������Ҫ����������Ľڵ�
	LinkNode * node_info = (LinkNode *)data;
	node_info->next = pCur->next;
	pCur->next = node_info;

	list->size++;
}

//ָ��λ��ɾ��
void DELPOS_list(VList head, int pos)
{
	//�ж���������ĺϷ���
	if (NULL == head)
	{
		return;
	}

	LinkList * list = (LinkList *)head;

	//�ж��Ƿ����
	if (0 == list->size)
	{
		return;
	}

	//�ж�λ�úϷ���
	if (pos < 0 || pos >= list->size)
	{
		return;
	}
	
	//����λ��
	LinkNode * pCur = &(list->header);//pCurָ���ͷ�ṹ���еĽڵ�ṹ�壨ͷ�ڵ㣩
	for (int i = 0; i < pos; i++)//ѭ������ʱ��pCurͣ�ڴ�ɾ��λ�õ�ǰһ��λ��
	{
		pCur = pCur->next;
	}

	//ɾ��λ�á��ν�
	LinkNode * tmp = pCur->next;//�洢��ɾ���ڵ�
	pCur->next = tmp->next;//ǰ�ڵ������м�ڵ����Ӻ�ڵ�
	tmp->next = NULL;
	//free(tmp);//ɾ��tmpָ��ָ��Ľڵ㣬����Ҫɾ����û������ѿռ�

	list->size--;
}

//����
void ERGODIC_list(VList head, PRINT pri)
{
	if (NULL == head)
	{
		return;
	}

	if (NULL == pri)
	{
		return;
	}

	LinkList * list = (LinkList *)head;
	LinkNode * pCur = &(list->header);//ͷ�ڵ�

	for (int i = 0; i < list->size; i++)
	{
		pCur = pCur->next;
		pri(pCur);
	}
}

//��ֵɾ��
void DELVAL_list(VList head, void * data, COMPARE com)
{
	if (NULL == head)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	if (NULL == com)
	{
		return;
	}

	LinkList * list = (LinkList *)head;

	if (0 == list->size)
	{
		return;
	}

	//����
	LinkNode * pPre = &(list->header);//ͷ�ڵ�
	LinkNode * pCur = pPre;
	for (int i = 0; i < list->size; i++)//������while(NULL != pCur)
	{
		pCur = pCur->next;
		if (com(pCur, data))//������ͬ
		{
			/*��������ô����list->size��仯��Ӱ��β�����ݵĶ�ȡ
			pPre = pCur->next;
			pCur = pPre;	//�����ڵ㣬û������ѿռ䣬���Բ�free
			list->size--;
			*/
			break;
		}
		pPre = pCur;
	}

	pPre->next = pCur->next;
	list->size--;
}

//�����ӡ����(ע��:����ת����)
void REPRIN_list(VList head, PRINT pri)
{
	//�ж�����
	if (NULL == head)
	{
		return;
	}

	if (NULL == pri)
	{
		return;
	}

	LinkNode * re = ((LinkNode *)head)->next;//��һ������
	REPRIN_list(re, pri);//�ݹ�
	pri(re);//�ص���ӡ����
}

//����ѡ������
void SELECT_list(VList head, COMPARE secom)
{
	//�ж�����
	if (NULL == head)
	{
		return;
	}

	if (NULL == secom)
	{
		return;
	}

	//��ȡ�����ȣ���������������ռ䣬��¼�±꽻��Ч�ʲ���
	LinkList * list = (LinkList *)head;
	int n = list->size;
	if (n <= 1)//������ֻ��һ��Ԫ�ز�������
	{
		return;
	}

	LinkNode * pFrom = &(list->header); //ͷ�ڵ�

#if 0
	LinkNode * pTo = NULL; //ͷ�ڵ�

	for (int i = 0; i < n - 1; i++)
	{
		pFrom = pFrom->next;	//�׽ڵ㿪ʼ�Ƚ�
		pTo = pFrom;			//ͬ����ʼ�ڵ�
		for (int j = i + 1; j < n; j++)
		{
			pTo = pTo->next;	//�ڵ����κ���
			if (secom(pFrom, pTo))
			{
				/*
				����һ������û����������ݴ����ָ���򴫵ݽ�����ֻ��Ҫ���������򼴿ɣ����ý���ָ����
				Person tmp = { NULL, NULL }; 
				tmp.dat = ((Person *)pFrom)->dat;
				((Person *)pFrom)->dat = ((Person *)pTo)->dat;
				((Person *)pTo)->dat = tmp.dat;
				*/

				//��������
				//�����ڵ㡶���塷
				Person tmp = *((Person*)pFrom);//ָ��ָ�򽻻�
				*((Person*)pFrom) = *((Person*)pTo);
				*((Person*)pTo) = tmp;
				//����ָ����
				tmp.next = pFrom->next;
				pFrom->next = pTo->next;
				pTo->next = tmp.next;
			}
		}
	}
#endif
	//�Ż�����ѡ�������㷨
	for (LinkNode * pTo = pFrom->next; pTo != NULL; pTo = pTo->next)//��ֹ�������жϡ�pTo->next != NULL��,��Ϊÿ��ѭ����Ҫ�жϡ�pTo = pTo->next���Ƿ�ΪNULL
	{
		//��ʱ�������漫ֵ�ڵ㣬һ��ʼ�ٶ�pToΪ��ֵ
		LinkNode * pm = pTo;
		for (LinkNode * pc = pTo->next; pc != NULL; pc = pc->next)
		{
			if (secom(pm, pc))
			{
				pm = pc;//�����������pc��ַ
			}
		}

		//ѭ��������pm�õ���ֵ�ĵ�ַ���ж��Ƿ���ԭ��pTo�ĵ�ַ
		if (pm != pTo)
		{
			Person * a = (Person *)pm;
			Person * b = (Person *)pTo;
			void * tmp = a->dat;
			a->dat = b->dat;
			b->dat = tmp;
		}
	}
}

//��������
void REVERSE_list(VList head)
{
	//�ж�����
	if (NULL == head)
	{
		return;
	}

	LinkList * Head = (LinkList *)head;
	LinkNode * pCur = Head->header.next;//�׽ڵ�
	//�ж�
	if (NULL == pCur)//
	{
		return;
	}
	
	LinkNode * pPre = pCur;
	pCur = pCur->next;

	LinkNode * tmp = NULL;
	while (NULL != pCur)
	{
		tmp = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = tmp;
	}

	tmp = Head->header.next;//�׽ڵ㣻
	tmp->next = NULL;

	(&(Head->header))->next = pPre;
}

//�ͷ�
void FREE_list(VList * head)
{
	if (NULL == head)
	{
		return;
	}

	LinkList * list = (LinkList *)(*head);
	free(list);
	*head = NULL;
	printf("�ڴ��ͷųɹ�\n");
}