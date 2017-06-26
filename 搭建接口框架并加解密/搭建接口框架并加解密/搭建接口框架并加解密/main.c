#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "InterFace.h"
#include "CallBack.h"
#include "des.h"
#include "frame.h"
#include "CodeInterFace.h"
#include "CodeFileRealize.h"

int main(void)
{
	//������Ҫͨ�ŵı���
	unsigned char	sendmes[10] = "xcgj";
	int				sendlen = strlen(sendmes);
	unsigned char	getmes[1024] = { 0 };
	int				getlen = 0;

	//��ʼ��ͨ�Žӿڣ���Ҫ���庯��ָ�룬������Щ����ָ�����ṹ��ͳһ����
	FunCall fc;
	call(&fc, init_data, send_data, gain_data, wipe_data);

	//��ʼ���ӽ���ͨ�Žӿڣ���Ҫ���庯��ָ�룬������Щ����ָ�����ṹ��ͳһ����
	CODE pc;
	secret(&pc, tocode, totext);

	//���ݴ����ܴ���
	frame(&fc, &pc, sendmes, sendlen, getmes, &getlen);

	//���
	printf("%s\n", getmes);
	printf("%d\n", getlen);
	return 0;
}
#if 0
int main(void)	//�ӽ���δʹ�ú���ָ��
{
	//������Ҫͨ�ŵı���
	unsigned char	sendmes[10] = "xcgj";
	int				sendlen = strlen(sendmes);
	unsigned char	getmes[1024] = { 0 };
	int				getlen = 0;

	//��ʼ��ͨ�Žӿڣ���Ҫ���庯��ָ�룬������Щ����ָ�����ṹ��ͳһ����
	FunCall fc;
	call(&fc, init_data, send_data, gain_data, wipe_data);

	//���ܱ���
	unsigned char	encodemes[1024] = { 0 };
	int				encodelen = 0;
	DesEnc(sendmes, sendlen, encodemes, &encodelen);

	//���ݴ����ܴ���
	unsigned char	codemes[1024] = { 0 };
	int				codelen = 0;
	frame(&fc, encodemes, encodelen, codemes, &codelen);

	//���ܱ���
	DesDec(codemes, codelen, getmes, &getlen);

	//���
	printf("%s\n", getmes);
	printf("%d\n", getlen);
	return 0;
}
#endif