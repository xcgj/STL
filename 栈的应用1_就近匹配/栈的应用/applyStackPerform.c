#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "applyStack.h"

//���ַ���ȡ�ַ���
//����ȡ������"("�ַ����ַ�λ�á��ڵ�󶨣���ɽṹ�壬�����ַ���������
//��ÿ�ζ�ȡ�Ľṹ������ѹջ
//����")"�ַ�ʱ��ƥ��ջ���ַ���ջ����"("��ջ�����ջΪ�գ���Ǵ���λ��
typedef struct DATA
{
	SNODE dnode;
	char ch;
	int index;
}DATA;

//����λ�ô�ӡ
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
	VLS stack = NULL;//ջ
	INIT_stack(&stack);						//����һ����ʼ�������stack��nextָ������ָ���Լ�
#endif
	
#if 0	
	VLS stack = INIT_stack2();				//���������ѳ�ʼ�������������ʱ������һ�Ͷ�ͬʱ���������˵ָ���Ӹ�ֵ�������Ч��Ӧ����һ���ģ�Ϊʲô���н���᲻ͬ
#endif

	for (int i = 0; i < len; i++)
	{
		c = *(str + i);
		if (c == '(')
		{
			//�������ջ��
			DATA * ltmp = (DATA *)malloc(sizeof(DATA));
			ltmp->ch = '(';
			ltmp->index = i;
			ltmp->dnode.next = NULL;

			PUSH_stack(stack, ltmp);		//�����������һ��������ѹջ�ɹ���stack��size����˸��������ڵ��ú����������Ѿ��ɹ���ֵΪ1
		}

		else if (c == ')')
		{
			//��ѯջ��Ԫ��
			DATA * rtmp = SEAR_stack(stack);
			if (NULL == rtmp)//��ջ
			{
				//��¼λ�ã����ô���λ�ô�ӡ����
				errPrint(i);
			}

			else //if ('(' == rtmp->ch)
			{
				//����ջ��Ԫ�أ����ͷſռ�
				POP_stack(stack);
				free(rtmp);
			}
		}
	}

	//ѭ�����������ջ��Ԫ�أ����γ�ջ������ ����λ�ô�ӡ����
	int size = SIZE_stack(stack);
	for (int i = 0; i < size; i++)
	{
		//��ѯջ��Ԫ��
		DATA * data = (DATA *)SEAR_stack(stack);
		int err = data->index;
		errPrint(err);

		//ջ��Ԫ�س�ջ
		POP_stack(stack);
	}

	//ɾ��ջ
	DESTR_stack(&stack);

	printf("Compelete\n");
	return 0;
}
