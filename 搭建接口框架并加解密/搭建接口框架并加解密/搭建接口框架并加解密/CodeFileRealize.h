#pragma once

//���ļ��ܳ�����
int tocode(unsigned char * mes, int len, unsigned char * codemes, int * codelen);

//���Ľ��ܳ�����
int totext(unsigned char * codemes, int codelen, unsigned char * mes, int * len);