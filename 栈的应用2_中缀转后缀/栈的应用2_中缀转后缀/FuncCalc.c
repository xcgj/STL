
#include "FuncCalc.h"

//�ж�������
int IsLeftBracket(char c)
{
	if ('(' == c)
	{
		return 1;
	}

	return 0;
}

//�ж�������
int IsRightBracket(char c)
{
	if (')' == c)
	{
		return 1;
	}

	return 0;
}

//�ж����������
int IsPrio(char c)
{
	if ('*' == c || '/' == c)
	{
		return 9;//���ȼ����
	}
	else if ('+' == c || '-' == c)
	{
		return 5;//���ȼ��е�
	}

	return 0;//����������������ȼ���ͣ�����0��ִ����������ıȽ��ж�
}			//��������Ȼ���ȼ���ߣ�����ֻѰ�������ž���ƥ�䣬�����д�С�ж�

//����
int IsDigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return 1;
	}

	return 0;
}