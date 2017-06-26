#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UniversalLink.h"

void print(void * data)
{
	if (NULL == data)
	{
		return;
	}

	Person * tmp = (Person *)data;
	printf("name = %s, age = %d\n", tmp->dat->name, tmp->dat->age);
}

int compare(void * data1, void * data2)
{
	if (NULL == data1)
	{
		return -1;
	}

	if (NULL == data2)
	{
		return -1;
	}

	Person * tmp1 = (Person *)data1;
	Person * tmp2 = (Person *)data2;
	return tmp1->dat->age == tmp2->dat->age && (!(strcmp(tmp1->dat->name, tmp2->dat->name)));
}

int selectCompare(void * data1, void * data2)
{
	//数据合法
	if (NULL == data1)
	{
		return 0;
	}

	if (NULL == data2)
	{
		return 0;
	}

	int age1 = ((Person *)data1)->dat->age;
	int age2 = ((Person *)data2)->dat->age;

	return age1 > age2 ? 1 : 0;//升序
}

//定义数据结构体，包含节点类型
int main(void)
{
	//初始化函数指针
	COMPARE func[] = { compare, selectCompare };

	DATA d1 = { "aaa", 10 };
	DATA d2 = { "bbb", 20 };
	DATA d3 = { "ccc", 30 };
	DATA d4 = { "ddd", 40 };
	DATA d5 = { "eee", 50 };
	DATA d6 = { "fff", 60 };

	Person p1 = { NULL, &d1 };
	Person p2 = { NULL, &d2 };
	Person p3 = { NULL, &d3 };
	Person p4 = { NULL, &d4 };
	Person p5 = { NULL, &d5 };
	Person p6 = { NULL, &d6 };

	LinkList * head = INIT_list();	//定义表头结构体

	//指定位置插入
	printf("插入\n");
	INSERT_list(head, 0, &p1);
	INSERT_list(head, 0, &p2);
	INSERT_list(head, 666, &p3);
	INSERT_list(head, -110, &p4);
	INSERT_list(head, 2, &p5);
	INSERT_list(head, 2, &p6);
	ERGODIC_list(head, print);//216534

							  //选择排序
	SELECT_list(head, func[1]);
	printf("选择排序\n");
	REPRIN_list(head, print);

	//指定位置删除
	printf("删除\n");
	DELPOS_list(head, 0);
	DELPOS_list(head, 3);
	ERGODIC_list(head, print);//1654

	//指定值删除
	printf("删除\n");
	DELVAL_list(head, &p6, func[0]);
	ERGODIC_list(head, print);//154

	//逆序打印链表，(注意:不反转链表)
	printf("逆序打印\n");
	REPRIN_list(head, print);



	//逆置
	printf("逆置\n");
	REVERSE_list(head);
	ERGODIC_list(head, print);//451

	//释放
	printf("释放\n");
	FREE_list(&head);

	printf("Compelete\n");
	return 0;
}
