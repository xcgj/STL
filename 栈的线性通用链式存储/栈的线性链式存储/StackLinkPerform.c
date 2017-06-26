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

//����ṹ�壬��Ҫ�����ڵ��������ͣ��ŵ�һ��Ա
typedef struct DATA
{
	LISTNODE * next;	//�ĸ��ֽڴ�С���������Ͷ�����һ���ڵ�ָ��
	Person p;
}DATA;

int main(void)
{
	//����һ���û�����
	DATA p1 = { NULL, { "aaa", 10 } };
	DATA p2 = { NULL, { "bbb", 20 } };
	DATA p3 = { NULL, { "ccc", 30 } };

	//��ʼ����ͷ
	VUSL head = INIT_USL();

	//����
	PUSH_ustack(head, &p1);
	PUSH_ustack(head, &p2);
	PUSH_ustack(head, &p3);

	//ɾ��
	POP_ustack(head);

	//��ѯ
	DATA * tmp = (DATA *)SEAR_ustack(head);
	printf("%d, %s\n", tmp->p.age, tmp->p.name);
	printf("%d\n", SIZE_ustack(head));

	//����
	DESTR_ustack(&head);

	printf("Compelete\n");
	return 0;
}
