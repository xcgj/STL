
#include "CodeFileRealize.h"
#include "des.h"

//���ļ��ܳ�����
int tocode(unsigned char * mes, int len, unsigned char * codemes, int * codelen)
{
	return DesEnc(mes, len, codemes, codelen);
}

//���Ľ��ܳ�����
int totext(unsigned char * codemes, int codelen, unsigned char * mes, int * len)
{
	return DesDec(codemes, codelen, mes, len);
}