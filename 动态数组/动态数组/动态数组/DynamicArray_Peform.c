#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicArray.h"

typedef struct Person
{
	char name[10];
	int age;
}Person;

//打印数据
int print(void * data)
{
	if (NULL == data)
	{
		return -1;
	}

	Person * tmp = (Person *)data;

	printf("name = %s, age = %d\n", tmp->name, tmp->age);
	return 0;
}

//比较数据
int compare(void * data1, void * data2)
{
	Person * tmp1 = (Person *)data1;
	Person * tmp2 = (Person *)data2;
	return tmp1->age == tmp2->age && !(strcmp(tmp1->name, tmp2->name));
}

int main(void)
{
	Person p1 = { "aaa", 10 };
	Person p2 = { "aaa", 20 };
	Person p3 = { "aaa", 30 };
	Person p4 = { "aaa", 40 };
	Person p5 = { "aaa", 50 };
	Person p6 = { "aaa", 60 };
	
	//初始化结构体
	void * arry = INIT_array();
	
	//头插
	printf("头插：\n");
	INSERT_array(arry, 0, &p1);
	INSERT_array(arry, 0, &p2);
	ERGODIC_array(arry, print);	//20 10

	//尾插
	printf("尾插：\n");
	INSERT_array(arry, 666, &p3);
	INSERT_array(arry, 1000, &p4);
	ERGODIC_array(arry, print);//20 10 30 40

	//指定插入
	printf("指定插入：\n");
	INSERT_array(arry, 2, &p5);
	INSERT_array(arry, 2, &p6);
	ERGODIC_array(arry, print);//20 10 60 50 30 40

	//删除位置
	printf("删除位置：\n");
	DELPOS_array(arry, 3);
	DELPOS_array(arry, 100);
	ERGODIC_array(arry, print);//20 10 60 30 40

	//删除值
	printf("删除值：\n");
	DELVAL_array(arry, &p3, compare);
	ERGODIC_array(arry, print);//20 10 60 40

	//释放
	printf("释放：\n");
	FREE_array(&arry);

	printf("Compelete\n");
	return 0;
}