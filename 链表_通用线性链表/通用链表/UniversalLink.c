#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UniversalLink.h"

//初始化表头
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

//指定位置插入
void INSERT_list(VList head, int pos, void * data)
{
	//判断输入合法性
	if (NULL == head)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	LinkList * list = (LinkList *)head;

	//判断位置合法性
	if (pos < 0 || pos > list->size)
	{
		pos = list->size;
	}

	//查找位置
	LinkNode * pCur = &(list->header);//将&(list->header)的LinkNode结构体地址赋值给pCur, pCur指向了头节点
	for (int i = 0; i < pos; i++)//头节点后面是0号元素
	{
		pCur = pCur->next;
	}

	//因为用户传入的数据的首地址也是节点的首地址，所以要利用数据里的节点
	LinkNode * node_info = (LinkNode *)data;
	node_info->next = pCur->next;
	pCur->next = node_info;

	list->size++;
}

//指定位置删除
void DELPOS_list(VList head, int pos)
{
	//判断数据输入的合法性
	if (NULL == head)
	{
		return;
	}

	LinkList * list = (LinkList *)head;

	//判断是否空链
	if (0 == list->size)
	{
		return;
	}

	//判断位置合法性
	if (pos < 0 || pos >= list->size)
	{
		return;
	}
	
	//查找位置
	LinkNode * pCur = &(list->header);//pCur指向表头结构体中的节点结构体（头节点）
	for (int i = 0; i < pos; i++)//循环结束时，pCur停在待删除位置的前一个位置
	{
		pCur = pCur->next;
	}

	//删除位置、衔接
	LinkNode * tmp = pCur->next;//存储待删除节点
	pCur->next = tmp->next;//前节点跳过中间节点连接后节点
	tmp->next = NULL;
	//free(tmp);//删除tmp指针指向的节点，不需要删除，没有申请堆空间

	list->size--;
}

//遍历
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
	LinkNode * pCur = &(list->header);//头节点

	for (int i = 0; i < list->size; i++)
	{
		pCur = pCur->next;
		pri(pCur);
	}
}

//按值删除
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

	//遍历
	LinkNode * pPre = &(list->header);//头节点
	LinkNode * pCur = pPre;
	for (int i = 0; i < list->size; i++)//建议用while(NULL != pCur)
	{
		pCur = pCur->next;
		if (com(pCur, data))//数据相同
		{
			/*不建议这么做，list->size会变化，影响尾部数据的读取
			pPre = pCur->next;
			pCur = pPre;	//舍弃节点，没有申请堆空间，所以不free
			list->size--;
			*/
			break;
		}
		pPre = pCur;
	}

	pPre->next = pCur->next;
	list->size--;
}

//逆序打印链表，(注意:不反转链表)
void REPRIN_list(VList head, PRINT pri)
{
	//判断数据
	if (NULL == head)
	{
		return;
	}

	if (NULL == pri)
	{
		return;
	}

	LinkNode * re = ((LinkNode *)head)->next;//下一个数据
	REPRIN_list(re, pri);//递归
	pri(re);//回调打印函数
}

//链表选择排序
void SELECT_list(VList head, COMPARE secom)
{
	//判断数据
	if (NULL == head)
	{
		return;
	}

	if (NULL == secom)
	{
		return;
	}

	//获取链表长度，这个链表不是连续空间，记录下标交换效率不高
	LinkList * list = (LinkList *)head;
	int n = list->size;
	if (n <= 1)//空链或只有一个元素不用排序
	{
		return;
	}

	LinkNode * pFrom = &(list->header); //头节点

#if 0
	LinkNode * pTo = NULL; //头节点

	for (int i = 0; i < n - 1; i++)
	{
		pFrom = pFrom->next;	//首节点开始比较
		pTo = pFrom;			//同步起始节点
		for (int j = i + 1; j < n; j++)
		{
			pTo = pTo->next;	//节点依次后移
			if (secom(pFrom, pTo))
			{
				/*
				方法一：如果用户将自有数据打包和指针域传递进来，只需要交换数据域即可，不用交换指针域
				Person tmp = { NULL, NULL }; 
				tmp.dat = ((Person *)pFrom)->dat;
				((Person *)pFrom)->dat = ((Person *)pTo)->dat;
				((Person *)pTo)->dat = tmp.dat;
				*/

				//方法二：
				//交换节点《整体》
				Person tmp = *((Person*)pFrom);//指针指向交换
				*((Person*)pFrom) = *((Person*)pTo);
				*((Person*)pTo) = tmp;
				//交换指针域
				tmp.next = pFrom->next;
				pFrom->next = pTo->next;
				pTo->next = tmp.next;
			}
		}
	}
#endif
	//优化链表选择排序算法
	for (LinkNode * pTo = pFrom->next; pTo != NULL; pTo = pTo->next)//终止条件不判断“pTo->next != NULL”,因为每次循环都要判断“pTo = pTo->next”是否为NULL
	{
		//临时变量保存极值节点，一开始假定pTo为极值
		LinkNode * pm = pTo;
		for (LinkNode * pc = pTo->next; pc != NULL; pc = pc->next)
		{
			if (secom(pm, pc))
			{
				pm = pc;//满足条件获得pc地址
			}
		}

		//循环结束，pm得到极值的地址，判断是否是原来pTo的地址
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

//链表逆置
void REVERSE_list(VList head)
{
	//判断输入
	if (NULL == head)
	{
		return;
	}

	LinkList * Head = (LinkList *)head;
	LinkNode * pCur = Head->header.next;//首节点
	//判断
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

	tmp = Head->header.next;//首节点；
	tmp->next = NULL;

	(&(Head->header))->next = pPre;
}

//释放
void FREE_list(VList * head)
{
	if (NULL == head)
	{
		return;
	}

	LinkList * list = (LinkList *)(*head);
	free(list);
	*head = NULL;
	printf("内存释放成功\n");
}