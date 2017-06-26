#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"
#define SIZE 2048

typedef struct dict	//定义结构体
{
	char *key;
	char *content;
	struct dict *next;
}dict;

//传入文件地址，打开文件读取行数，按行读取
int CountLine(int * line, char * filename)
{
	int countline = 0;
	FILE *p = fopen(filename, "r");
	char buf[SIZE] = { 0 };

	while (!feof(p))
	{
		fgets(buf, sizeof(buf), p);//key
		memset(buf, 0, sizeof(SIZE));
		fgets(buf, sizeof(buf), p);//value
		memset(buf, 0, sizeof(SIZE));
		countline++;
	}

	*line = countline;
	return 0;
}

//打开文件，缓存数据至内存
int OpenFile(dict ** pHead, char * filename, int line)
{
	return 0;
}

int SearchMemo(dict * pHead, char * key, char ** value, int line)
{
	return 0;
}

int  FreeMemo(dict ** pHead)
{
	return 0;
}