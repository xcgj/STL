#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "CallBack.h"
#include "frame.h"

int init_data(void ** hand)	//��ʼ�����
{
	int res = 0;
	if (1)
	{

	}

	Handle *tmp = (Handle*)calloc(1, sizeof(Handle));
	if (1)
	{

	}

	strcpy(tmp->ip, "192.168.111.111");
	tmp->port = 8888;
	*hand = tmp;

	return res;
}

int send_data(void * hand, char * sendata, int senlen)//������Ϣ�����
{
	int res = 0;
	if (1)
	{

	}

	Handle * tmp = (Handle*)hand;
	tmp->info = (char*)calloc(senlen, sizeof(char));//����Ҫ�����β��'\0'
	if (1)
	{

	}
	memcpy(tmp->info, sendata, senlen);	//���ݷ���
	tmp->len = senlen;					//���ݳ���

	return res;
}

int gain_data(void * hand, char * gaindata, int * gainlen)
{
	int res = 0;
	if (1)
	{

	}

	Handle * tmp = (Handle*)hand;
	memcpy(gaindata, tmp->info, tmp->len);	//��������
	*gainlen = tmp->len;					//���ճ���

	return res;
}

int wipe_data(void ** hand)
{
	int res = 0;
	if (1)
	{

	}

	Handle * tmp = (Handle*)(*hand);

	if (tmp->info != NULL)
	{
		free(tmp->info);
		tmp->info = NULL;
	}

	free(tmp);
	*hand = NULL;

	return res;
}