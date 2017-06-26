#pragma once

//定义节点
typedef struct LinkNode
{
	struct LinkNode * next;
}LinkNode;

//定义表头
typedef struct LinkList
{
	struct LinkNode header;
	int size;
}LinkList;

typedef struct DATA
{
	char name[10];
	int age;
}DATA;

typedef struct Person
{
	LinkNode * next;
	DATA *dat;
}Person;

//隐藏数据类型
typedef void * VList;

//打印
typedef void PRINT(void * data);

//比较，如果使用(*COMPARE[])，形参和实参的值如何传递
typedef int (*COMPARE)(void * data1, void * data2);

//初始化表头
LinkList * INIT_list();

//指定位置插入
void INSERT_list(VList head, int pos, void * data);

//指定位置删除
void DELPOS_list(VList head, int pos);

//遍历
void ERGODIC_list(VList head, PRINT pri);

//按值删除
void DELVAL_list(VList head, void * data, COMPARE com);

//逆序打印链表，(注意:不反转链表)
void REPRIN_list(VList head, PRINT pri);

//链表选择排序
void SELECT_list(VList head, COMPARE com);

//链表逆置
void REVERSE_list(VList head);

//释放
void FREE_list(VList * head);