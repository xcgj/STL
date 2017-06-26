#pragma once

//定义函数指针
typedef int(*INIT)(void ** handle);
typedef int(*SENT)(void * handle/*传出去的报文*/, int len/*通知对方内容长度*/, char * buf/*对方用来接收报文内容*/);
typedef int(*RECE)(void * handle/*传进来的报文*/, int * len/*我方获取内容长度*/, char * buf/*我方用来接收报文内容*/);
typedef int(*CLEA)(void ** handle);

//将函数指针类型放入结构体
typedef struct SERE
{
	INIT init;
	SENT sent;
	RECE rece;
	CLEA clea;
}SERE;

//结构体初始化声明
int sere(SERE * stru, INIT ini, SENT sen, RECE rec, CLEA cle);