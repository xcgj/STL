#pragma once

#include "LinkList.h"

//��ʼ������
LinkInfo * INIT_line();

//���
void PUSH_line(void * head, void * data);

//����
void POP_line(void * head);

//����
void DESTR_line(void ** head);