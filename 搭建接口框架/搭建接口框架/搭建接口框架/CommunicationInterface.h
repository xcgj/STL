#pragma once

//���庯��ָ��
typedef int(*INIT)(void ** handle);
typedef int(*SENT)(void * handle/*����ȥ�ı���*/, int len/*֪ͨ�Է����ݳ���*/, char * buf/*�Է��������ձ�������*/);
typedef int(*RECE)(void * handle/*�������ı���*/, int * len/*�ҷ���ȡ���ݳ���*/, char * buf/*�ҷ��������ձ�������*/);
typedef int(*CLEA)(void ** handle);

//������ָ�����ͷ���ṹ��
typedef struct SERE
{
	INIT init;
	SENT sent;
	RECE rece;
	CLEA clea;
}SERE;

//�ṹ���ʼ������
int sere(SERE * stru, INIT ini, SENT sen, RECE rec, CLEA cle);