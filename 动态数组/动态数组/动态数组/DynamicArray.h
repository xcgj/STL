#pragma once

//表头
typedef struct DArray	//动态数组结构体
{
	void ** array;//在这里面动态分配数组空间，存储数据，不需要next指针，因为空间连续，用下标即可访问
	//void**指向的空间数据类型是void*, void*指向的空间数据类型是void，void*可转化为任意类型
	int capacity;//容量
	int size;//大小，统计《有效》节点的个数
}DArray;

typedef int(*PRINT)(void * data);

typedef int(*COMPARE)(void * data1, void * data2);

//打印数据
int print(void * data);

//比较数据
int compare(void * data1, void * data2);

//初始化数组
void* INIT_array();

//数组中在指定位置插入元素
int INSERT_array(void * hand, int pos, void * data);

//数组中删除指定位置的元素
int DELPOS_array(void * hand, int pos);

//按数据的值删除元素
int DELVAL_array(void * hand, void * data, COMPARE com);

//遍历这个数组
int ERGODIC_array(void * hand, PRINT pri);

//释放数组
int FREE_array(void ** hand);


