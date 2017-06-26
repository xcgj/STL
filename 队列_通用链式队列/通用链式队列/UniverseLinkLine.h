#pragma once
//通用链式队列
//首节点位置出队，尾节点入队
//表头属性不仅需要头节点指针和大小，还要有指向尾节点的标识指针变量
//队列链表形式：
//				  尾节点标识指针
//					   |
//头节点->首节点->……->尾节点->NULL
//		  出队        入队


//定义节点数据类型
typedef struct NODE
{
	struct NODE *next;
}NODE;

//定义表头数据类型
typedef struct LINE
{
	NODE head;
	NODE * tail;
	int size;
}LINE;

typedef void * VULL;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	//初始化
	void INIT_line(VULL * lin);

	//入队
	void PUSH_line(VULL lin, void *data);

	//出队
	void POP_line(VULL lin);
	//查询
	void * HEAD_line(VULL lin);

	void * END_line(VULL lin);

	//销毁
	void DESTR_line(VULL * lin);

#ifdef __cplusplus
}
#endif // __cplusplus
