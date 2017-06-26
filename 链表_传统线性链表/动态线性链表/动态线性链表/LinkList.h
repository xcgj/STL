#pragma once

//�ȶ�������ڵ��������ͣ���Ȼͷ�ڵ�����������޷�����
typedef struct LinkNode
{
	struct LinkNode * next;
	void * data;
}LinkNode;

//�ٶ����ͷ�ṹ���������ͱ�����������
typedef struct LinkInfo
{
	struct LinkNode head;//ֱ�������˽ڵ�Ŀռ��С���������ָ����Ҫ��������ռ�
	int size;
}LinkInfo;

//�����ӡ����
typedef void(*PRINT)(void * data);

//����ȽϺ���
typedef int(*COMPARE)(void * data1, void * data2);

//��ʼ��
LinkInfo * INIT_link();

//����
int INSERT_link(void * head, int pos, void * data);

//��λ��ɾ��
int DELPOS_link(void * head, int pos);

//����
//int ERGODIC_link(void * head, void(*PRINT)(void * data));
int ERGODIC_link(void * head, PRINT pri);

//��ֵɾ��
//int DELVAL_link(void * head, void * data, void(*COMPARE)(void * data1, void * data2));
int DELVAL_link(void * head, void * data, COMPARE com);

//�ͷ�
int FREE_link(void ** head);