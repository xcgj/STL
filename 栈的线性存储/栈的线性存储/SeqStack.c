#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SeqStack.h"

//初始化
VStack INIT_stack()
{
	SeqStack * stack_prop = (SeqStack *)malloc(sizeof(SeqStack));
	if (NULL == stack_prop)
	{
		return NULL;
	}
	stack_prop->size = 0;
	return stack_prop;
}

//压栈
void PUSH_stack(VStack sk, void * data)
{
	//判断数据合法
	if (NULL == sk)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	SeqStack * tmp = (SeqStack *)sk;

	//判断栈满
	if (tmp->size == MAX)
	{
		return;
	}

	//入栈
	tmp->stak[tmp->size] = data;

	tmp->size++;
}

//出栈
void POP_stack(VStack sk)
{
	//判断数据有效性
	if (NULL == sk)
	{
		return;
	}

	SeqStack * tmp = (SeqStack *)sk;

	//判断栈空
	if (tmp->size == 0)
	{
		return;
	}

	tmp->size--;
}

//查询栈顶数据
void * SEAR_stack(VStack sk)
{
	//判断数据有效性
	if (NULL == sk)
	{
		return NULL;
	}

	SeqStack * tmp = (SeqStack *)sk;

	//判断栈空
	if (tmp->size == 0)
	{
		return NULL;
	}

	return tmp->stak[tmp->size - 1];
}

//销毁栈
void DESTR_stack(VStack * sk)
{
	if (NULL == sk)
	{
		return;
	}
	
	if (NULL == *sk)
	{
		return;
	}

	//SeqStack * tmp = (SeqStack *)(*sk);

	free(*sk);
	*sk = NULL;
}