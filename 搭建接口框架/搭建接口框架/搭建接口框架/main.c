#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CommunicationInterface.h"	//ͨ�Žӿڳ�ʼ��
#include "shellframe.h"				//����������
#include "CallbackFunctionRealize.h"//�ص�����ʵ��

int main(void)
{
	//׼����Ϣ
	char sendmes[10] = "xcgj";
	int sendlen = strlen(sendmes);
	char getmes[1024] = { 0 };
	int getlen = 0;

	//׼���ӿ�
	SERE inter;
	sere(&inter, init_mes, sent_mes, rece_mes, dele_mes);

	//������
	frame(&inter, sendmes, sendlen, getmes, &getlen);

	printf("%s\n", getmes);
	printf("%d\n", getlen);

	return 0;
}
