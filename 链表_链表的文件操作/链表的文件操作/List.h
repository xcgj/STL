#pragma once
//====================����������������====================
//�ڵ�
typedef struct NODE
{
	struct NODE *next;
}NODE;

//������
typedef struct LIST
{
	NODE node;//ͷ�ڵ�
	NODE * end;//�����βָ��ĵ�ַ
	int size;
}LIST;

typedef void * VL;

typedef int(*COMPARE)(void *, void *);

typedef void(*PRINT)(void *);

typedef void(*EXCHANGE)(void *, void *);//����������


//====================�û��Զ�����������====================
//����������ṹ��
typedef struct DATA
{
	char name[1024];
	int a;
}DATA;

//����ڵ�+���� �ṹ��
typedef struct ND
{
	NODE * nodes;
	DATA * dat;
}ND;

//====================API��������====================
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	//��ʼ��
	void INIT_list(VL * head);

	//����
	void ERGO_list(VL head, PRINT pri);

	//����ָ��λ��
	void INSE_list(VL head, int pos, void * data);

	//��ȡָ��λ�õ�ֵ
	void VALU_list(VL head, int pos, void ** data);

	//ɾ��ָ��λ��
	void DEPO_list(VL head, int pos);

	//ɾ��ָ��ֵ
	void DEVA_list(VL head, void * data, COMPARE com);

	//��ȡ�����С
	void SIZE_list(VL head, int * size);

	//��������
	void ORDE_list(VL head, COMPARE com, EXCHANGE exc);

	//��������
	void REVE_list(VL head);

	//����
	void DEST_list(VL * head);

#ifdef __cplusplus
}
#endif // __cplusplus
