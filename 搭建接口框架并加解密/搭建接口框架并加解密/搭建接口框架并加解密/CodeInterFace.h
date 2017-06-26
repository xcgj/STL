#pragma once

//���ļ��ܳ�����
typedef int(*ENCODE)(unsigned char * mes, int len, unsigned char * codemes, int * codelen);

//���Ľ��ܳ�����
typedef int(*DECODE)(unsigned char * codemes, int codelen, unsigned char * mes, int * len);

//����ָ��ṹ��
typedef struct CODE
{
	ENCODE encode;
	DECODE decode;
}CODE;

//�����ṹ���ʼ���������ýṹ��ָ����ú���ָ��
int secret(CODE * code, ENCODE incod, DECODE uncod);
