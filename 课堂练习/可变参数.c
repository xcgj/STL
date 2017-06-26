#include <stdio.h>
#include <stdarg.h>
/*
va_list		����һ��ָ��
va_start()
va_arg()
va_end
*/
int func1(m, n, ...)
{
	va_list ap;			//����һ��vaָ�����������ָ������б��е�ĳ������
	va_start(ap, n);	//��ʾapָ��ָ���˲���n

	for (int  i = 0; i < n; i++)
		printf("%d\n", va_arg(ap, int));	//apָ��ÿ��ѭ���Ƶ���һ������������ָ��int

	va_end(ap);			//��apָ�뻹ԭ����ʼ״̬
	return 0;
}

int func2(const char * p, ...)
{
	va_list ap;
	va_start(ap, p);

	const char * temp = p;	//����ָ��
	while (temp)
	{
		printf("%s\n", temp);
		temp = va_arg(ap, const char*);
	}

	va_end(ap);
	return 0;
}

int main(void)
{
	func1(1, 4, 3, 2, 5, 7);
	func2("ad", "sd", "zx", "we", "fg", NULL);
	printf("Compelete\n");
	return 0;
}
