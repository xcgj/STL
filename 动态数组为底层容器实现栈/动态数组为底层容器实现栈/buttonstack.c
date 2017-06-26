#include "DynamicArray.h"

//初始化
void * INIT_stack()
{
	return INIT_array();
}

//入栈
void PUSH_stack(void * hand, void * data)
{
	INSERT_array(hand, 0, data);
}

//出栈
void POP_stack(void * hand)
{
	DELPOS_array(hand, 0);
}

//销毁栈
void DESTR_stack(void ** hand)
{
	FREE_array(hand);
}