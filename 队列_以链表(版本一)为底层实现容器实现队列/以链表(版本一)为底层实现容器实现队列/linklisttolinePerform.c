#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkList.h"
#include "linklisttoline.h"

typedef struct Person
{
	char name[10];
	int age;
}Person;

int main(void)
{
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };

	LinkInfo * head = NULL;
	
	//初始化
	head = INIT_line();

	//插入
	PUSH_line(head, &p1);
	PUSH_line(head, &p2);
	PUSH_line(head, &p3);

	//按位置删除
	POP_line(head);

	//释放
	DESTR_line(&head);

	printf("Compelete\n");
	return 0;
}
