#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkList.h"

typedef struct Person
{
	char name[10];
	int age;
}Person;

//定义打印函数
void print(void * data)
{
	if (NULL == data)
	{
		return;
	}

	Person *tmp = (Person *)data;
	printf("name = %s, age = %d\n", tmp->name, tmp->age);
}

//定义比较函数
int compare(void * data1, void * data2)
{
	if (NULL == data1 || NULL == data2)
	{
		return -1;
	}

	Person * tmp1 = (Person *)data1;
	Person * tmp2 = (Person *)data2;
	return tmp1->age == tmp2->age && !(strcmp(tmp1->name, tmp2->name));
}

int main(void)
{
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };
	Person p4 = { "ddd", 40 };
	Person p5 = { "eee", 50 };
	Person p6 = { "fff", 60 };

	LinkInfo * head = NULL;
	
	//初始化
	head = INIT_link();

	//插入
	INSERT_link(head, 0, &p1);
	INSERT_link(head, 0, &p2);

	INSERT_link(head, 66, &p3);
	INSERT_link(head, -10, &p4);

	INSERT_link(head, 1, &p5);
	INSERT_link(head, 1, &p6);

	ERGODIC_link(head, print);// 2 6 5 1 3 4

	//按位置删除
	DELPOS_link(head, 3);
	ERGODIC_link(head, print);// 2 6 5 3 4

	//按值删除
	DELVAL_link(head, &p2, compare);
	ERGODIC_link(head, print);// 6 5 3 4

	//释放
	FREE_link(&head);

	printf("Compelete\n");
	return 0;
}
