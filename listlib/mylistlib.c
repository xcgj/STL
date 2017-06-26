#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylistlib.h"

typedef struct Node
{
	int id;				//数据域
	struct Node *next;	//指针域
}SLIST;

void SListDestroy(XCGJ * pH)		//释放所有节点
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

//删除值为x的所有结点
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

//链表节点排序，交换的是数据域
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

	int index = 1;	//元素个数
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
		pPre = loop;		//获得外循环起始位置
		pCur = pPre->next;	//获得外循环起始位置
		for (int j = i + 1; j < index; j++)
		{
			if (pPre->id > pCur->id)
			{
				SLIST temp = *pPre;
				//temp.id = pPre->id;
				pPre->id = pCur->id;	//只交换数据域，只适用链表只带一个成员的情况
				pCur->id = temp.id;
			}
			pCur = pCur->next;//内循环往下走
		}
		loop = loop->next;	//每次外循环走一步
	}
	/*
	//注意，排序，next指针还需要交换
	if (pPre->id > pCur->id) //升序
	{
	//先交换节点整体
	SLIST tmp = *pCur;
	*pCur = *pPre;
	*pPre = tmp;

	//再重新交换一下next指针域将链表指向恢复
	tmp.next = pCur->next;
	pCur->next = pPre->next;
	pPre->next = tmp.next;
	}*/
	return 0;
}

//假如原来链表是升序的,升序插入新节点
//不能插入节点后再排序，是升序插入新节点x
int SListNodeInsertPro(XCGJ * pH, int x, int y)//	x是id的值
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

	while (pCur)//pPre是NULL也结束循环
	{
		if (x == pCur->id)
		{
			break;	//找到了就跳出循环
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

int SListNodeReverse(XCGJ * pH)//头节点不逆置
{
	SLIST *pHead = (SLIST*)pH;
	int res = 0;
	if (pHead == NULL || pHead->next == NULL)//只有一个节点无需逆置
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
		pCur = temp;//最后 == NULL
	}

	//处理头尾节点
	temp = pHead->next;	//第二个节点
	pHead->next = pPre;
	temp->next = NULL;
	return 0;
}

int SListPrint(XCGJ * pH)//遍历所有节点
{
	SLIST *p = (SLIST *)pH;
	int res = 0;
	if (p == NULL)
	{
		printf("err, NULL pointer\n");
		res = -1;
		return res;
	}

	p = p->next;	//从首节点打印
	for (int i = 0; p; i++)
	{
		printf("第%d个节点的值为：%d\n", i + 1, p->id);
		p = p->next;
		res++;
	}

	return res;	//返回成功打印的个数
}

void * SListCreat()//创建节点
{
	SLIST *temp = (SLIST*)calloc(1, sizeof(SLIST));
	if (temp == NULL)
	{
		printf("err, allocate failed\n");
		exit(0);
	}

	temp->next = NULL;
	SLIST *t = temp;//保存头节点

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
	temp->next = tp;	//建立节点连接
	temp = temp->next;	//跳到下个节点
	if (NULL == temp)
	{
	printf("err, allocate failed\n");
	SListDestroy(t);
	return NULL;
	}
	temp->id = 2 * i;
	}
	temp->next = NULL;		//尾节点
	*/
	return t;
}