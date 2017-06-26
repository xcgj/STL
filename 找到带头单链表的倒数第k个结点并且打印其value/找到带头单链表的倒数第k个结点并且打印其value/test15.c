#include <stdio.h>

typedef struct _tag_listnode
{
	int data;
	struct _tag_listnode *next;
}ListNode;

//����ԭ��: int findLastKNode(ListNode *head);
//ʵ�ִ��� �ҵ���ͷ������� ������k����� ���Ҵ�ӡ��value ��

int findLastKNode(ListNode *head, int k);

int findLastKNode(ListNode *head, int k)
{
	//�ж�����
	if (NULL == head)
	{
		return -1;
	}

	//����һ�飬�����ܹ������ڵ�
	ListNode * tmp = head;//ͷ�ڵ�
	int count = 0;//��Ч�ڵ����
	tmp = tmp->next;//�׽ڵ�

	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}

	if (0 == count)//����
	{
		return -2;
	}

	//�ҵ��ڵ�
	int n = count - k;//��0��ʼ�����ڵ����ڵ�λ��
	if (n < 0)//λ�÷Ƿ�
	{
		return -3;
	}

	tmp = head->next;//��λ�׽ڵ�

	for (int i = 0; i < n; i++)
	{
		tmp = tmp->next;
	}
	
	return tmp->data;
}
