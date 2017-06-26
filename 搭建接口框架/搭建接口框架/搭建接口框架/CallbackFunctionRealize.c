#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CallbackFunctionRealize.h"

typedef struct Message	//定义句柄结构体
{
	char ip[32];
	char date[16];
	char *text;
	int len;
}Message;

int init_mes(void ** handle)	//初始化出一个句柄
{
	Message *tmp = (Message*)calloc(1, sizeof(Message));

	strcpy(tmp->ip, "192.168.125.1");

	strcpy(tmp->date, "2017.04.20");

	*handle = tmp;

	return 0;
}

int sent_mes(void * handle, int sen_len, char * sen_buf)//发信息给句柄
{
	Message *tmp = (Message*)handle;

	tmp->text = (char*)calloc(1, sen_len + 1);

	memcpy(tmp->text, sen_buf, sen_len);

	(tmp->text)[sen_len] = '\0';

	tmp->len = sen_len;

	return 0;
}

int rece_mes(void *handle, int * get_len, char * get_buf)//从句柄接收信息
{
	Message *tmp = (Message*)handle;

	memcpy(get_buf, tmp->text, tmp->len);

	*get_len = tmp->len;

	return 0;
}

int dele_mes(void ** handle)	//销毁句柄
{
	Message * tmp = (Message*)(*handle);
	
	if (tmp->text != NULL)
	{
		free(tmp->text);
		tmp->text = NULL;
	}

	free(tmp);
	*handle = NULL;

	return 0;
}