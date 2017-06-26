/*
ʹ�õ���ģʽʵ��һ����ӡ����
	��ӡ������ַ���
	�ۼƴ�ӡ����
*/
#include "ʹ�õ���ģʽʵ��һ����ӡ����.h"

//==============��̬������ʼ��==============//

SINGLETON * SINGLETON::st = new SINGLETON;

int SINGLETON::count = 0;

//==============��Ա����ʵ��==============//
//����
SINGLETON::SINGLETON()
{
	str = NULL;
}

//��������
SINGLETON::SINGLETON(const SINGLETON & obj) {}

//����
SINGLETON::~SINGLETON()
{
	if (NULL != st)
	{
		delete st;
		st = NULL;
	}
}

//����ָ��
SINGLETON * SINGLETON::GetSingleton()
{
	return st;
}

//��ӡ
void SINGLETON::print(const string & s)
{
	str = new string(s);
	cout << *str << endl;
	count++;
	if (NULL != str)
	{
		delete str;
		str = NULL;
	}
}

//��ӡ����
int SINGLETON::GetCount()
{
	return count;
}