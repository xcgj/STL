
#include "linklisttoline.h"

//��ʼ������
LinkInfo * INIT_line()
{
	return INIT_link();
}

//���
void PUSH_line(void * head, void * data)
{
	int pos = ((LinkInfo *)head)->size;
	INSERT_link(head, pos, data);
}

//����
void POP_line(void * head)
{
	DELPOS_link(head, 0);
}

//����
void DESTR_line(void ** head)
{
	FREE_link(head);
}