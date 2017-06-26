#pragma once
//使用利用栈的线性顺序结构练习
//先定义栈的数据类型，不需要节点数据类型
#define MAX 1024

typedef struct LINESTACK
{
	void * stk[MAX];//指针数组
	int size;//有效元素大小
}LINESTACK;

typedef void * VMTPS;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	//初始化
	void INIT_stack(VMTPS * head);

	//入栈
	void PUSH_stack(VMTPS head, void * data);

	//出栈
	void POP_stack(VMTPS head);

	//获取栈顶元素
	void * TOPREAD_stack(VMTPS head);

	//获取栈大小
	int SIZE_stack(VMTPS head);

	//销毁栈
	void DESTR_stack(VMTPS * head);

#ifdef __cplusplus
}
#endif // __cplusplus

