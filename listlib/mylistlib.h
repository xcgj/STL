#pragma once

typedef void XCGJ;

void SListDestroy(XCGJ * pH);		//�ͷ����нڵ�

//ɾ��ֵΪx�����н��
int SListNodeDelPro(XCGJ *pH, int x);

//����ڵ����򣬽�������������
int SListNodeSort(XCGJ * pH);

//����ԭ�������������,��������½ڵ�
//���ܲ���ڵ������������������½ڵ�x
int SListNodeInsertPro(XCGJ * pH, int x, int y);//	y��id��ֵ

int SListNodeReverse(XCGJ * pH);//ͷ�ڵ㲻����

int SListPrint(XCGJ * pH);//�������нڵ�

void * SListCreat();//�����ڵ