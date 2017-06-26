#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SqeLine.h"

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
	//����һ���û�����
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };

	//��ʼ��
	VAL p;
	INIT_line(&p);

	//���
	PUSH_line(p, &p1);
	PUSH_line(p, &p2);
	PUSH_line(p, &p3);
	printf("\n=========���=========\n");//10 20 30
	print(START_line(p));
	END_line(p, print);
	printf("Size = %d\n\n", SIZE_line(p));

	//����
	POP_line(p);
	printf("=========����=========\n");//20 30
	print(START_line(p));
	END_line(p, print);
	printf("Size = %d\n\n", SIZE_line(p));

	//����
	DESTR_line(&p);
	printf("Size = %d\n\n", SIZE_line(p));

	printf("Compelete\n");
	return 0;
}
