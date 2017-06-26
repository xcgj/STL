#pragma once
//====================程序所需数据类型====================
//节点
typedef struct NODE
{
	struct NODE *next;
}NODE;

//表类型
typedef struct LIST
{
	NODE node;//头节点
	NODE * end;//保存结尾指针的地址
	int size;
}LIST;

typedef void * VL;

typedef int(*COMPARE)(void *, void *);

typedef void(*PRINT)(void *);

typedef void(*EXCHANGE)(void *, void *);//交换数据域


//====================用户自定义数据类型====================
//定义数据体结构体
typedef struct DATA
{
	char name[1024];
	int a;
}DATA;

//定义节点+数据 结构体
typedef struct ND
{
	NODE * nodes;
	DATA * dat;
}ND;

//====================API函数定义====================
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	//初始化
	void INIT_list(VL * head);

	//遍历
	void ERGO_list(VL head, PRINT pri);

	//插入指定位置
	void INSE_list(VL head, int pos, void * data);

	//获取指定位置的值
	void VALU_list(VL head, int pos, void ** data);

	//删除指定位置
	void DEPO_list(VL head, int pos);

	//删除指定值
	void DEVA_list(VL head, void * data, COMPARE com);

	//获取链表大小
	void SIZE_list(VL head, int * size);

	//链表排序
	void ORDE_list(VL head, COMPARE com, EXCHANGE exc);

	//链表逆置
	void REVE_list(VL head);

	//销毁
	void DEST_list(VL * head);

#ifdef __cplusplus
}
#endif // __cplusplus
