#pragma once

//��ͷ
typedef struct DArray	//��̬����ṹ��
{
	void ** array;//�������涯̬��������ռ䣬�洢���ݣ�����Ҫnextָ�룬��Ϊ�ռ����������±꼴�ɷ���
	//void**ָ��Ŀռ�����������void*, void*ָ��Ŀռ�����������void��void*��ת��Ϊ��������
	int capacity;//����
	int size;//��С��ͳ�ơ���Ч���ڵ�ĸ���
}DArray;

//��ʼ������
void* INIT_array();

//��������ָ��λ�ò���Ԫ��
int INSERT_array(void * hand, int pos, void * data);

//������ɾ��ָ��λ�õ�Ԫ��
int DELPOS_array(void * hand, int pos);

//�ͷ�����
int FREE_array(void ** hand);


