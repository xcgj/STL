#pragma once
//ͷ�巨����ͳ����		//����
//�ȶ���ڵ���������
typedef struct NODE
{
	struct NODE *next;
	void * data;
}NODE;

//�ٶ����ͷ��������
typedef struct Head
{
	NODE header;//ָ��һ���ڴ�ռ䣬ֱ�Ӷ����������Ҫ����ָ�룬���������ͷſռ�
	int size;
}Head;

typedef void* VTSL;// void traditional stack list

//��ʼ��
VTSL INIT_tstack();

//����
void PUSH_tstack(VTSL head, void *data);

//ɾ��
void POP_tstack(VTSL head);

//��ѯ����
void * SEAR_tstack(VTSL head);

//��ѯ��С
int SIZE_tstack(VTSL head);

//����
void DESTR_tstack(VTSL * head);
