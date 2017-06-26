#include "实现一个字符串类.h"

void test()
{
	cout << "=====无参构造=====" << endl;
	MyString a;
	cout << a << endl;

	cout << "=====有参构造=====" << endl;
	MyString b(3, 'b');
	cout << b << endl;

	cout << "=====拷贝构造=====" << endl;
	MyString c = b;
	cout << c << endl;
	cout << "返回字符串长度:" << c.Size() << endl;

	cout << "=====赋值运算符重载=====" << endl;
	a = c;
	cout << a << endl;
	a = "aaa";
	cout << a << endl;

	cout << "===== 加运算符重载 =====" << endl;
	MyString d = a + b;
	cout << d << endl;
	d = d + "ccc";
	cout << d << endl;

	cout << "===== 加等运算符重载 =====" << endl;
	MyString e;
	e += d;
	cout << e << endl;
	e += "ddd";
	cout << e << endl;

	cout << "=====下标运算符重载=====" << endl;
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
		cout << "未知错误" << endl;
	}

	cout << "=====输入运算符重载=====" << endl;
	cout << "请输入内容：";
	cin >> e;
	cout << e << endl;
}

int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
