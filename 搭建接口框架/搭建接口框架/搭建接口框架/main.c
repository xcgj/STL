#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CommunicationInterface.h"	//通信接口初始化
#include "shellframe.h"				//参数传入框架
#include "CallbackFunctionRealize.h"//回调函数实现

int main(void)
{
	//准备信息
	char sendmes[10] = "xcgj";
	int sendlen = strlen(sendmes);
	char getmes[1024] = { 0 };
	int getlen = 0;

	//准备接口
	SERE inter;
	sere(&inter, init_mes, sent_mes, rece_mes, dele_mes);

	//输入框架
	frame(&inter, sendmes, sendlen, getmes, &getlen);

	printf("%s\n", getmes);
	printf("%d\n", getlen);

	return 0;
}
