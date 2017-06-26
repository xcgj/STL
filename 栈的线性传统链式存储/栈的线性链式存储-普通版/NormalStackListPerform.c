#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NormalStackList.h"

typedef struct Person
{
	char name[10];
	int age;
}Person;



int main(void)
{
	//����һ���û�����
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };

	//��ʼ����ͷ
	VTSL head = INIT_tstack();

	//����
	PUSH_tstack(head, &p1);
	PUSH_tstack(head, &p2);
	PUSH_tstack(head, &p3);

	//ɾ��
	POP_tstack(head);

	//��ѯ
	Person * tmp = (Person *)SEAR_tstack(head);
	printf("%d, %s\n", tmp->age, tmp->name);
	printf("%d\n", SIZE_tstack(head));

	//����
	DESTR_tstack(&head);

	printf("Compelete\n");
	return 0;
}
