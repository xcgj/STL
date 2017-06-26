
#include "FuncCalc.h"

//判断左括号
int IsLeftBracket(char c)
{
	if ('(' == c)
	{
		return 1;
	}

	return 0;
}

//判断右括号
int IsRightBracket(char c)
{
	if (')' == c)
	{
		return 1;
	}

	return 0;
}

//判断四则运算符
int IsPrio(char c)
{
	if ('*' == c || '/' == c)
	{
		return 9;//优先级最高
	}
	else if ('+' == c || '-' == c)
	{
		return 5;//优先级中等
	}

	return 0;//不是四则运算符优先级最低，返回0不执行四则运算的比较判断
}			//右括号虽然优先级最高，但他只寻找左括号经行匹配，不进行大小判断

//数字
int IsDigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return 1;
	}

	return 0;
}