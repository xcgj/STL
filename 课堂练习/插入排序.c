#include <stdio.h>
#include <stdlib.h>

//插入排序
int main(void)
{
	int a[10] = { 5,2,0,7,9,8,1,3,4,6 };
	int length = sizeof(a) / sizeof(a[0]);

#if 1
	for (int i = 1; i < length; i++)//第0个元素是有序的，需要从第1个数往前开始比较
	{
		if (a[i] < a[i - 1])//升序//第一次判断是否需要移动
		{
			int tmp = a[i]; //第i个元素提取出来，暂时存到临时变量
			//前面的数往后移动一个位置，再前面的数也依次与tmp比较
			int j = i;
			for (; j > 0 && tmp < a[j - 1]; --j)//j == 0 的时候好像有点问题
				//  越界     a[j]的位置刚好是需要插入的位置
			{
				a[j] = a[j - 1];
			}

			a[j] = tmp;
		}
	}
#endif
#if 0
	for (int i = 1; i < length; i++)
	{
		if (a[i] < a[i - 1])
		{
			int tmp = a[i];

			int j = i - 1;
			for (; j >= 0 && tmp < a[j]; --j)
			{
				a[j + 1] = a[j];
			}

			a[j + 1] = tmp;
		}
	}
#endif
	for (int i = 0; i < length; i++)
	{
		printf( "%d ", a[i] );
	}
	printf("\nCompelete\n");
	return 0;
}
