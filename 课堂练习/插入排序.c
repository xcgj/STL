#include <stdio.h>
#include <stdlib.h>

//��������
int main(void)
{
	int a[10] = { 5,2,0,7,9,8,1,3,4,6 };
	int length = sizeof(a) / sizeof(a[0]);

#if 1
	for (int i = 1; i < length; i++)//��0��Ԫ��������ģ���Ҫ�ӵ�1������ǰ��ʼ�Ƚ�
	{
		if (a[i] < a[i - 1])//����//��һ���ж��Ƿ���Ҫ�ƶ�
		{
			int tmp = a[i]; //��i��Ԫ����ȡ��������ʱ�浽��ʱ����
			//ǰ����������ƶ�һ��λ�ã���ǰ�����Ҳ������tmp�Ƚ�
			int j = i;
			for (; j > 0 && tmp < a[j - 1]; --j)//j == 0 ��ʱ������е�����
				//  Խ��     a[j]��λ�øպ�����Ҫ�����λ��
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
