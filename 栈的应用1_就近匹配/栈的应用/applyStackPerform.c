#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "applyStack.h"

//按字符读取字符串
//将读取出来的"("字符、字符位置、节点绑定，组成结构体，其余字符不做处理
//将每次读取的结构体数据压栈
//遇到")"字符时，匹配栈顶字符，栈顶的"("出栈，如果栈为空，标记错误位置
typedef struct DATA
{
	SNODE dnode;
	char ch;
	int index;
}DATA;

//错误位置打印
void errPrint(int err)
{
	for (int i = 0; i < err; i++)
	{
		printf(" ");
	}
	printf("A\n");
}

int main(void)
{
	char * str = "(5+5*6))+9/3*1)-(1+3(";
	printf("%s\n", str);

	int len = strlen(str);
	char c = 0;
#if 1
	VLS stack = NULL;//栈
	INIT_stack(&stack);						//问题一：初始化后，这个stack的next指针无限指向自己
#endif
	
#if 0	
	VLS stack = INIT_stack2();				//问题三：把初始化函数换成这个时，问题一和二同时解决，按理说指针间接赋值和这个的效果应该是一样的，为什么运行结果会不同
#endif

	for (int i = 0; i < len; i++)
	{
		c = *(str + i);
		if (c == '(')
		{
			//打包放入栈中
			DATA * ltmp = (DATA *)malloc(sizeof(DATA));
			ltmp->ch = '(';
			ltmp->index = i;
			ltmp->dnode.next = NULL;

			PUSH_stack(stack, ltmp);		//问题二：将第一个左括号压栈成功后，stack的size变成了负数，但在调用函数中明明已经成功赋值为1
		}

		else if (c == ')')
		{
			//查询栈顶元素
			DATA * rtmp = SEAR_stack(stack);
			if (NULL == rtmp)//空栈
			{
				//记录位置，调用错误位置打印函数
				errPrint(i);
			}

			else //if ('(' == rtmp->ch)
			{
				//弹出栈顶元素，并释放空间
				POP_stack(stack);
				free(rtmp);
			}
		}
	}

	//循环结束，检查栈中元素，依次出栈，调用 错误位置打印函数
	int size = SIZE_stack(stack);
	for (int i = 0; i < size; i++)
	{
		//查询栈顶元素
		DATA * data = (DATA *)SEAR_stack(stack);
		int err = data->index;
		errPrint(err);

		//栈顶元素出栈
		POP_stack(stack);
	}

	//删除栈
	DESTR_stack(&stack);

	printf("Compelete\n");
	return 0;
}
