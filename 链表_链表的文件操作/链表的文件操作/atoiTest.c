#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main01(void)
{
	char * a = "   83   ";
	int b = atoi(a);//���ӿո�
	printf("%d", b);


	char *c = "a = b";
	char *d = strchr(c, '=');//cָ��λ�ò���
	printf("%s", c);
	return 0;
}

