#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "mylistlib.h"

int main()
{
	void *pHead = NULL;

	pHead = SListCreat(); //����ͷ���
	printf("\n����ͷ����\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeDelPro(pHead, 4);//ɾ������ֵΪ4�Ľ��
	printf("\nɾ������ֵΪ4�Ľ��\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeSort(pHead);//����ڵ�����
	printf("\n����ڵ�����\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeInsertPro(pHead, 5, 10);//�������5
	printf("\n�������5��\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeReverse(pHead); //��ת����Ľڵ㣨����ͷ�ڵ㣩
	printf("\n��ת����Ľڵ�\n");
	SListPrint(pHead); //�������нڵ�

	SListDestroy(pHead);//�ͷ����нڵ�
	pHead = NULL;

	return 0;
}