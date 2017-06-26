#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "List.h"
#include "RecallFunction.h"

void test(void)//���Դ���
{
	DATA p1 = { 1 };
	DATA p2 = { 2 };
	DATA p3 = { 3 };
	DATA p4 = { 4 };
	DATA p5 = { 5 };

	ND q1 = { NULL, &p1 };
	ND q2 = { NULL, &p2 };
	ND q3 = { NULL, &p3 };
	ND q4 = { NULL, &p4 };
	ND q5 = { NULL, &p5 };

	VL list = NULL;
	//��ʼ��
	INIT_list(&list);

	//����ָ��λ��
	INSE_list(list, 0, &q4);
	INSE_list(list, 0, &q5);
	INSE_list(list, 0, &q1);
	INSE_list(list, 0, &q2);
	INSE_list(list, 0, &q3);
	printf("��ʼ������\n");
	ERGO_list(list, print);

	//��������
	ORDE_list(list, compare, exchange);
	printf("\n��������\n");
	ERGO_list(list, print);

	//��������
	REVE_list(list);
	printf("\n��������\n");
	ERGO_list(list, print);

	//��ȡָ��λ�õ�ֵ
	ND * t1 = NULL;
	ND * t2 = NULL;
	ND * t3 = NULL;
	VALU_list(list, 0, &t1);
	VALU_list(list, 4, &t2);
	VALU_list(list, 5, &t3);
	printf("\nָ��λ�õ�ֵ0 4 5\n");
	print(t1);
	print(t2);
	print(t3);

	//ɾ��ָ��λ��
	DEPO_list(list, 4);
	DEPO_list(list, 0);
	printf("\nɾ��ָ��λ��4 0\n");
	ERGO_list(list, print);

	//��ȡ�����С
	int n = 0;
	SIZE_list(list, &n);
	printf("\n��ȡ�����С\n");
	printf("%d", n);

	//ɾ��ָ��ֵ
	DEVA_list(list, &q1, isequal);//������ݵ�ַɾ���ˣ�ǰ����������˵�ַ�����ݵİ󶨣�ֻ�в�������û���ң������������ݿ�ȡ�����ٲ�������
	printf("\nɾ��ָ��ֵ%d\n", q1.dat->a);
	ERGO_list(list, print);

	//����
	printf("\n����");
	DEST_list(&list);
}

//ȥ��ͷβ�Ŀո�
void popBlank(char ** str, int *len)
{
	if (NULL == str)
	{
		return;
	}
	if (NULL == *str)
	{
		return;
	}
	if (0 == *len || NULL == len)
	{
		*str = NULL;
		return;
	}
	//�����ǲ���ȫ�ǿո�
	char * p1 = *str;
	char * p2 = p1 + *len - 1;//ָ��������Ч�ַ�

	int i = 0;
	for (; i < *len; i++)
	{
		if (!(isspace(p1[i])))//���ǿո�����ѭ��
		{
			break;
		}
	}
	if (i == *len)//ȫ�ǿո�
	{
		*str = NULL;
		return;
	}

	while (p2 > p1)
	{
		if (isspace(*p2))
		{
			p2--;
		}
		else
		{
			p2++;
			*p2 = '\0';//�����ַ�����β��ʶ
			break;
		}
	}

	while (p1 > p2)
	{
		if (isspace(*p1))
		{
			p1++;
		}
		else
		{
			break;
		}
	}

	int newlen = strlen(p1);
	strncpy(*str, p1, newlen);
	(*str)[newlen] = '\0';
	*len = newlen;
}

//��ֵ�Դ�����
int keyVal(char * buf, int * age, char * name)
{
	int res = 0;
	if (NULL == buf)
	{
		res = -1;
		return res;
	}
	if (NULL == age)
	{
		res = -1;
		return res;
	}
	if (NULL == name)
	{
		res = -1;
		return res;
	}

	//�����ַ���
	char * str = buf;

	//�ж��ַ�����������
	char * ep = strchr(str, '=');
	if (NULL == ep)
	{
		res = -1;
		return res;
	}
	ep++;//ָ������Ƶ��Ⱥź���

	//�ָ��ַ���
	int length_key = ep - 1 - str;
	str[length_key] = '\0';

	//�ַ���ȥ�ո�
	popBlank(&str, &length_key);
	if (NULL == str)
	{
		res = -1;
		return res;
	}

	//��Ӹ�ֵ
	strncpy(name, str, length_key);
	name[length_key] = '\0';
	//��Ӹ�ֵ
	*age = atoi(ep);//������������ֺͿո�᷵��0

	return res;
}

