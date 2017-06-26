//五只猴子分桃。
//半夜，第一只猴子先起来，它把桃分成了相等的五堆，多出一只。于是，它吃掉了一个，拿走了一堆； 
//第二只猴子起来一看，只有四堆桃。于是把四堆合在一起，分成相等的五堆，又多出一个。于是，它也吃掉了一个，拿走了一堆；
//.....其他几只猴子也都是 这样分的。
//问：这堆桃至少有多少个？
#include <stdio.h>

#if 1
//int n = 5;
int func(int sum, int n)
{
	if (0 == n)
	{
		return 1;
	}

	if ((sum - 1) % 5 == 0)
	{
		return func(sum - 1 - (sum - 1) / 5, n - 1);
	}
	else
	{
		//n = 5;
		return 0;
	}
}

int main(void)
{
	for (int i = 6; ; i += 5)
	{
		if (func(i, 5))
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
#endif

#if 0
int func(int num, int chang, int a)
{
	if (5 == a)
	{
		return num;
	}

	if ((chang - 1) % 5 == 0)
	{
		return func(num, chang - 1 - (chang - 1) / 5, a + 1);
	}

	else
	{
		return func(num + 5, num + 5, 0);
	}
}

int main(void)
{
	printf("%d\n", func(6, 6, 0));
	return 0;
}
#endif

#if 0

int main()
{
	int i = 6;
	for (i = 6;; i += 5)//最少有6个能分一组
	{
		int j = 0;
		int k = i;//辅助变量，防止i变化
		for (j = 0; j < 5; j++)//分桃分5次
		{
			if ((k - 1) % 5 == 0)
			{

				k = k - 1 - (k - 1) / 5;//如果符合条件，就按规则分桃
			}
			else
			{
				break;
			}
		}
		if (5 == j)//成功分了5次，跳出循环
		{
			break;
		}
	}
	printf("%d\n", i);
	return 0;
}

#endif


