#pragma once
//头插法，通用链表
//先定义节点
typedef struct LISTNODE	
{
	struct LISTNODE * next;
}LISTNODE;//四个字节大小的数据类型

//再定义栈线性链表属性的结构体，包含指向栈链表首节点的头节点 和 栈链表的大小
typedef struct UNISTACK
{
	struct LISTNODE header;
	int size;
}UNISTACK;

typedef void * VUSL;//void university stack list

//表头初始化
VUSL INIT_USL();

//入栈
void PUSH_ustack(VUSL head, void * data);

//出栈
void POP_ustack(VUSL head);

//查询栈顶元素
void * SEAR_ustack(VUSL head);

//查询链表大小
int SIZE_ustack(VUSL head);

//销毁
void DESTR_ustack(VUSL * head);
