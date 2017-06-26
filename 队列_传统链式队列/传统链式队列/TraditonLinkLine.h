#pragma once
//传统链式队列
//指定在首节点位置出队，尾节点入队
//表头属性不仅需要头节点指针和大小，还要有指向尾节点的标识指针变量
//队列链表形式：
//				  尾节点标识指针
//					   |
//头节点->首节点->……->尾节点->NULL
//		  出队        入队

//节点数据类型
typedef struct NODE
{
	struct NODE *next;
	void * data;
}NODE;

//表头数据类型
typedef struct LINE
{
	NODE head;	//直接定义结构体变量便于操作内存，定义表头时，两个节点空间也有了
	NODE * tail;//指向尾节点的指针变量，尾节点的数据类型是 NODE
	int size;
}LINE;

typedef void * VTLL;

#ifdef __cplusplus
extern "C" {
#endif

	//初始化
	void INIT_line(VTLL * line);//二级指针间接赋值

	//尾节点入队
	void PUSH_line(VTLL line, void * data);

	//首节点出队，注意大小为1时头节点指向
	void POP_line(VTLL line);

	//查询队头和队尾的数据
	void READ_line(VTLL line, void ** data1, void ** data2);//二级指针间接赋值

	//销毁队列
	void DESTR_line(VTLL * line);

#ifdef __cplusplus
}
#endif // __cplusplus
