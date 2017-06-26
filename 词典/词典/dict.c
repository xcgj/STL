#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"

//�����ļ���ַ�����ļ���ȡ���������ж�ȡ
int CountLine(int * line, char * filename)
{
	int countline = 0;
	FILE *p = fopen(filename, "r");
	char buf[SIZE] = { 0 };
#if 0
	while (!feof(p))//�������ļ���βʱ���ļ��α�pָ�����ļ�β����
					//���Ǵ�ʱ����feof���������ᴥ���ļ�������־��
					//��Ҫ�ٽ���һ�ζ��ļ���������feof�Ż᷵����
	{
		fgets(buf, sizeof(buf), p);//key
		//memset(buf, 0, sizeof(SIZE));
		fgets(buf, sizeof(buf), p);//value
		//memset(buf, 0, sizeof(SIZE));
		countline++;
	}
#endif
#if 0
	while (1)//�������ļ���βʱ���ļ��α�pָ�����ļ�β����
					//���Ǵ�ʱ����feof���������ᴥ���ļ�������־��
					//��Ҫ�ٽ���һ�ζ��ļ���������feof�Ż᷵����
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

//���ļ��������������ڴ�
int OpenFile(dict ** pHead, char * filename, int line)
{
	dict * tmp = (dict*)calloc(1, sizeof(dict));//ͷ�ڵ�
	tmp->next = NULL;
	dict * save = tmp;//����ͷ�ڵ�

	FILE * p = fopen(filename, "r");
	char buf[SIZE] = { 0 };

	while (fgets(buf, sizeof(buf), p))
	{
		dict * t = (dict*)calloc(1, sizeof(dict));//�����½ڵ�

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
	dict * find = pHead->next;//�׽ڵ�

	int flag = 1;
	for (int i = 0; i < line; i++)
	{
		if (strcmp(key, find->key) == 0)
		{
			printf("���ʣ�%s\n", find->key);
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

		temp->next = NULL;//�жϼ����ͷŵĽڵ�����һ���ڵ����ϵ
		free(temp);//�ͷŸýڵ�
	}

	*pHead = NULL;//��ʵ��ָ��pHead��ָ���ÿ�
	printf("�����ͷųɹ�\n");

	return 0;
}

int Seprate(char *str)
{
	char buf[SIZE] = { 0 };
	char * temp = buf;
	strcpy(temp, str);	//����һ�ݣ���ֹ������޸Ķ�ԭ�ַ�������Ӱ��

	temp = strtok(temp, "@");
	while (temp)
	{
		printf("���壺%s\n", temp);
		temp = strtok(NULL, "@");
	}

	return 0;
}