#pragma once
//ͷ�巨��ͨ������
//�ȶ���ڵ�
typedef struct LISTNODE	
{
	struct LISTNODE * next;
}LISTNODE;//�ĸ��ֽڴ�С����������

//�ٶ���ջ�����������ԵĽṹ�壬����ָ��ջ�����׽ڵ��ͷ�ڵ� �� ջ����Ĵ�С
typedef struct UNISTACK
{
	struct LISTNODE header;
	int size;
}UNISTACK;

typedef void * VUSL;//void university stack list

//��ͷ��ʼ��
VUSL INIT_USL();

//��ջ
void PUSH_ustack(VUSL head, void * data);

//��ջ
void POP_ustack(VUSL head);

//��ѯջ��Ԫ��
void * SEAR_ustack(VUSL head);

//��ѯ�����С
int SIZE_ustack(VUSL head);

//����
void DESTR_ustack(VUSL * head);
