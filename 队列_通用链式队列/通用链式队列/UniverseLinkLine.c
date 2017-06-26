#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UniverseLinkLine.h"

//初始化
void INIT_line(VULL * lin)
{
	//判断数据
	if (NULL == lin)
	{
		return;
	}

	LINE * tmp = (LINE *)malloc(sizeof(LINE));
	if (NULL == tmp)
	{
		return;
	}

	//初始化
	tmp->size = 0;
	tmp->head.next = NULL;
	tmp->tail = &(tmp->head);

	//间接赋值
	*lin = tmp;
}

//入队
void PUSH_line(VULL lin, void *data)
{
	//判断数据
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

	//插入数据
	list->tail->next = tmp;
	tmp->next = NULL;
	list->tail = tmp;

	//大小为0，特殊处理	//好像不需要了

	//大小加一
	list->size++;
}

//出队
void POP_line(VULL lin)
{
	//判断数据
	if (NULL == lin)
	{
		return;
	}

	LINE * list = (LINE *)lin;

	//判断大小
	if (0 == list->size)
	{
		return;
	}

	//删除数据
	NODE * tmp = list->head.next;//首节点
	list->head.next = tmp->next;

	//数据为1的情况
	if (1 == list->size)
	{
		list->tail = &(list->head);//结尾标识指针变量指向头节点
	}

	//更新大小
	list->size--;
}
//查询头
void * HEAD_line(VULL lin)
{
	//判断数据
	if (NULL == lin)
	{
		return NULL;
	}

	return ((NODE *)lin)->next;
}

//查询尾
void * END_line(VULL lin)
{
	//判断数据
	if (NULL == lin)
	{
		return NULL;
	}

	return ((LINE *)lin)->tail;
}

//销毁
void DESTR_line(VULL * lin)
{
	//判断数据
	if (NULL == lin || NULL == *lin)
	{
		return;
	}

	//释放
	free(*lin);
	*lin = NULL;
}