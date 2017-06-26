#pragma once
//��ͳ��ʽ����
//ָ�����׽ڵ�λ�ó��ӣ�β�ڵ����
//��ͷ���Բ�����Ҫͷ�ڵ�ָ��ʹ�С����Ҫ��ָ��β�ڵ�ı�ʶָ�����
//����������ʽ��
//				  β�ڵ��ʶָ��
//					   |
//ͷ�ڵ�->�׽ڵ�->����->β�ڵ�->NULL
//		  ����        ���

//�ڵ���������
typedef struct NODE
{
	struct NODE *next;
	void * data;
}NODE;

//��ͷ��������
typedef struct LINE
{
	NODE head;	//ֱ�Ӷ���ṹ��������ڲ����ڴ棬�����ͷʱ�������ڵ�ռ�Ҳ����
	NODE * tail;//ָ��β�ڵ��ָ�������β�ڵ������������ NODE
	int size;
}LINE;

typedef void * VTLL;

#ifdef __cplusplus
extern "C" {
#endif

	//��ʼ��
	void INIT_line(VTLL * line);//����ָ���Ӹ�ֵ

	//β�ڵ����
	void PUSH_line(VTLL line, void * data);

	//�׽ڵ���ӣ�ע���СΪ1ʱͷ�ڵ�ָ��
	void POP_line(VTLL line);

	//��ѯ��ͷ�Ͷ�β������
	void READ_line(VTLL line, void ** data1, void ** data2);//����ָ���Ӹ�ֵ

	//���ٶ���
	void DESTR_line(VTLL * line);

#ifdef __cplusplus
}
#endif // __cplusplus
