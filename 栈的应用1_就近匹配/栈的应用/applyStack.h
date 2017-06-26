#pragma once

//定义节点数据类型
typedef struct SNODE
{
	struct SNODE * next;
}SNODE;

//定义链栈的属性结构体类型
typedef struct LISTSTACK
{
	SNODE node;
	int size;
}LISTSTACK;

typedef void * VLS;

//初始化
void INIT_stack(VLS * head);

VLS INIT_stack2();

//压栈
void PUSH_stack(VLS head, void * data);

//出栈
void POP_stack(VLS head);

//查询栈顶元素
void * SEAR_stack(VLS head);

//查询栈大小
int SIZE_stack(VLS head);

//销毁栈
void DESTR_stack(VLS * head);
