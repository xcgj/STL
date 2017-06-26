#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicArray.h"

//初始化数组
void * INIT_array()
{

	DArray *tmp = (DArray*)malloc(sizeof(DArray));//结构体申请空间
	if (NULL == tmp)
	{
		return NULL;
	}

	tmp->capacity = 5;
	tmp->size = 0;
	tmp->array = (void**)malloc(tmp->capacity * sizeof(void*));//给动态数组分配额外的空间

	return tmp;
}

//数组中在指定位置插入元素
int INSERT_array(void * hand, int pos, void * data)
{
	//判断传入数据的有效性
	if (NULL == hand || NULL == data)
	{
		return -1;
	}

	DArray * tmp = (DArray * )hand;

	//判断容量是否满
	if (tmp->size == tmp->capacity)//开辟空间，策略是两倍开辟
	{
		int newcapacity = tmp->capacity * 2;
		void ** newspace = (void **)malloc(newcapacity * sizeof(void *));

		memcpy(newspace, tmp->array, tmp->capacity * sizeof(void *));//拷贝内存

		free(tmp->array);
		tmp->capacity = newcapacity;
		tmp->array = newspace;
	}

	//判断插入位置的合法性
	if (pos < 0 || pos > tmp->size)//如果等于tmp->size，会直接在尾部插入，不会产生空节点
	{
		pos = tmp->size;
	}

	//移动数据
	for (int i = tmp->size - 1; i >= pos; i--)
	{
		tmp->array[i + 1] = tmp->array[i];
	}

	//插入数据
	tmp->array[pos] = data;

	tmp->size++;//大小加一
	return 0;
}

//数组中删除指定位置的元素
int DELPOS_array(void * hand, int pos)
{
	//判断传入数据的有效性
	if (NULL == hand)
	{
		return -1;
	}

	DArray * tmp = (DArray *)hand;

	//判断插入位置的有效性
	if (pos < 0 || pos >= tmp->size)//tmp->array[tmp->size]这个元素是空的
	{
		return -1;
	}

	//数组元素移动
	for (int i = pos; i < tmp->size - 1; i++)//tmp->array[tmp->size - 1]是最后一个有效数据，交换到tmp->array[tmp->size - 1]停止
	{
		tmp->array[i] = tmp->array[i + 1];
	}

	tmp->size--;
	return 0;
}

//释放数组
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