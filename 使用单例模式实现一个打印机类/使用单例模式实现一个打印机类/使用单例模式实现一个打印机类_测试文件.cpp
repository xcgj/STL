
#include "ʹ�õ���ģʽʵ��һ����ӡ����.h"

void test()
{
	//3��ʹ�ô�ӡ��
	SINGLETON * p1 = SINGLETON::GetSingleton();
	SINGLETON * p2 = SINGLETON::GetSingleton();
	SINGLETON * p3 = SINGLETON::GetSingleton();

	//��ӡ�ļ�
	p1->print("aaa");
	p2->print("bbb");
	p1->print("aaa");
	p3->print("ccc");
	p2->print("bbb");

	//��ӡ����
	cout << "�ܹ���ӡ�Ĵ���Ϊ��" << SINGLETON::GetCount() << endl;
}

int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
