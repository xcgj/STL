#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StackLink.h"

typedef struct Person
{
	char name[10];
	int age;
}Person;

//定义结构体，需要包含节点数据类型，放第一成员
typedef struct DATA
{
	LISTNODE * next;	//四个字节大小的数据类型定义了一个节点指针
	Person p;
}DATA;

int main(void)
{
	//定义一组用户数据
	DATA p1 = { NULL, { "aaa", 10 } };
	DATA p2 = { NULL, { "bbb", 20 } };
	DATA p3 = { NULL, { "ccc", 30 } };

	//初始化表头
	VUSL head = INIT_USL();

	//插入
	PUSH_ustack(head, &p1);
	PUSH_ustack(head, &p2);
	PUSH_ustack(head, &p3);

	//删除
	POP_ustack(head);

	//查询
	DATA * tmp = (DATA *)SEAR_ustack(head);
	printf("%d, %s\n", tmp->p.age, tmp->p.name);
	printf("%d\n", SIZE_ustack(head));

	//销毁
	DESTR_ustack(&head);

	printf("Compelete\n");
	return 0;
}
