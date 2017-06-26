
#include "linklisttoline.h"

//初始化队列
LinkInfo * INIT_line()
{
	return INIT_link();
}

//入队
void PUSH_line(void * head, void * data)
{
	int pos = ((LinkInfo *)head)->size;
	INSERT_link(head, pos, data);
}

//出队
void POP_line(void * head)
{
	DELPOS_link(head, 0);
}

//销毁
void DESTR_line(void ** head)
{
	FREE_link(head);
}