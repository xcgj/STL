#pragma once
#if 0
typedef int(*INIT)(void ** handle);
typedef int(*SENT)(void * handle/*����ȥ�ı���*/, int len/*֪ͨ�Է����ݳ���*/, char * buf/*�Է��������ձ�������*/);
typedef int(*RECE)(void * handle/*�������ı���*/, int * len/*�ҷ���ȡ���ݳ���*/, char * buf/*�ҷ��������ձ�������*/);
typedef int(*CLEA)(void ** handle);
#endif

int init_mes(void ** handle);

int sent_mes(void * handle, int sen_len, char * sen_buf);

int rece_mes(void *handle, int * get_len, char * get_buf);

int dele_mes(void ** handle);