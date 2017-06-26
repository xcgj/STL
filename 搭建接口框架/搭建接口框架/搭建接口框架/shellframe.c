#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shellframe.h"

int frame(SERE * set, char * inf_sent, int sent_len, char * inf_rece, int * rece_len)
{
	int res = 0;

	void * hand = NULL;		//句柄定义

	set->init(&hand);		//句柄分配空间

	set->sent(hand, sent_len, inf_sent);//发送报文给句柄

	set->rece(hand, rece_len, inf_rece);//接收句柄的报文

	set->clea(&hand);		//清空句柄

	return res;
}