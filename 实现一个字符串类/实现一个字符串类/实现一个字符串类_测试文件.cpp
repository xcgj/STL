#include "ʵ��һ���ַ�����.h"

void test()
{
	cout << "=====�޲ι���=====" << endl;
	MyString a;
	cout << a << endl;

	cout << "=====�вι���=====" << endl;
	MyString b(3, 'b');
	cout << b << endl;

	cout << "=====��������=====" << endl;
	MyString c = b;
	cout << c << endl;
	cout << "�����ַ�������:" << c.Size() << endl;

	cout << "=====��ֵ���������=====" << endl;
	a = c;
	cout << a << endl;
	a = "aaa";
	cout << a << endl;

	cout << "===== ����������� =====" << endl;
	MyString d = a + b;
	cout << d << endl;
	d = d + "ccc";
	cout << d << endl;

	cout << "===== �ӵ���������� =====" << endl;
	MyString e;
	e += d;
	cout << e << endl;
	e += "ddd";
	cout << e << endl;

	cout << "=====�±����������=====" << endl;
	try
	{
		cout << e[5] << endl;
		cout << e[100] << endl;
		cout << e[5] << endl;
	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "δ֪����" << endl;
	}

	cout << "=====�������������=====" << endl;
	cout << "���������ݣ�";
	cin >> e;
	cout << e << endl;
}

int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
