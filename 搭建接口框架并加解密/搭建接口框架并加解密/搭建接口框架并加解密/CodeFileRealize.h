#pragma once

//明文加密成密文
int tocode(unsigned char * mes, int len, unsigned char * codemes, int * codelen);

//密文解密成明文
int totext(unsigned char * codemes, int codelen, unsigned char * mes, int * len);