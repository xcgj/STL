#include "DynamicArray.h"

//��ʼ��
void * INIT_stack()
{
	return INIT_array();
}

//��ջ
void PUSH_stack(void * hand, void * data)
{
	INSERT_array(hand, 0, data);
}

//��ջ
void POP_stack(void * hand)
{
	DELPOS_array(hand, 0);
}

//����ջ
void DESTR_stack(void ** hand)
{
	FREE_array(hand);
}