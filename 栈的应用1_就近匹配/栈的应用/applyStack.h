#pragma once

//����ڵ���������
typedef struct SNODE
{
	struct SNODE * next;
}SNODE;

//������ջ�����Խṹ������
typedef struct LISTSTACK
{
	SNODE node;
	int size;
}LISTSTACK;

typedef void * VLS;

//��ʼ��
void INIT_stack(VLS * head);

VLS INIT_stack2();

//ѹջ
void PUSH_stack(VLS head, void * data);

//��ջ
void POP_stack(VLS head);

//��ѯջ��Ԫ��
void * SEAR_stack(VLS head);

//��ѯջ��С
int SIZE_stack(VLS head);

//����ջ
void DESTR_stack(VLS * head);
