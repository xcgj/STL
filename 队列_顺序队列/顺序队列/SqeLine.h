#pragma once

#define MAX 1024
//���Զ��У�
//����Ҫ����ڵ�����
//����һ�������ڴ�ռ䣬ÿ��Ԫ���Ƿ���ָ��������洢���ݵĵ�ַ
//ָ����ͷΪ����ջ��a[0]
//ָ����βΪ����ջ��a[size]

//������е���������
typedef struct LINE
{
	void ** Line;//���е��׵�ַ��ָ�����飬MAX������������ void ** p
	int size;//���еĴ�С
}LINE;

typedef void * VAL;

typedef void(*PRINT)(void *);

//��ʼ��
//VAL * INIT_line();//���ص��ǵ�ַ��
void INIT_line(VAL * lin);

//���
void PUSH_line(VAL lin, void * data);

//����
void POP_line(VAL lin);

//��ѯ��ͷ
void * START_line(VAL lin);

//��ѯ�ӵ�
void END_line(VAL lin, PRINT pri);

//��ѯ��С
int SIZE_line(VAL lin);

//���ٶ���
void DESTR_line(VAL * lin);