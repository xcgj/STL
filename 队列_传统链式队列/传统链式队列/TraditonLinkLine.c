#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TraditonLinkLine.h"

//初始化
void INIT_line(VTLL * line)//二级指针间接赋值
{
	//判断数据
	if (NULL == line)
	{
		return;
	}

	//申请表头空间
	LINE * tmp = (LINE *)malloc(sizeof(LINE));
	if (NULL == tmp)
	{
		return;
	}

	//处理成员数据
	tmp->size = 0;

	tmp->head.next = NULL;
	tmp->head.data = NULL;

	tmp->tail = &(tmp->head);//尾节点标识指针指向头节点

	//间接赋值
	*line = tmp;
}

//尾节点入队
void PUSH_line(VTLL line, void * data)
{
	//判断数据
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

	//储存节点
	tmp->data = data;
	tmp->next = NULL;

	list->tail->next = tmp;//更新尾节点next指针的指向
	list->tail = tmp;		//更新尾节点标识指针指向

	//如果大小为0，需要更新头节点
	if (0 == list->size)
	{
		list->head.next = tmp;//头节点指向唯一一个有效节点
	}

	//更新大小
	list->size++;
}

//头节点出队，注意大小为1时尾节点标识符指向
void POP_line(VTLL line)
{
	//判断数据有效
	if (NULL == line)
	{
		return;
	}

	LINE * list = (LINE *)line;
	NODE * tmp = list->head.next;//缓存待删除节点，首节点

	//判断空链
	if (0 == list->size)
	{
		return;
	}

	//头节点改变指向
	list->head.next = tmp->next;
	free(tmp);

	if (1 == list->size)
	{
		list->tail = &(list->head);
	}

	//更新大小
	list->size--;
}

//查询队头和队尾的数据
void READ_line(VTLL line, void ** data1, void ** data2)//二级指针间接赋值
{
	//判断数据有效性
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

	//判断空链
	if (0 == list->size)
	{
		return;
	}

	//间接赋值
	*data1 = list->head.next->data;
	*data2 = list->tail->data;
}

//销毁队列
void DESTR_line(VTLL * line)
{
	//判断数据
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
	printf("释放成功\n");
}