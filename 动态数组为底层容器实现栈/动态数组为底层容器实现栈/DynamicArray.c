#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicArray.h"

//��ʼ������
void * INIT_array()
{

	DArray *tmp = (DArray*)malloc(sizeof(DArray));//�ṹ������ռ�
	if (NULL == tmp)
	{
		return NULL;
	}

	tmp->capacity = 5;
	tmp->size = 0;
	tmp->array = (void**)malloc(tmp->capacity * sizeof(void*));//����̬����������Ŀռ�

	return tmp;
}

//��������ָ��λ�ò���Ԫ��
int INSERT_array(void * hand, int pos, void * data)
{
	//�жϴ������ݵ���Ч��
	if (NULL == hand || NULL == data)
	{
		return -1;
	}

	DArray * tmp = (DArray * )hand;

	//�ж������Ƿ���
	if (tmp->size == tmp->capacity)//���ٿռ䣬��������������
	{
		int newcapacity = tmp->capacity * 2;
		void ** newspace = (void **)malloc(newcapacity * sizeof(void *));

		memcpy(newspace, tmp->array, tmp->capacity * sizeof(void *));//�����ڴ�

		free(tmp->array);
		tmp->capacity = newcapacity;
		tmp->array = newspace;
	}

	//�жϲ���λ�õĺϷ���
	if (pos < 0 || pos > tmp->size)//�������tmp->size����ֱ����β�����룬��������սڵ�
	{
		pos = tmp->size;
	}

	//�ƶ�����
	for (int i = tmp->size - 1; i >= pos; i--)
	{
		tmp->array[i + 1] = tmp->array[i];
	}

	//��������
	tmp->array[pos] = data;

	tmp->size++;//��С��һ
	return 0;
}

//������ɾ��ָ��λ�õ�Ԫ��
int DELPOS_array(void * hand, int pos)
{
	//�жϴ������ݵ���Ч��
	if (NULL == hand)
	{
		return -1;
	}

	DArray * tmp = (DArray *)hand;

	//�жϲ���λ�õ���Ч��
	if (pos < 0 || pos >= tmp->size)//tmp->array[tmp->size]���Ԫ���ǿյ�
	{
		return -1;
	}

	//����Ԫ���ƶ�
	for (int i = pos; i < tmp->size - 1; i++)//tmp->array[tmp->size - 1]�����һ����Ч���ݣ�������tmp->array[tmp->size - 1]ֹͣ
	{
		tmp->array[i] = tmp->array[i + 1];
	}

	tmp->size--;
	return 0;
}

//�ͷ�����
int FREE_array(void ** hand)
{
	if (NULL == hand || NULL == *hand)
	{
		return -1;
	}

	DArray * tmp = (DArray *)(*hand);
	if (NULL != tmp->array)
	{
		free(tmp->array);
		tmp->array = NULL;
	}

	free(tmp);
	*hand = NULL;

	return 0;
}