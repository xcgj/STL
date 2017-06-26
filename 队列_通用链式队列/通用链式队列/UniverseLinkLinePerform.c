#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UniverseLinkLine.h"


//定义数据类型，包含节点
typedef struct DATA
{
	NODE node;//取地址强转直接调用next指针
	char name[10];
	int age;
}DATA;

void print(void * data)
{
	if (NULL == data)
	{
		return;
	}

	DATA * tmp = (DATA *)data;
	printf("name = %s, age = %d\n", tmp->name, tmp->age);
}

int main(void)
{
	//定义一组用户数据
	DATA p1 = { NULL, "aaa", 10 };
	DATA p2 = { NULL, "bbb", 20 };
	DATA p3 = { NULL, "ccc", 30 };

	VULL p = NULL;
	void * d1 = NULL;
	void * d2 = NULL;

	//初始化
	INIT_line(&p);

	//入队
	PUSH_line(p, &p1);
	PUSH_line(p, &p2);
	PUSH_line(p, &p3);
	d1 = HEAD_line(p);
	d2 = END_line(p);
	print(d1);
	print(d2);

	//出队
	POP_line(p);
	POP_line(p);
	d1 = HEAD_line(p);
	d2 = END_line(p);
	print(d1);
	print(d2);

	//释放
	DESTR_line(&p);

	printf("Compelete\n");
	return 0;
}
