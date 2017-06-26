#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"

int main(void)
{
	int line = 0;
	char * filename = "dict_gbk.txt";
	CountLine(&line, filename);
	printf("%d\n", line);
	return 0;
}
