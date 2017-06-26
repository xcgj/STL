#include <stdio.h>
#include <stdlib.h>

#include "List.h"

//====================API函数实现====================

//初始化
void INIT_list(VL * head)
{
	if (NULL == head)
	{
		return;
	}
	
	LIST * tmp = (LIST *)malloc(sizeof(LIST));
	if (NULL == tmp)
	{
		return;
	}

	tmp->size = 0;
	tmp->node.next = NULL;
	tmp->end = &(tmp->node);//尾节点初始化指向头节点

	*head = tmp;
}

//遍历
void ERGO_list(VL head, PRINT pri)
{
	if (NULL == head)
	{
		return;
	}
	if (NULL == pri)
	{
		return;
	}

	NODE * tmp = ((LIST *)head)->node.next;//首节点

	while (NULL != tmp)
	{
		pri(tmp);
		tmp = tmp->next;
	}
}

//插入指定位置
void INSE_list(VL head, int pos, void * data)
{
	if (NULL == head)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}

	LIST * tmp = (LIST *)head;

	//校验插入位置，位置不对，尾部插入
	if (pos < 0 || pos > tmp->size - 1)
	{
		pos = tmp->size;
#if 0
		tmp->end->next = (NODE *)data;//尾节点接上新增的节点
		tmp->end = (NODE *)data;//保存尾节点地址的指针指向尾节点
		((NODE *)data)->next = NULL;//置空新的尾节点
#endif
	}

	//正常遍历插入
	NODE * pCur = &(tmp->node);//头节点
	for (int i = 0; i < pos; i++)//退出循环时，pCur处在第i号节点
	{
		pCur = pCur->next;
	}

	((NODE *)data)->next = pCur->next;
	pCur->next = (NODE *)data;

	if (NULL == ((NODE *)data)->next)//尾节点
	{
		tmp->end = (NODE *)data;
	}

	//大小加1
	tmp->size++;
}

//获取指定位置的值
void VALU_list(VL head, int pos, void ** data)
{
	if (NULL == data)
	{
		return;
	}

	if (NULL == head)
	{
		*data = NULL;
		return;
	}
	
	LIST * tmp = (LIST *)head;
	NODE * pCur = tmp->node.next;//首节点

	//判断位置合法
	if (pos < 0 || pos > tmp->size - 1)
	{
		*data = NULL;
		return;
	}

	//遍历
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}

	*data = pCur;
}


//删除指定位置
void DEPO_list(VL head, int pos)
{
	if (NULL == head)
	{
		return;
	}

	LIST * tmp = (LIST *)head;

	//判断空链
	if (0 == tmp->size)
	{
		return;
	}

	//判断位置合法
	if (pos < 0 || pos > tmp->size - 1)
	{
		return;
	}

	//遍历
	NODE * pPre = &(tmp->node);//头节点
	NODE * pCur = pPre->next;//首节点，0号元素的位置
	for (int i = 0; i < pos; i++)
	{
		pPre = pCur;//退出时，i-1 号元素的位置
		pCur = pCur->next;//退出时，i号元素的位置
	}

	pPre->next = pCur->next;//删除节点

	if (NULL == pPre->next)//尾节点
	{
		tmp->end = pPre;
	}

	//大小减一
	tmp->size--;
}

//删除指定值
void DEVA_list(VL head, void * data, COMPARE com)
{
	if (NULL == head)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}

	LIST * tmp = (LIST *)head;

	//判断空链
	if (0 == tmp->size)
	{
		return;
	}

	//遍历
	NODE * pPre = &(tmp->node);//头
	NODE * pCur = pPre->next;//首
	while (NULL != pCur)
	{
		if (com(data, pCur))
		{
			pCur = pCur->next;
			pPre->next = pCur;
			tmp->size--;
			continue;
		}

		pPre = pCur;
		pCur = pCur->next;
	}

	tmp->end = pPre;//尾节点
}

//获取链表大小
void SIZE_list(VL head, int * size)
{
	if (NULL == head)
	{
		return;
	}
	if (NULL == size)
	{
		return;
	}

	LIST * tmp = (LIST *)head;
	*size = tmp->size;
}

