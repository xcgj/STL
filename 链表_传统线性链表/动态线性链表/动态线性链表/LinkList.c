#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkList.h"

//初始化
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

//指定位置插入数据，头节点的下一个节点（首节点）算第0个元素
int INSERT_link(void * head, int pos, void * data)
{
	//判断输入数据的合法性
	if (NULL == head || NULL == data)
	{
		return -1;
	}

	LinkInfo * pHead = (LinkInfo *)head;

	//判断位置的合法性
	if (pos < 0 || pos > pHead->size)
	{
		pos = pHead->size;
	}

	//遍历链表，直到到达指定位置
	LinkNode * pCur = &(pHead->head);//将头节点的地址赋值给pCur，pCur将从头节点往下遍历
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;	//第0个元素的位置是首节点的位置（pCur->next）
	}

	LinkNode * tmp = (LinkNode *)malloc(sizeof(LinkNode));
	tmp->data = data;
	tmp->next = NULL;

	tmp->next = pCur->next;
	pCur->next = tmp;

	pHead->size++;

	return 0;
}

//按位置删除
int DELPOS_link(void * head, int pos)
{
	//判断位置合法性
	if (NULL == head)
	{
		return -1;
	}

	LinkInfo * pHead = (LinkInfo *)head;

	//判断位置的合法性
	if (pos < 0 || pos > pHead->size - 1)
	{
		return -1;
	}
	
	//判断空链表
	if (0 == pHead->size)
	{
		return -1;
	}

	LinkNode * pCur = &(pHead->head);//头节点

	for (int i = 0; i < pos; i++)	//循环结束时，pCur处在第pos个元素的位置
	{
		pCur = pCur->next;
	}

	LinkNode * tmp = pCur->next;	//保存待删除节点
	pCur->next = tmp->next;			//衔接前后节点

	tmp->next = NULL;
	free(tmp);

	pHead->size--;

	return 0;
}

//遍历
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

//按值删除
//int DELVAL_link(void * head, void * data, void(*COMPARE)(void * data1, void * data2));
int DELVAL_link(void * head, void * data, COMPARE com)
{
	if (NULL == head || NULL == data || NULL == com)
	{
		return -1;
	}

	LinkInfo * pHead = (LinkInfo *)head;
	LinkNode * pPre = &(pHead->head);	//头节点
	LinkNode * pCur = pPre->next; ;		//首节点

	for (int i = 0; i < pHead->size; i++)
	{
		if ((com(pCur->data, data)))
		{
			//break;			//退出循环时，pCur在待删除节点，pPre在前一个节点
			LinkNode * tmp = pCur;	//保存删除节点
			pCur = pCur->next;		//跳到下个节点
			pPre->next = pCur;		//衔接节点

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

//释放
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

	printf("内存释放成功\n");

	return 0;
}