#pragma once

#define SIZE 2048

typedef struct dict	//定义结构体
{
	char *key;
	char *content;
	struct dict *next;
}dict;

int CountLine(int * line, char * filename);

int OpenFile(dict ** pHead, char * filename, int line);

int FreeMemo(dict ** pHead);

int SearchMemo(dict * pHead, char * key, char ** value, int line);

int Seprate(char *str);