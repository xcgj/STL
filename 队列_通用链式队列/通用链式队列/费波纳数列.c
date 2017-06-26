//找终止条件，那个变量（这个变量一般是函数的形参）变化到哪个值会返回哪个数（返回值）
//找变量变化关系，代入参数列表
//找返回值和函数的关系，上一次计算的结果和本次调用的函数有什么关系

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fb(n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}

	return f(n - 1) + f(n - 2);
}

int main(void)
{
	printf("%d\n", fb(6));
	return 0;
}
