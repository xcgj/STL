#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shellframe.h"

int frame(SERE * set, char * inf_sent, int sent_len, char * inf_rece, int * rece_len)
{
	int res = 0;

	void * hand = NULL;		//�������

	set->init(&hand);		//�������ռ�

	set->sent(hand, sent_len, inf_sent);//���ͱ��ĸ����

	set->rece(hand, rece_len, inf_rece);//���վ���ı���

	set->clea(&hand);		//��վ��

	return res;
}