//链表排序
void ORDE_list(VL head, COMPARE com, EXCHANGE exc)
{
	if (NULL == head)
	{
		return;
	}

	LIST * tmp = (LIST *)head;

	//空链、单节点不排序
	if (0 == tmp->size || 1 == tmp->size)
	{
		return;
	}

	NODE * pFrom = tmp->node.next;//首
	NODE * pTo = NULL;
	NODE * ptmp = NULL;


	//只交换数据域，尾指针标识指向不变
	//冒泡
#if 0
	for (; pFrom != NULL; pFrom = pFrom->next)
	{
		for (pTo = tmp->node.next; pTo != NULL; pTo = pTo->next)
		{
			ptmp = pTo->next;
			if (NULL == ptmp)
			{
				break;
			}

			if (com(pTo, ptmp))
			{
				exc(pTo, ptmp);
			}
		}
	}
#endif
#if 0
	for (int i = 0; i < tmp->size; i++)
	{
		pTo = pFrom;
		for (int j = 0; j < tmp->size - i - 1; j++)
		{
			ptmp = pTo;
			pTo = pTo->next;
			if (com(ptmp, pTo))
			{
				exc(ptmp, pTo);
			}
		}
		//pFrom = pFrom->next;不要下移
	}
#endif

	//选择
#if 0
	for (; pFrom != NULL; pFrom = pFrom->next)
	{
		pTo = pFrom->next;
		ptmp = pTo;
		for (; pTo != NULL; pTo = pTo->next)
		{
			if (com(ptmp, pTo))//位置不能变
			{
				ptmp = pTo;
			}
		}

		if (ptmp != pFrom)
		{
			exc(ptmp, pFrom);
		}
	}
#endif

	//插入
#if 0
	//数组是逆序比较，因为可以用下标访问元素
	for (int i = 1; i < tmp->size; i++)
	{
		if (a[i] < a[i - 1])
		{
			tmp = a[i];

			int j = i - 1;
			for (; j >= 0 && tmp < a[j]; --j)
			{
				a[j + 1] = a[j];
			}
			a[j + 1] = tmp;
		}
	}
#endif
#if 1
	//链表用顺序比较的方法，不能逆序，后一个节点找不到前一个节点，找到位置直接插入节点并删除原节点
	//pTo = pFrom;//首节点
	//pFrom = pFrom->next;//第二节点
	for (; pFrom->next != NULL;)
	{
		if (com(pFrom, pFrom->next))
		{
			ptmp = pFrom->next;
			pTo = &(tmp->node);//头
			for (; pTo->next != pFrom && com(ptmp, pTo->next); pTo = pTo->next);//从头节点往前找，找到符合的位置插入该节点，并删除原节点

			pFrom->next = ptmp->next;//连接交换前原节点的前后节点
			ptmp->next = pTo->next;//原节点指向被插入节点的后一个节点
			pTo->next = ptmp;//将插入节点的前一个节点的指向 指向原节点
		}
		else//上述交换会使pFrom的位置偏移一个节点，所有只有不交还pFrom才往下移
		{
			pFrom = pFrom->next;
		}
	}
#endif
}

//链表逆置
void REVE_list(VL head)
{
	if (NULL == head)
	{
		return;
	}

	LIST * tmp = (LIST *)head;

	//空链、单个节点不用逆置
	if (0 == tmp->size || 1 == tmp->size)
	{
		return;
	}

	NODE * pPre = tmp->node.next;//首
	NODE * pCur = pPre->next;//
	NODE * ptmp = NULL;

	while (NULL != pCur)
	{
		ptmp = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = ptmp;
	}

	ptmp = &(tmp->node);//头
	tmp->end = ptmp->next;
	ptmp->next->next = NULL;//首指空
	ptmp->next = pPre;//改首
}

//销毁
void DEST_list(VL * head)
{
	if (NULL == head)
	{
		return;
	}
	if (NULL == *head)
	{
		return;
	}

	free(*head);
	*head = NULL;
	printf("\n链表销毁成功\n");
}