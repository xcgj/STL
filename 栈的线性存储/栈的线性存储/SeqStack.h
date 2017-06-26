#pragma once

#define MAX 1024

//����ṹ�壬����˳��ջ������Ϣ��ָ��ջ�ĵ�ַ��ջ���Ĵ�С
typedef struct SeqStack
{
	void * stak[MAX];	//ָ�����飬ÿ��Ԫ�ض�ָ���û����ݵ��׵�ַ
	int size;
}SeqStack;

typedef void * VStack;

//��ʼ��
VStack INIT_stack();

//ѹջ
void PUSH_stack(VStack sk, void * data);

//��ջ
void POP_stack(VStack sk);

//��ѯջ������
void * SEAR_stack(VStack sk);

//����ջ
void DESTR_stack(VStack * sk);