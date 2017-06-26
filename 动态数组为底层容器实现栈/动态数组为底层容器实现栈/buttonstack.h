#pragma once

//初始化
void * INIT_stack();

//入栈
void PUSH_stack(void * hand, void * data);

//出栈
void POP_stack(void * hand);

//销毁栈
void DESTR_stack(void ** hand);