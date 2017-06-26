#pragma once
//ʹ������ջ������˳��ṹ��ϰ
//�ȶ���ջ���������ͣ�����Ҫ�ڵ���������
#define MAX 1024

typedef struct LINESTACK
{
	void * stk[MAX];//ָ������
	int size;//��ЧԪ�ش�С
}LINESTACK;

typedef void * VMTPS;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	//��ʼ��
	void INIT_stack(VMTPS * head);

	//��ջ
	void PUSH_stack(VMTPS head, void * data);

	//��ջ
	void POP_stack(VMTPS head);

	//��ȡջ��Ԫ��
	void * TOPREAD_stack(VMTPS head);

	//��ȡջ��С
	int SIZE_stack(VMTPS head);

	//����ջ
	void DESTR_stack(VMTPS * head);

#ifdef __cplusplus
}
#endif // __cplusplus

