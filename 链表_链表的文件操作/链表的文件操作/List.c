#include <stdio.h>
#include <stdlib.h>

#include "List.h"

//====================API����ʵ��====================

//��ʼ��
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
	tmp->end = &(tmp->node);//β�ڵ��ʼ��ָ��ͷ�ڵ�

	*head = tmp;
}

//����
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

	NODE * tmp = ((LIST *)head)->node.next;//�׽ڵ�

	while (NULL != tmp)
	{
		pri(tmp);
		tmp = tmp->next;
	}
}

//����ָ��λ��
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

	//У�����λ�ã�λ�ò��ԣ�β������
	if (pos < 0 || pos > tmp->size - 1)
	{
		pos = tmp->size;
#if 0
		tmp->end->next = (NODE *)data;//β�ڵ���������Ľڵ�
		tmp->end = (NODE *)data;//����β�ڵ��ַ��ָ��ָ��β�ڵ�
		((NODE *)data)->next = NULL;//�ÿ��µ�β�ڵ�
#endif
	}

	//������������
	NODE * pCur = &(tmp->node);//ͷ�ڵ�
	for (int i = 0; i < pos; i++)//�˳�ѭ��ʱ��pCur���ڵ�i�Žڵ�
	{
		pCur = pCur->next;
	}

	((NODE *)data)->next = pCur->next;
	pCur->next = (NODE *)data;

	if (NULL == ((NODE *)data)->next)//β�ڵ�
	{
		tmp->end = (NODE *)data;
	}

	//��С��1
	tmp->size++;
}

//��ȡָ��λ�õ�ֵ
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
	NODE * pCur = tmp->node.next;//�׽ڵ�

	//�ж�λ�úϷ�
	if (pos < 0 || pos > tmp->size - 1)
	{
		*data = NULL;
		return;
	}

	//����
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}

	*data = pCur;
}


//ɾ��ָ��λ��
void DEPO_list(VL head, int pos)
{
	if (NULL == head)
	{
		return;
	}

	LIST * tmp = (LIST *)head;

	//�жϿ���
	if (0 == tmp->size)
	{
		return;
	}

	//�ж�λ�úϷ�
	if (pos < 0 || pos > tmp->size - 1)
	{
		return;
	}

	//����
	NODE * pPre = &(tmp->node);//ͷ�ڵ�
	NODE * pCur = pPre->next;//�׽ڵ㣬0��Ԫ�ص�λ��
	for (int i = 0; i < pos; i++)
	{
		pPre = pCur;//�˳�ʱ��i-1 ��Ԫ�ص�λ��
		pCur = pCur->next;//�˳�ʱ��i��Ԫ�ص�λ��
	}

	pPre->next = pCur->next;//ɾ���ڵ�

	if (NULL == pPre->next)//β�ڵ�
	{
		tmp->end = pPre;
	}

	//��С��һ
	tmp->size--;
}

//ɾ��ָ��ֵ
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

	//�жϿ���
	if (0 == tmp->size)
	{
		return;
	}

	//����
	NODE * pPre = &(tmp->node);//ͷ
	NODE * pCur = pPre->next;//��
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

	tmp->end = pPre;//β�ڵ�
}

//��ȡ�����С
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

//��������
void ORDE_list(VL head, COMPARE com, EXCHANGE exc)
{
	if (NULL == head)
	{
		return;
	}

	LIST * tmp = (LIST *)head;

	//���������ڵ㲻����
	if (0 == tmp->size || 1 == tmp->size)
	{
		return;
	}

	NODE * pFrom = tmp->node.next;//��
	NODE * pTo = NULL;
	NODE * ptmp = NULL;


	//ֻ����������βָ���ʶָ�򲻱�
	//ð��
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
		//pFrom = pFrom->next;��Ҫ����
	}
#endif

	//ѡ��
#if 0
	for (; pFrom != NULL; pFrom = pFrom->next)
	{
		pTo = pFrom->next;
		ptmp = pTo;
		for (; pTo != NULL; pTo = pTo->next)
		{
			if (com(ptmp, pTo))//λ�ò��ܱ�
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

	//����
#if 0
	//����������Ƚϣ���Ϊ�������±����Ԫ��
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
	//������˳��Ƚϵķ������������򣬺�һ���ڵ��Ҳ���ǰһ���ڵ㣬�ҵ�λ��ֱ�Ӳ���ڵ㲢ɾ��ԭ�ڵ�
	//pTo = pFrom;//�׽ڵ�
	//pFrom = pFrom->next;//�ڶ��ڵ�
	for (; pFrom->next != NULL;)
	{
		if (com(pFrom, pFrom->next))
		{
			ptmp = pFrom->next;
			pTo = &(tmp->node);//ͷ
			for (; pTo->next != pFrom && com(ptmp, pTo->next); pTo = pTo->next);//��ͷ�ڵ���ǰ�ң��ҵ����ϵ�λ�ò���ýڵ㣬��ɾ��ԭ�ڵ�

			pFrom->next = ptmp->next;//���ӽ���ǰԭ�ڵ��ǰ��ڵ�
			ptmp->next = pTo->next;//ԭ�ڵ�ָ�򱻲���ڵ�ĺ�һ���ڵ�
			pTo->next = ptmp;//������ڵ��ǰһ���ڵ��ָ�� ָ��ԭ�ڵ�
		}
		else//����������ʹpFrom��λ��ƫ��һ���ڵ㣬����ֻ�в�����pFrom��������
		{
			pFrom = pFrom->next;
		}
	}
#endif
}

//��������
void REVE_list(VL head)
{
	if (NULL == head)
	{
		return;
	}

	LIST * tmp = (LIST *)head;

	//�����������ڵ㲻������
	if (0 == tmp->size || 1 == tmp->size)
	{
		return;
	}

	NODE * pPre = tmp->node.next;//��
	NODE * pCur = pPre->next;//
	NODE * ptmp = NULL;

	while (NULL != pCur)
	{
		ptmp = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = ptmp;
	}

	ptmp = &(tmp->node);//ͷ
	tmp->end = ptmp->next;
	ptmp->next->next = NULL;//��ָ��
	ptmp->next = pPre;//����
}

//����
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
	printf("\n�������ٳɹ�\n");
}