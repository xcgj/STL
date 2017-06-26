#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "MidToPos.h"
#include "FuncCalc.h"

//遇到数字，直接输出
//遇到符号：
//	按优先级，( < * / < + -
//	优先级比栈顶元素低，弹出栈顶元素再入栈
//	优先级比栈顶元素高，直接入栈
//	右括号在匹配到左括号前，一直弹出栈顶元素
//	左右括号不打印

int main(void)
{
	char * p = "(8/2+(3-1))*5*1/8+2";// 8 2 / 3 1 - + 5 * 1 -
	char * str = p;

	//初始化函数指针数组
	TELL func[] = { IsDigit, IsLeftBracket, IsPrio, IsRightBracket };

	//创建一个栈
	VMTPS mtpstack;
	INIT_stack(&mtpstack);

	//遍历字符串，输出数字，压栈出栈符号
	while (*str != '\0')
	{
#if 0
		if (isdigit(str[0]))//识别'-'字符出错
		{
			printf("%c ", str[0]);
			str++;
			continue;
		}
#endif
		//直接输出数字
		if (func[0](str[0]))
		{
			printf("%c ", str[0]);
		}

		//符号
		//左括号
		if (func[1](str[0]))
		{
			//入栈，不打印
			PUSH_stack(mtpstack, str);
		}

		//运算符
		if (func[2](str[0]))
		{
#if 0
			//栈为空，直接入栈
			if (0 == SIZE_stack(mtpstack))
			{
				PUSH_stack(mtpstack, str);
			}
			//非空，与栈中元素比优先级
			else
			{
				//读取栈顶元素
				char a = ((char *)TOPREAD_stack(mtpstack))[0];
				if (func[2](str[0]) < func[2](a))//栈顶优先级高
				{
					//栈顶输出，出栈再入栈，只弹一次吗，新的栈顶要不要管???
					printf("%c ", a);
					POP_stack(mtpstack);
					PUSH_stack(mtpstack, str);
				}
				else//栈顶优先级小于等于
				{
					PUSH_stack(mtpstack, str);
				}
			}
#endif
			//栈不为空
			if (0 != SIZE_stack(mtpstack))
			{
				//读取栈顶元素
				char a = ((char *)TOPREAD_stack(mtpstack))[0];
				if (func[2](str[0]) < func[2](a))//栈顶优先级高
				{
					//栈顶输出，栈顶出栈再数据入栈，只弹一次吗，新的栈顶要不要管???
					printf("%c ", a);
					POP_stack(mtpstack);
				}
			}
			PUSH_stack(mtpstack, str);
		}

		//右括号
		if (func[3](str[0]))
		{
			//空栈
			if (0 == SIZE_stack(mtpstack))
			{
				return -1;//表达式有误
			}

			//查询栈顶元素
			while (SIZE_stack(mtpstack))
			{
				char a = ((char *)TOPREAD_stack(mtpstack))[0];
				if (func[1](a))//左括号
				{
					POP_stack(mtpstack);//弹出
					break;
				}
				printf("%c ", a);//其他运算符打印
				POP_stack(mtpstack);//其他运算符也弹出
			}
		}
		str++;
	}

	//清空栈内所有符号
	while (SIZE_stack(mtpstack))
	{
		char a = ((char *)TOPREAD_stack(mtpstack))[0];
		printf("%c ", a);//运算符打印
		POP_stack(mtpstack);//运算符弹出
	}

	//释放栈
	DESTR_stack(&mtpstack);

	printf("\nCompelete\n");
	return 0;
}