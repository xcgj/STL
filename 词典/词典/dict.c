#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"

//传入文件地址，打开文件读取行数，按行读取
int CountLine(int * line, char * filename)
{
	int countline = 0;
	FILE *p = fopen(filename, "r");
	char buf[SIZE] = { 0 };
#if 0
	while (!feof(p))//当读到文件结尾时，文件游标p指向了文件尾部，
					//但是此时进行feof操作并不会触发文件结束标志，
					//需要再进行一次读文件操作函数feof才会返回真
	{
		fgets(buf, sizeof(buf), p);//key
		//memset(buf, 0, sizeof(SIZE));
		fgets(buf, sizeof(buf), p);//value
		//memset(buf, 0, sizeof(SIZE));
		countline++;
	}
#endif
#if 0
	while (1)//当读到文件结尾时，文件游标p指向了文件尾部，
					//但是此时进行feof操作并不会触发文件结束标志，
					//需要再进行一次读文件操作函数feof才会返回真
	{
		fgets(buf, sizeof(buf), p);//key
		//memset(buf, 0, sizeof(SIZE));
		if (feof(p))
			break;
		fgets(buf, sizeof(buf), p);//value
		//memset(buf, 0, sizeof(SIZE));
		countline++;
}
#endif
#if 1
	while (fgets(buf, sizeof(buf), p))
	{
		//memset(buf, 0, sizeof(SIZE));
		fgets(buf, sizeof(buf), p);
		//memset(buf, 0, sizeof(SIZE));
		countline++;
	}
#endif

	fclose(p);
	*line = countline;
	return 0;
}

//打开文件，缓存数据至内存
int OpenFile(dict ** pHead, char * filename, int line)
{
	dict * tmp = (dict*)calloc(1, sizeof(dict));//头节点
	tmp->next = NULL;
	dict * save = tmp;//保存头节点

	FILE * p = fopen(filename, "r");
	char buf[SIZE] = { 0 };

	while (fgets(buf, sizeof(buf), p))
	{
		dict * t = (dict*)calloc(1, sizeof(dict));//创建新节点

		int len_buf = 0;
		len_buf = strlen(buf) - 2;//CleanBuf(buf, &len_buf);
		t->key = (char*)calloc(len_buf + 1, sizeof(char));
		strncpy(t->key, buf + 1, len_buf);//key
		t->key[len_buf] = '\0';

		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), p);

		len_buf = 0;
		len_buf = strlen(buf) - 7;//CleanBuf(buf, &len_buf);
		t->content = (char*)calloc(len_buf + 1, sizeof(char));
		strncpy(t->content, buf + 6, len_buf);//value
		t->content[len_buf] = '\0';

		memset(buf, 0, sizeof(buf));

		t->next = NULL;


		tmp->next = t;
		tmp = tmp->next;
	}

	*pHead = save;
	fclose(p);
	printf("open success\n");
	return 0;
}

int SearchMemo(dict * pHead, char * key, char ** value, int line)
{
	dict * find = pHead->next;//首节点

	int flag = 1;
	for (int i = 0; i < line; i++)
	{
		if (strcmp(key, find->key) == 0)
		{
			printf("单词：%s\n", find->key);
			int len = strlen(find->content);
			strncpy(*value, find->content, len);
			(*value)[len] = '\0';
			flag = 0;
			break;
		}

		find = find->next;
	}

	if (flag)
	{
		*value = NULL;
	}

	return 0;
}

int FreeMemo(dict ** pHead)
{
	dict * pCur = *pHead;
	dict * temp = NULL;

	while (pCur)
	{
		temp = pCur;
		pCur = pCur->next;

		temp->next = NULL;//切断即将释放的节点与下一个节点的联系
		free(temp);//释放该节点
	}

	*pHead = NULL;//将实参指向pHead的指针置空
	printf("链表释放成功\n");

	return 0;
}

int Seprate(char *str)
{
	char buf[SIZE] = { 0 };
	char * temp = buf;
	strcpy(temp, str);	//拷贝一份，防止下面的修改对原字符串产生影响

	temp = strtok(temp, "@");
	while (temp)
	{
		printf("释义：%s\n", temp);
		temp = strtok(NULL, "@");
	}

	return 0;
}