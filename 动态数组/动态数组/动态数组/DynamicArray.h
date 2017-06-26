#pragma once

//��ͷ
typedef struct DArray	//��̬����ṹ��
{
	void ** array;//�������涯̬��������ռ䣬�洢���ݣ�����Ҫnextָ�룬��Ϊ�ռ����������±꼴�ɷ���
	//void**ָ��Ŀռ�����������void*, void*ָ��Ŀռ�����������void��void*��ת��Ϊ��������
	int capacity;//����
	int size;//��С��ͳ�ơ���Ч���ڵ�ĸ���
}DArray;

typedef int(*PRINT)(void * data);

typedef int(*COMPARE)(void * data1, void * data2);

//��ӡ����
int print(void * data);

//�Ƚ�����
int compare(void * data1, void * data2);

//��ʼ������
void* INIT_array();

//��������ָ��λ�ò���Ԫ��
int INSERT_array(void * hand, int pos, void * data);

//������ɾ��ָ��λ�õ�Ԫ��
int DELPOS_array(void * hand, int pos);

//�����ݵ�ֵɾ��Ԫ��
int DELVAL_array(void * hand, void * data, COMPARE com);

//�����������
int ERGODIC_array(void * hand, PRINT pri);

//�ͷ�����
int FREE_array(void ** hand);


