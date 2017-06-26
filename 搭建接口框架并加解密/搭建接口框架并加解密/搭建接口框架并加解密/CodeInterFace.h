#pragma once

//明文加密成密文
typedef int(*ENCODE)(unsigned char * mes, int len, unsigned char * codemes, int * codelen);

//密文解密成明文
typedef int(*DECODE)(unsigned char * codemes, int codelen, unsigned char * mes, int * len);

//函数指针结构体
typedef struct CODE
{
	ENCODE encode;
	DECODE decode;
}CODE;

//声明结构体初始化函数，用结构体指针调用函数指针
int secret(CODE * code, ENCODE incod, DECODE uncod);
