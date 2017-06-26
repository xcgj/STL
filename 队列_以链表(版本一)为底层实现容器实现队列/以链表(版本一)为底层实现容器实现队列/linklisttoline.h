#pragma once

#include "LinkList.h"

//初始化队列
LinkInfo * INIT_line();

//入队
void PUSH_line(void * head, void * data);

//出队
void POP_line(void * head);

//销毁
void DESTR_line(void ** head);