void readTxt(char * fn, VL * lis)
{
	if (NULL == fn)
	{
		return;
	}
	if (NULL == lis)
	{
		return;
	}

	//��ʼ������
	VL list = NULL;
	INIT_list(&list);

	//�ļ���ȡ
	FILE * p = fopen(fn, "r");
	if (NULL == p)
	{
		return;
	}

	char buf[1024] = { 0 };

	memset(buf, 0, sizeof(buf));
	while ((fgets(buf, sizeof(buf), p)) != NULL)
	{
		char name[1024] = { 0 };
		int age = 0;
		//��ֵ�Դ�����
		int ret = keyVal(buf, &age, name);
		if (0 != ret)//��Ҫ����Ǽ�ֵ���ַ���
		{
			memset(buf, 0, sizeof(buf));
			continue;
		}

		//�������
		//�û�����
		DATA * data = (DATA *)calloc(1, sizeof(DATA));//����ʱ��Ҫfree
		if (NULL == data)
		{
			memset(buf, 0, sizeof(buf));
			continue;
		}

		data->a = age;
		strncpy(data->name, buf, 9);
		data->name[9] = '\0';
		//�û�+�ڵ�����
		ND * nd = (ND *)calloc(1, sizeof(ND));//����ʱ��Ҫfree
		if (NULL == nd)
		{
			memset(buf, 0, sizeof(buf));
			continue;
		}

		nd->nodes = NULL;
		nd->dat = data;

		//����ڣ�ͷ��
		INSE_list(list, 0, nd);

		memset(buf, 0, sizeof(buf));
	}

	//��ȡ��ɣ��������ݺ��ļ�����˳���෴������һ��
	REVE_list(list);

	//�ر��ļ�
	fclose(p);

	//����ָ���Ӹ�ֵ
	*lis = list;
}

void writeConfig(VL list, char * configname)
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == configname)
	{
		return;
	}

	VL lis = list;//����ָ��
	FILE * p = fopen(configname, "wb+");
	if (NULL == p)
	{
		return;
	}

	char buf[1024] = { 0 };

	//��ȡ�ڵ�����
	int n = 0;
	SIZE_list(list, &n);
	void * data = NULL;//��Ŷ�ȡ�����ݵ��׵�ַ
	DATA * info = (DATA *)calloc(1, sizeof(DATA));//��ʱ����û�����
	if (NULL == info)
	{
		return;
	}

	for (int i = 0; i < n; i++)
	{
		memset(info, 0, sizeof(DATA));

		//���ζ����ڵ����ݵ��ṹ��
		VALU_list(lis, i, &data);
		ND * tmp_data = (ND *)data;
		info->a = tmp_data->dat->a;
		memcpy(info->name, tmp_data->dat->name, 1024);

		//�ṹ��д���ļ�
		fwrite(info, sizeof(DATA), 1, p);
	}
	
	//����
	fclose(p);
	free(info);
}

void readConfig(char * configname)
{
	if (NULL == configname)
	{
		return;
	}

	FILE * p = fopen(configname, "rb");
	if (NULL == p)
	{
		return;
	}

	DATA * data = (DATA *)calloc(1, sizeof(DATA));
	if (NULL == data)
	{
		return;
	}

	while (fread(data, sizeof(DATA), 1, p) != 0)
	{
		printf("name = %s\n", data->name);
		printf("age = %d\n", data->a);
		memset(data, 0, sizeof(DATA));
	}
}

int main(void)
{
	//test();
	VL list = NULL;
	char * filename = "na.txt";
	
	//���ļ�������
	readTxt(filename, &list);

	//д�����ļ�
	char * configname = "na.cfg";
	writeConfig(list, configname);

	//�������ļ�
	readConfig(configname);

	//��������
	int link_size = 0;
	SIZE_list(list, &link_size);
	printf("\nlink_size = %d\n", link_size);

	void * del_data = NULL;//��ʱ�洢ɾ���ڵ���׵�ַ
	for (int i = 0; i < link_size; i++)
	{
		VALU_list(list, 0, &del_data);//��ȡ�׽ڵ��ֵ
		DEPO_list(list, 0);//ɾ�������׽ڵ�
		ND * nd = (ND *)del_data;
		if (nd->dat != NULL)//�ͷ��û�����
		{
			free(nd->dat);
			nd->dat = NULL;
		}
		if (nd != NULL)//�ͷŽڵ�+�û�����
		{
			free(nd);
			del_data = NULL;
		}
	}

	//�ͷſ�����ͷ
	DEST_list(&list);

	printf("\nCompelete\n");
	return 0;
}
