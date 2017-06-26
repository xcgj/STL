#include <stdio.h>
#include <stdarg.h>
/*
va_list		定义一个指针
va_start()
va_arg()
va_end
*/
int func1(m, n, ...)
{
	va_list ap;			//定义一个va指针变量，用来指向参数列表中的某个参数
	va_start(ap, n);	//表示ap指针指向了参数n

	for (int  i = 0; i < n; i++)
		printf("%d\n", va_arg(ap, int));	//ap指针每次循环移到下一个参数，步长指定int

	va_end(ap);			//将ap指针还原到初始状态
	return 0;
}

int func2(const char * p, ...)
{
	va_list ap;
	va_start(ap, p);

	const char * temp = p;	//辅助指针
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
