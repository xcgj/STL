#pragma once
//ͨ����ʽ����
//�׽ڵ�λ�ó��ӣ�β�ڵ����
//��ͷ���Բ�����Ҫͷ�ڵ�ָ��ʹ�С����Ҫ��ָ��β�ڵ�ı�ʶָ�����
//����������ʽ��
//				  β�ڵ��ʶָ��
//					   |
//ͷ�ڵ�->�׽ڵ�->����->β�ڵ�->NULL
//		  ����        ���


//����ڵ���������
typedef struct NODE
{
	struct NODE *next;
}NODE;

//�����ͷ��������
typedef struct LINE
{
	NODE head;
	NODE * tail;
	int size;
}LINE;

typedef void * VULL;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	//��ʼ��
	void INIT_line(VULL * lin);

	//���
	void PUSH_line(VULL lin, void *data);

	//����
	void POP_line(VULL lin);
	//��ѯ
	void * HEAD_line(VULL lin);

	void * END_line(VULL lin);

	//����
	void DESTR_line(VULL * lin);

#ifdef __cplusplus
}
#endif // __cplusplus
