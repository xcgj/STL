#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SeqStack.h"

typedef struct Person
{
	char name[10];
	int size;
}Person;

int main(void)
{
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };

	//初始化
	VStack * stack = INIT_stack();

	//压栈
	PUSH_stack(stack, &p1);
	PUSH_stack(stack, &p2);
	PUSH_stack(stack, &p3);
	Person * tmp1 = SEAR_stack(stack);//30
	printf("name = %s, age = %d\n", tmp1->name, tmp1->size);

	//出栈
	POP_stack(stack);
	POP_stack(stack);
	Person * tmp2 = SEAR_stack(stack);//10
	printf("name = %s, age = %d\n", tmp2->name, tmp2->size);

	//销毁
	DESTR_stack(&stack);

	printf("Compelete\n");
	return 0;
}
