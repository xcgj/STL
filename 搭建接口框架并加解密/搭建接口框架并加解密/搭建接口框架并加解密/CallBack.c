#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "CallBack.h"
#include "frame.h"

int init_data(void ** hand)	//初始化句柄
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

int send_data(void * hand, char * sendata, int senlen)//发送信息给句柄
{
	int res = 0;
	if (1)
	{

	}

	Handle * tmp = (Handle*)hand;
	tmp->info = (char*)calloc(senlen, sizeof(char));//不需要处理结尾的'\0'
	if (1)
	{

	}
	memcpy(tmp->info, sendata, senlen);	//数据发送
	tmp->len = senlen;					//数据长度

	return res;
}

int gain_data(void * hand, char * gaindata, int * gainlen)
{
	int res = 0;
	if (1)
	{

	}

	Handle * tmp = (Handle*)hand;
	memcpy(gaindata, tmp->info, tmp->len);	//接收数据
	*gainlen = tmp->len;					//接收长度

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