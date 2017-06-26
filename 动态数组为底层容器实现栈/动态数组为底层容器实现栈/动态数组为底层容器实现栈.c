#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicArray.h"
#include "buttonstack.h"

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

	//��ʼ��
	void * stack = INIT_stack();

	//��ջ
	PUSH_stack(stack, &p1);

	//��ջ
	POP_stack(stack);

	//����ջ
	DESTR_stack(&stack);

	printf("Compelete\n");
	return 0;
}
