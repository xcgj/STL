//����ֹ�������Ǹ��������������һ���Ǻ������βΣ��仯���ĸ�ֵ�᷵���ĸ���������ֵ��
//�ұ����仯��ϵ����������б�
//�ҷ���ֵ�ͺ����Ĺ�ϵ����һ�μ���Ľ���ͱ��ε��õĺ�����ʲô��ϵ

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
