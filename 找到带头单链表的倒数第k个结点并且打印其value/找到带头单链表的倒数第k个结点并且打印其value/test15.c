#include <stdio.h>

typedef struct _tag_listnode
{
	int data;
	struct _tag_listnode *next;
}ListNode;

//函数原型: int findLastKNode(ListNode *head);
//实现代码 找到带头单链表的 倒数第k个结点 并且打印其value 。

int findLastKNode(ListNode *head, int k);

int findLastKNode(ListNode *head, int k)
{
	//判断数据
	if (NULL == head)
	{
		return -1;
	}

	//遍历一遍，计算总共几个节点
	ListNode * tmp = head;//头节点
	int count = 0;//有效节点个数
	tmp = tmp->next;//首节点

	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}

	if (0 == count)//空链
	{
		return -2;
	}

	//找到节点
	int n = count - k;//从0开始数，节点所在的位置
	if (n < 0)//位置非法
	{
		return -3;
	}

	tmp = head->next;//复位首节点

	for (int i = 0; i < n; i++)
	{
		tmp = tmp->next;
	}
	
	return tmp->data;
}
