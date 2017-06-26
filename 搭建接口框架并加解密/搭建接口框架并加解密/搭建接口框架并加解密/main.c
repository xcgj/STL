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
	//传入需要通信的报文
	unsigned char	sendmes[10] = "xcgj";
	int				sendlen = strlen(sendmes);
	unsigned char	getmes[1024] = { 0 };
	int				getlen = 0;

	//初始化通信接口，需要定义函数指针，并将这些函数指针放入结构体统一管理
	FunCall fc;
	call(&fc, init_data, send_data, gain_data, wipe_data);

	//初始化加解密通信接口，需要定义函数指针，并将这些函数指针放入结构体统一管理
	CODE pc;
	secret(&pc, tocode, totext);

	//数据传入框架传输
	frame(&fc, &pc, sendmes, sendlen, getmes, &getlen);

	//输出
	printf("%s\n", getmes);
	printf("%d\n", getlen);
	return 0;
}
#if 0
int main(void)	//加解密未使用函数指针
{
	//传入需要通信的报文
	unsigned char	sendmes[10] = "xcgj";
	int				sendlen = strlen(sendmes);
	unsigned char	getmes[1024] = { 0 };
	int				getlen = 0;

	//初始化通信接口，需要定义函数指针，并将这些函数指针放入结构体统一管理
	FunCall fc;
	call(&fc, init_data, send_data, gain_data, wipe_data);

	//加密报文
	unsigned char	encodemes[1024] = { 0 };
	int				encodelen = 0;
	DesEnc(sendmes, sendlen, encodemes, &encodelen);

	//数据传入框架传输
	unsigned char	codemes[1024] = { 0 };
	int				codelen = 0;
	frame(&fc, encodemes, encodelen, codemes, &codelen);

	//解密报文
	DesDec(codemes, codelen, getmes, &getlen);

	//输出
	printf("%s\n", getmes);
	printf("%d\n", getlen);
	return 0;
}
#endif