#if 0
//递归
#include <stdio.h>
void foo1()
{
	printf("1\n");
}

void foo2()
{
	foo1();
	printf("2\n");
}

void foo3()
{
	foo2();
	printf("3\n");
}

void foo(int n)
{
	if (n == 0)
		return;
	foo(n - 1);
	printf("%d\n", n);
}

void(*p)(int);
typedef void func(int);
func *f;
typedef void(*ff)(int);
ff f1;

#include <stdarg.h>
//可变参数
void func(int n,int m,...)
{
	va_list ap;
	va_start(ap, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", va_arg(ap, int));
	}
	va_end(ap);
}

void func1(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	const char *temp = str;
	while (temp)
	{
		printf("%s\n", temp);
		temp = va_arg(ap, const char *);
	}
	va_end(ap);
}
#endif
int foo1(int n)
{
	/*int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += i;
	}
	return sum;*/

	/*if (n == 1)
		return 1;
	return n + foo1(n - 1);*/

	//return n*(n + 1) / 2;

	//不允许使用if 三目运算符，for,while,do..while，乘除法
}

typedef int(*F)(int);
F arr[2];
int func0(int n)
{
	return 0;
}

int func1(int n)
{

	return n + arr[!!(n-1)](n - 1);
}

int main()
{
	//func(10,4, 1, 2, 3);
	//func1("haha", "hehe", "heihei");
	//写一个函数,输出从1加到N的值
	arr[0] = func0;
	arr[1] = func1;
	int n = 100;
	printf("%d\n", arr[!!n](n));
	return 0;
}