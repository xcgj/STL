#pragma once

typedef void XCGJ;

void SListDestroy(XCGJ * pH);		//释放所有节点

//删除值为x的所有结点
int SListNodeDelPro(XCGJ *pH, int x);

//链表节点排序，交换的是数据域
int SListNodeSort(XCGJ * pH);

//假如原来链表是升序的,升序插入新节点
//不能插入节点后再排序，是升序插入新节点x
int SListNodeInsertPro(XCGJ * pH, int x, int y);//	y是id的值

int SListNodeReverse(XCGJ * pH);//头节点不逆置

int SListPrint(XCGJ * pH);//遍历所有节点

void * SListCreat();//创建节点