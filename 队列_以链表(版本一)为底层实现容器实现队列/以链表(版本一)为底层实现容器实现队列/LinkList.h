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

//��ʼ��
LinkInfo * INIT_link();

//����
int INSERT_link(void * head, int pos, void * data);

//��λ��ɾ��
int DELPOS_link(void * head, int pos);

//�ͷ�
int FREE_link(void ** head);