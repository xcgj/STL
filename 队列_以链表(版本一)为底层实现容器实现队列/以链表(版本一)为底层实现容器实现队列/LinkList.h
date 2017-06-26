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

//初始化
LinkInfo * INIT_link();

//插入
int INSERT_link(void * head, int pos, void * data);

//按位置删除
int DELPOS_link(void * head, int pos);

//释放
int FREE_link(void ** head);