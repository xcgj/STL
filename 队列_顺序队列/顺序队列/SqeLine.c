#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SqeLine.h"

//��ʼ��
//VAL * INIT_line();//���ص��ǵ�ַ��
void INIT_line(VAL * lin)
{
	LINE * line = (LINE *)malloc(sizeof(LINE));
	if (NULL == line)
	{
		return;
	}

	line->Line = (void **)malloc(MAX * sizeof(void *));//���������ռ�
	line->size = 0;//��С

	*lin = line;//��Ӹ�ֵ
}

//���
void PUSH_line(VAL lin, void * data)
{
	//�ж����ݺϷ�
	if (NULL == lin)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	LINE * operate = (LINE *)lin;

	//�ж϶����Ƿ���
	if (MAX == operate->size)
	{
		return;
	}

	//��β���
	(operate->Line)[operate->size] = data;

	//��С��1
	operate->size++;
}

//����
void POP_line(VAL lin)
{
	//�ж����ݺϷ�
	if (NULL == lin)
	{
		return;
	}

	LINE * operate = (LINE *)lin;

	//�жϿ���
	if (0 == operate->size)
	{
		return;
	}

	//��ͷ���ӣ�����ǰ��
	for (int i = 0; i < operate->size - 1; i++)
	{
		(operate->Line)[i] = (operate->Line)[i + 1];
	}

	//��С��1
	operate->size--;
}

//��ѯ��ͷ
void * START_line(VAL lin)
{
	//�ж����ݺϷ�
	if (NULL == lin)
	{
		return NULL;
	}

	LINE * operate = (LINE *)lin;

	//�жϿ���
	if (0 == operate->size)
	{
		return NULL;
	}

	//���ز�ѯֵ
	return (operate->Line)[0];
}

//��ѯ��β
void END_line(VAL lin, PRINT pri)
{
	//�ж����ݺϷ�
	if (NULL == lin)
	{
		return;
	}

	LINE * operate = (LINE *)lin;

	//�жϿ���
	if (0 == operate->size)
	{
		return;
	}

	//���ز�ѯֵ
	pri((operate->Line)[operate->size - 1]);
}

//��ѯ��С
int SIZE_line(VAL lin)
{
	//�ж����ݺϷ�
	if (NULL == lin)
	{
		return 0;
	}

	//���ش�С
	LINE * tmp = (LINE *)lin;
	return tmp->size;
}

//���ٶ���
void DESTR_line(VAL * lin)
{

	//�ж����ݺϷ�
	if (NULL == lin)
	{
		return;
	}

	if (NULL == *lin)
	{
		return;
	}

	LINE * tmp = (LINE *)(*lin);
	//���ͷŶ����׵�ַ�Ŀռ�
	if (NULL != tmp->Line)
	{
		free(tmp->Line);
		tmp->Line = NULL;
	}

	//���ͷŽṹ��Ŀռ�
	tmp->size = 0;
	free(tmp);
	*lin = NULL;
	printf("�������ٳɹ�\n");
}