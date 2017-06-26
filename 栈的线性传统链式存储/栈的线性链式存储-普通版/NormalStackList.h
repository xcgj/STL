#pragma once
//头插法，传统链表		//程序
//先定义节点数据类型
typedef struct NODE
{
	struct NODE *next;
	void * data;
}NODE;

//再定义表头数据类型
typedef struct Head
{
	NODE header;//指向一个内存空间，直接定义变量，不要定义指针，方便申请释放空间
	int size;
}Head;

typedef void* VTSL;// void traditional stack list

//初始化
VTSL INIT_tstack();

//插入
void PUSH_tstack(VTSL head, void *data);

//删除
void POP_tstack(VTSL head);

//查询数据
void * SEAR_tstack(VTSL head);

//查询大小
int SIZE_tstack(VTSL head);

//销毁
void DESTR_tstack(VTSL * head);
