#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "MidToPos.h"
#include "FuncCalc.h"

//�������֣�ֱ�����
//�������ţ�
//	�����ȼ���( < * / < + -
//	���ȼ���ջ��Ԫ�صͣ�����ջ��Ԫ������ջ
//	���ȼ���ջ��Ԫ�ظߣ�ֱ����ջ
//	��������ƥ�䵽������ǰ��һֱ����ջ��Ԫ��
//	�������Ų���ӡ

int main(void)
{
	char * p = "(8/2+(3-1))*5*1/8+2";// 8 2 / 3 1 - + 5 * 1 -
	char * str = p;

	//��ʼ������ָ������
	TELL func[] = { IsDigit, IsLeftBracket, IsPrio, IsRightBracket };

	//����һ��ջ
	VMTPS mtpstack;
	INIT_stack(&mtpstack);

	//�����ַ�����������֣�ѹջ��ջ����
	while (*str != '\0')
	{
#if 0
		if (isdigit(str[0]))//ʶ��'-'�ַ�����
		{
			printf("%c ", str[0]);
			str++;
			continue;
		}
#endif
		//ֱ���������
		if (func[0](str[0]))
		{
			printf("%c ", str[0]);
		}

		//����
		//������
		if (func[1](str[0]))
		{
			//��ջ������ӡ
			PUSH_stack(mtpstack, str);
		}

		//�����
		if (func[2](str[0]))
		{
#if 0
			//ջΪ�գ�ֱ����ջ
			if (0 == SIZE_stack(mtpstack))
			{
				PUSH_stack(mtpstack, str);
			}
			//�ǿգ���ջ��Ԫ�ر����ȼ�
			else
			{
				//��ȡջ��Ԫ��
				char a = ((char *)TOPREAD_stack(mtpstack))[0];
				if (func[2](str[0]) < func[2](a))//ջ�����ȼ���
				{
					//ջ���������ջ����ջ��ֻ��һ�����µ�ջ��Ҫ��Ҫ��???
					printf("%c ", a);
					POP_stack(mtpstack);
					PUSH_stack(mtpstack, str);
				}
				else//ջ�����ȼ�С�ڵ���
				{
					PUSH_stack(mtpstack, str);
				}
			}
#endif
			//ջ��Ϊ��
			if (0 != SIZE_stack(mtpstack))
			{
				//��ȡջ��Ԫ��
				char a = ((char *)TOPREAD_stack(mtpstack))[0];
				if (func[2](str[0]) < func[2](a))//ջ�����ȼ���
				{
					//ջ�������ջ����ջ��������ջ��ֻ��һ�����µ�ջ��Ҫ��Ҫ��???
					printf("%c ", a);
					POP_stack(mtpstack);
				}
			}
			PUSH_stack(mtpstack, str);
		}

		//������
		if (func[3](str[0]))
		{
			//��ջ
			if (0 == SIZE_stack(mtpstack))
			{
				return -1;//���ʽ����
			}

			//��ѯջ��Ԫ��
			while (SIZE_stack(mtpstack))
			{
				char a = ((char *)TOPREAD_stack(mtpstack))[0];
				if (func[1](a))//������
				{
					POP_stack(mtpstack);//����
					break;
				}
				printf("%c ", a);//�����������ӡ
				POP_stack(mtpstack);//���������Ҳ����
			}
		}
		str++;
	}

	//���ջ�����з���
	while (SIZE_stack(mtpstack))
	{
		char a = ((char *)TOPREAD_stack(mtpstack))[0];
		printf("%c ", a);//�������ӡ
		POP_stack(mtpstack);//���������
	}

	//�ͷ�ջ
	DESTR_stack(&mtpstack);

	printf("\nCompelete\n");
	return 0;
}