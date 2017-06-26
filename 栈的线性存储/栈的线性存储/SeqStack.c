#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SeqStack.h"

//��ʼ��
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

//ѹջ
void PUSH_stack(VStack sk, void * data)
{
	//�ж����ݺϷ�
	if (NULL == sk)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	SeqStack * tmp = (SeqStack *)sk;

	//�ж�ջ��
	if (tmp->size == MAX)
	{
		return;
	}

	//��ջ
	tmp->stak[tmp->size] = data;

	tmp->size++;
}

//��ջ
void POP_stack(VStack sk)
{
	//�ж�������Ч��
	if (NULL == sk)
	{
		return;
	}

	SeqStack * tmp = (SeqStack *)sk;

	//�ж�ջ��
	if (tmp->size == 0)
	{
		return;
	}

	tmp->size--;
}

//��ѯջ������
void * SEAR_stack(VStack sk)
{
	//�ж�������Ч��
	if (NULL == sk)
	{
		return NULL;
	}

	SeqStack * tmp = (SeqStack *)sk;

	//�ж�ջ��
	if (tmp->size == 0)
	{
		return NULL;
	}

	return tmp->stak[tmp->size - 1];
}

//����ջ
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