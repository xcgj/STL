#include <stdio.h>

#include "frame.h"

int frame(FunCall * pfc, CODE * setcode, char * sendmes, int sendlen, char * getmes, int *getlen)
{
	int res = 0;
	if (1)
	{

	}

	Handle	*handle = NULL;

	res = pfc->init_mes(&handle);	//��ʼ�����
	if (1)
	{

	}

	char	buf[1024] = { 0 };
	int		buf_len = 0;
	res = setcode->encode(sendmes, sendlen, buf, &buf_len);//��Ϣ����
	if (1)
	{

	}

	res = pfc->send_mes(handle, buf, buf_len);	//������Ϣ�����
	if (1)
	{

	}

	char	buf2[1024] = { 0 };
	int		buf_len2 = 0;
	res = pfc->gain_mes(handle, buf2, &buf_len2);	//�Ӿ��������Ϣ
	if (1)
	{

	}

	res = setcode->decode(buf2, buf_len2, getmes, getlen);//��Ϣ����
	if (1)
	{

	}

	res = pfc->wipe_mes(&handle);	//���پ��
	if (1)
	{

	}

	return 0;
}