#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TraditonLinkLine.h"

typedef struct Person
{
	char name[10];
	int age;
}Person;

void print(void * data)
{
	if (NULL == data)
	{
		return;
	}

	Person * tmp = (Person *)data;
	printf("name = %s, age = %d\n", tmp->name, tmp->age);
}

int main(void)
{
	//定义一组用户数据
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };

	VTLL p = NULL;
	void * read1, * read2;

	//初始化
	INIT_line(&p);

	//入队
	PUSH_line(p, &p1);
	PUSH_line(p, &p2);
	PUSH_line(p, &p3);//123
	READ_line(p, &read1, &read2);
	print(read1);
	print(read2);

	//出队
	POP_line(p);
	POP_line(p);
	READ_line(p, &read1, &read2);
	print(read1);
	print(read2);

	//销毁
	DESTR_line(&p);

	printf("Compelete\n");
	return 0;
}
