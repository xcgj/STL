#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "List.h"
#include "RecallFunction.h"

void test(void)//测试代码
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
	//初始化
	INIT_list(&list);

	//插入指定位置
	INSE_list(list, 0, &q4);
	INSE_list(list, 0, &q5);
	INSE_list(list, 0, &q1);
	INSE_list(list, 0, &q2);
	INSE_list(list, 0, &q3);
	printf("初始化遍历\n");
	ERGO_list(list, print);

	//链表排序
	ORDE_list(list, compare, exchange);
	printf("\n链表排序\n");
	ERGO_list(list, print);

	//链表逆置
	REVE_list(list);
	printf("\n链表逆置\n");
	ERGO_list(list, print);

	//获取指定位置的值
	ND * t1 = NULL;
	ND * t2 = NULL;
	ND * t3 = NULL;
	VALU_list(list, 0, &t1);
	VALU_list(list, 4, &t2);
	VALU_list(list, 5, &t3);
	printf("\n指定位置的值0 4 5\n");
	print(t1);
	print(t2);
	print(t3);

	//删除指定位置
	DEPO_list(list, 4);
	DEPO_list(list, 0);
	printf("\n删除指定位置4 0\n");
	ERGO_list(list, print);

	//获取链表大小
	int n = 0;
	SIZE_list(list, &n);
	printf("\n获取链表大小\n");
	printf("%d", n);

	//删除指定值
	DEVA_list(list, &q1, isequal);//这里根据地址删除了，前面排序打乱了地址和数据的绑定，只有插入排序没打乱，它是整个数据块取出来再插入链表
	printf("\n删除指定值%d\n", q1.dat->a);
	ERGO_list(list, print);

	//销毁
	printf("\n销毁");
	DEST_list(&list);
}

//去掉头尾的空格
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
	//遍历是不是全是空格
	char * p1 = *str;
	char * p2 = p1 + *len - 1;//指向最后的有效字符

	int i = 0;
	for (; i < *len; i++)
	{
		if (!(isspace(p1[i])))//不是空格，跳出循环
		{
			break;
		}
	}
	if (i == *len)//全是空格
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
			*p2 = '\0';//接上字符串结尾标识
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

//键值对处理函数
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

	//拷贝字符串
	char * str = buf;

	//判断字符串符合条件
	char * ep = strchr(str, '=');
	if (NULL == ep)
	{
		res = -1;
		return res;
	}
	ep++;//指针向后移到等号后面

	//分割字符串
	int length_key = ep - 1 - str;
	str[length_key] = '\0';

	//字符串去空格
	popBlank(&str, &length_key);
	if (NULL == str)
	{
		res = -1;
		return res;
	}

	//间接赋值
	strncpy(name, str, length_key);
	name[length_key] = '\0';
	//间接赋值
	*age = atoi(ep);//如果不包含数字和空格会返回0

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

	//初始化链表
	VL list = NULL;
	INIT_list(&list);

	//文件读取
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
		//键值对处理函数
		int ret = keyVal(buf, &age, name);
		if (0 != ret)//主要处理非键值对字符串
		{
			memset(buf, 0, sizeof(buf));
			continue;
		}

		//打包数据
		//用户数据
		DATA * data = (DATA *)calloc(1, sizeof(DATA));//销毁时需要free
		if (NULL == data)
		{
			memset(buf, 0, sizeof(buf));
			continue;
		}

		data->a = age;
		strncpy(data->name, buf, 9);
		data->name[9] = '\0';
		//用户+节点数据
		ND * nd = (ND *)calloc(1, sizeof(ND));//销毁时需要free
		if (NULL == nd)
		{
			memset(buf, 0, sizeof(buf));
			continue;
		}

		nd->nodes = NULL;
		nd->dat = data;

		//插入节，头插
		INSE_list(list, 0, nd);

		memset(buf, 0, sizeof(buf));
	}

	//读取完成，链表数据和文件数据顺序相反，逆置一下
	REVE_list(list);

	//关闭文件
	fclose(p);

	//二级指针间接赋值
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

	VL lis = list;//辅助指针
	FILE * p = fopen(configname, "wb+");
	if (NULL == p)
	{
		return;
	}

	char buf[1024] = { 0 };

	//获取节点数量
	int n = 0;
	SIZE_list(list, &n);
	void * data = NULL;//存放读取的数据的首地址
	DATA * info = (DATA *)calloc(1, sizeof(DATA));//临时存放用户数据
	if (NULL == info)
	{
		return;
	}

	for (int i = 0; i < n; i++)
	{
		memset(info, 0, sizeof(DATA));

		//依次读出节点数据到结构体
		VALU_list(lis, i, &data);
		ND * tmp_data = (ND *)data;
		info->a = tmp_data->dat->a;
		memcpy(info->name, tmp_data->dat->name, 1024);

		//结构体写入文件
		fwrite(info, sizeof(DATA), 1, p);
	}
	
	//清理
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
	
	//读文件到链表
	readTxt(filename, &list);

	//写配置文件
	char * configname = "na.cfg";
	writeConfig(list, configname);

	//读配置文件
	readConfig(configname);

	//销毁链表
	int link_size = 0;
	SIZE_list(list, &link_size);
	printf("\nlink_size = %d\n", link_size);

	void * del_data = NULL;//临时存储删除节点的首地址
	for (int i = 0; i < link_size; i++)
	{
		VALU_list(list, 0, &del_data);//获取首节点的值
		DEPO_list(list, 0);//删除链表首节点
		ND * nd = (ND *)del_data;
		if (nd->dat != NULL)//释放用户数据
		{
			free(nd->dat);
			nd->dat = NULL;
		}
		if (nd != NULL)//释放节点+用户数据
		{
			free(nd);
			del_data = NULL;
		}
	}

	//释放空链表头
	DEST_list(&list);

	printf("\nCompelete\n");
	return 0;
}
