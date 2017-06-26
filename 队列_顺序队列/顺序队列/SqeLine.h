#pragma once

#define MAX 1024
//线性队列：
//不需要定义节点类型
//申请一段连续内存空间，每个元素是泛型指针变量，存储数据的地址
//指定队头为（出栈）a[0]
//指定队尾为（入栈）a[size]

//定义队列的数据类型
typedef struct LINE
{
	void ** Line;//队列的首地址，指针数组，MAX是容量，传参 void ** p
	int size;//队列的大小
}LINE;

typedef void * VAL;

typedef void(*PRINT)(void *);

//初始化
//VAL * INIT_line();//返回的是地址，
void INIT_line(VAL * lin);

//入队
void PUSH_line(VAL lin, void * data);

//出队
void POP_line(VAL lin);

//查询队头
void * START_line(VAL lin);

//查询队底
void END_line(VAL lin, PRINT pri);

//查询大小
int SIZE_line(VAL lin);

//销毁队列
void DESTR_line(VAL * lin);