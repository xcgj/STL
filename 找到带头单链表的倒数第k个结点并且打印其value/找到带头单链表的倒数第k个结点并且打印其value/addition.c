//��ֻ���ӷ��ҡ�
//��ҹ����һֻ�����������������ҷֳ�����ȵ���ѣ����һֻ�����ǣ����Ե���һ����������һ�ѣ� 
//�ڶ�ֻ��������һ����ֻ���Ķ��ҡ����ǰ��ĶѺ���һ�𣬷ֳ���ȵ���ѣ��ֶ��һ�������ǣ���Ҳ�Ե���һ����������һ�ѣ�
//.....������ֻ����Ҳ���� �����ֵġ�
//�ʣ�����������ж��ٸ���
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
	for (i = 6;; i += 5)//������6���ܷ�һ��
	{
		int j = 0;
		int k = i;//������������ֹi�仯
		for (j = 0; j < 5; j++)//���ҷ�5��
		{
			if ((k - 1) % 5 == 0)
			{

				k = k - 1 - (k - 1) / 5;//��������������Ͱ��������
			}
			else
			{
				break;
			}
		}
		if (5 == j)//�ɹ�����5�Σ�����ѭ��
		{
			break;
		}
	}
	printf("%d\n", i);
	return 0;
}

#endif


