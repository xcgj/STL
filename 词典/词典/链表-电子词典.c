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

	dict * pHead = NULL;
	OpenFile(&pHead, filename, line);
	printf("%p\n", pHead);

	while (1)
	{
		char key[SIZE] = { 0 };
		char valu[SIZE] = { 0 };
		char *p = valu;
		printf("请输入检索单词：\n");
		scanf("%s", key);

		if (strcmp(key, "-1") == 0)
			break;

		SearchMemo(pHead, key, &p, line);
		if (p == NULL)
			printf("词典中没有这个单词\n");
		else
			Seprate(p);
	}

	FreeMemo(&pHead);
	printf("%p\n", pHead);

	return 0;
}