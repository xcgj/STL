#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "InterFace.h"
#include "functions.h"

#pragma comment(lib,"./OpenWifi.lib")

int main(void) 
{
	//��ʼ������ָ��ṹ��
	CHO stru;
	INIT_choice(&stru, choice1, choice2);

	//���û�������ú���
	printf("�����������Ӧ���ã�\n\n");
	printf("1������wifi���ֺ�����\n2����Ĭ����������wifi\n\nѡ��");
	int choice = 0;
	scanf("%d", &choice);
	if (1 != choice && 2 != choice)
	{
		printf("\nѡ����󣬳����˳�\n\n");
		goto End;
	}

	//����
	stru.a[choice - 1]();

	//��������
	printf("ϵͳwifi�������óɹ������ֻ�δ��⵽wifi�����������֣�1\n");
	getchar();//�Իس�

	char state;
	state = getchar();
	if ('1' == state)
	{
		system("ncpa.cpl");
		printf("\n�밴���·����������ã�\n���Ҽ����ӵ����� -> ���� -> ���� -> ��ѡȫ����ѡ�񡰱������� *x��\n\n");
	}

End:
	system("pause");

	return 0;
}