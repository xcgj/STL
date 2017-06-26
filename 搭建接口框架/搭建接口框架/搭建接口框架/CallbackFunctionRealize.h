#pragma once
#if 0
typedef int(*INIT)(void ** handle);
typedef int(*SENT)(void * handle/*传出去的报文*/, int len/*通知对方内容长度*/, char * buf/*对方用来接收报文内容*/);
typedef int(*RECE)(void * handle/*传进来的报文*/, int * len/*我方获取内容长度*/, char * buf/*我方用来接收报文内容*/);
typedef int(*CLEA)(void ** handle);
#endif

int init_mes(void ** handle);

int sent_mes(void * handle, int sen_len, char * sen_buf);

int rece_mes(void *handle, int * get_len, char * get_buf);

int dele_mes(void ** handle);