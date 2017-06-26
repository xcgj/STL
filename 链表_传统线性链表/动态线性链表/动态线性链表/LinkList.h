#pragma once

//先定义链表节点数据类型，不然头节点的数据类型无法定义
typedef struct LinkNode
{
	struct LinkNode * next;
	void * data;
}LinkNode;

//再定义表头结构体数据类型保存链表数据
typedef struct LinkInfo
{
	struct LinkNode head;//直接申请了节点的空间大小。如果定义指针需要额外申请空间
	int size;
}LinkInfo;

//定义打印函数
typedef void(*PRINT)(void * data);

//定义比较函数
typedef int(*COMPARE)(void * data1, void * data2);

//初始化
LinkInfo * INIT_link();

//插入
int INSERT_link(void * head, int pos, void * data);

//按位置删除
int DELPOS_link(void * head, int pos);

//遍历
//int ERGODIC_link(void * head, void(*PRINT)(void * data));
int ERGODIC_link(void * head, PRINT pri);

//按值删除
//int DELVAL_link(void * head, void * data, void(*COMPARE)(void * data1, void * data2));
int DELVAL_link(void * head, void * data, COMPARE com);

//释放
int FREE_link(void ** head);