#pragma once

//��ʼ��
void * INIT_stack();

//��ջ
void PUSH_stack(void * hand, void * data);

//��ջ
void POP_stack(void * hand);

//����ջ
void DESTR_stack(void ** hand);