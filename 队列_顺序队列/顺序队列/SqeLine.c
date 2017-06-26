#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SqeLine.h"

//初始化
//VAL * INIT_line();//返回的是地址，
void INIT_line(VAL * lin)
{
	LINE * line = (LINE *)malloc(sizeof(LINE));
	if (NULL == line)
	{
		return;
	}

	line->Line = (void **)malloc(MAX * sizeof(void *));//申请连续空间
	line->size = 0;//大小

	*lin = line;//间接赋值
}

//入队
void PUSH_line(VAL lin, void * data)
{
	//判断数据合法
	if (NULL == lin)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	LINE * operate = (LINE *)lin;

	//判断队列是否满
	if (MAX == operate->size)
	{
		return;
	}

	//队尾入队
	(operate->Line)[operate->size] = data;

	//大小加1
	operate->size++;
}

//出队
void POP_line(VAL lin)
{
	//判断数据合法
	if (NULL == lin)
	{
		return;
	}

	LINE * operate = (LINE *)lin;

	//判断空列
	if (0 == operate->size)
	{
		return;
	}

	//队头出队，数据前移
	for (int i = 0; i < operate->size - 1; i++)
	{
		(operate->Line)[i] = (operate->Line)[i + 1];
	}

	//大小减1
	operate->size--;
}

//查询队头
void * START_line(VAL lin)
{
	//判断数据合法
	if (NULL == lin)
	{
		return NULL;
	}

	LINE * operate = (LINE *)lin;

	//判断空列
	if (0 == operate->size)
	{
		return NULL;
	}

	//返回查询值
	return (operate->Line)[0];
}

//查询队尾
void END_line(VAL lin, PRINT pri)
{
	//判断数据合法
	if (NULL == lin)
	{
		return;
	}

	LINE * operate = (LINE *)lin;

	//判断空列
	if (0 == operate->size)
	{
		return;
	}

	//返回查询值
	pri((operate->Line)[operate->size - 1]);
}

//查询大小
int SIZE_line(VAL lin)
{
	//判断数据合法
	if (NULL == lin)
	{
		return 0;
	}

	//返回大小
	LINE * tmp = (LINE *)lin;
	return tmp->size;
}

//销毁队列
void DESTR_line(VAL * lin)
{

	//判断数据合法
	if (NULL == lin)
	{
		return;
	}

	if (NULL == *lin)
	{
		return;
	}

	LINE * tmp = (LINE *)(*lin);
	//先释放队列首地址的空间
	if (NULL != tmp->Line)
	{
		free(tmp->Line);
		tmp->Line = NULL;
	}

	//再释放结构体的空间
	tmp->size = 0;
	free(tmp);
	*lin = NULL;
	printf("队列销毁成功\n");
}