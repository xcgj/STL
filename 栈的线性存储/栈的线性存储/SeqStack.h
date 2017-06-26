#pragma once

#define MAX 1024

//定义结构体，保存顺序栈链的信息。指向栈的地址和栈链的大小
typedef struct SeqStack
{
	void * stak[MAX];	//指针数组，每个元素都指向用户数据的首地址
	int size;
}SeqStack;

typedef void * VStack;

//初始化
VStack INIT_stack();

//压栈
void PUSH_stack(VStack sk, void * data);

//出栈
void POP_stack(VStack sk);

//查询栈顶数据
void * SEAR_stack(VStack sk);

//销毁栈
void DESTR_stack(VStack * sk);