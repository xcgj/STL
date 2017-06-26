#pragma once

//����ڵ�
typedef struct LinkNode
{
	struct LinkNode * next;
}LinkNode;

//�����ͷ
typedef struct LinkList
{
	struct LinkNode header;
	int size;
}LinkList;

typedef struct DATA
{
	char name[10];
	int age;
}DATA;

typedef struct Person
{
	LinkNode * next;
	DATA *dat;
}Person;

//������������
typedef void * VList;

//��ӡ
typedef void PRINT(void * data);

//�Ƚϣ����ʹ��(*COMPARE[])���βκ�ʵ�ε�ֵ��δ���
typedef int (*COMPARE)(void * data1, void * data2);

//��ʼ����ͷ
LinkList * INIT_list();

//ָ��λ�ò���
void INSERT_list(VList head, int pos, void * data);

//ָ��λ��ɾ��
void DELPOS_list(VList head, int pos);

//����
void ERGODIC_list(VList head, PRINT pri);

//��ֵɾ��
void DELVAL_list(VList head, void * data, COMPARE com);

//�����ӡ����(ע��:����ת����)
void REPRIN_list(VList head, PRINT pri);

//����ѡ������
void SELECT_list(VList head, COMPARE com);

//��������
void REVERSE_list(VList head);

//�ͷ�
void FREE_list(VList * head);