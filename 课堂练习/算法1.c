#if 0
	//����5Ԫ1ֻ��ĸ��3Ԫ1ֻ��С��1Ԫ3ֻ����100��Ǯ��100ֻ���ж����ַ�����
	//i+j+k=100
	//5*i+3*j+k/3=100
	//15*i+9*j+k=300
	//14*i+8*j=200
	//7*i+4*j=100
	//4*j=100-7*i
	//j=25-7/4*i; --> i=4n, j=25-7n, n=0..3
#endif

#if 0
	// ��������ҹ���һ�ھ���
	// �ס��ҡ�������������Ҹ���һ�����Ӽ�ˮ
	// �����������ֱ�ʾÿһ�ҵ����ӣ���
	// �ס�2 + �� = ���
	// �ҡ�3 + �� = ���
	// ����4 + �� = ���
	// ����5 + �� = ���
	// ���6 + �� = ���
	// ��ס��ҡ�����������������ӵĳ��Ⱥ;��
	// ���721 = ����*76��
	// ��= ����*76/721; -->����=721*n;
	
#endif
	
#include <stdio.h>
void foo1()
{
	//O(n^3)
	for (int i = 0; i <= 20; ++i)
	{
		for (int j = 0; j <= 33; ++j)
		{
			for (int k = 0; k <= 100; k += 3)
			{
				if (i + j + k == 100 && 5 * i + 3 * j + k / 3 == 100)
				{
					printf("i=%d,j=%d,k=%d\n", i, j, k);
				}
			}
		}
	}
	printf("----------�����ķָ���------------\n");
	//O(n^2)
	for (int i = 0; i <= 20; ++i)
	{
		for (int j = 0; j <= 33; ++j)
		{
			int k = 100 - i - j;
			if (k % 3 == 0 && 5 * i + 3 * j + k / 3 == 100)
			{
				printf("i=%d,j=%d,k=%d\n", i, j, k);
			}
		}
	}
	printf("--------------�����ķָ���-------------\n");
	//O(n)
	for (int n = 0; n <= 3; ++n)
	{
		int i = 4 * n;
		int j = 25 - 7 * n;
		int k = 100 - i - j;
		printf("i=%d,j=%d,k=%d\n", i, j, k);
	}
}

void foo2()
{
#if 0
	for (int js = 1;; ++js)
		for(int j=1;j<js;++j)
			for(int y=1;y<js;++y)
				for(int b=1;b<js;++b)
						for(int d=1;d<js;++d)
							for (int w = 1; w < js; ++w)
							{
								printf("%d\n", w);
								if (j * 2 + y == js && y * 3 + b == js && b * 4 + d == js && d * 5 + w == js && w * 6 + j == js)
								{
									printf("js=%d,j=%d,y=%d,b=%d,d=%d,w=%d\n", js, j, y, b, d, w);
									return;
								}
							}

	for (int js = 1;; ++js)
	{
		for (int j = 1; j < js; ++j)
		{
			int y = js - 2 * j;
			int b = js - 3 * y;
			int d = js - 4 * b;
			int w = js - 5 * d;
			if (y > 0 && b > 0 && d > 0 && w > 0 && w * 6 + j == js)
			{
				printf("js=%d,j=%d,y=%d,b=%d,d=%d,w=%d\n", js, j, y, b, d, w);
				return;
			}
		}
	}
#endif
	for (int n = 1; n <= 4; ++n)
	{
		int js = 721 * n;
		int w = 76 * n;
		int j = js - w * 6;
		int d = (js - w) / 5;
		int b = (js - d) / 4;
		int y = (js - b) / 3;
		printf("js=%d,j=%d,y=%d,b=%d,d=%d,w=%d\n", js, j, y, b, d, w);
	}
}

int main()
{
	//foo1();
	foo2();
	return 0;
}