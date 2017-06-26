#include <iostream>

using namespace std;

class A
{
public:
	A()
	{ 
		cout << "A构造" << endl;
	}
	A(int a)
	{
		_a = a;
		cout << "A构造" << a << endl;
	}
	void show()
	{
		cout << "a = " << this->_a << " b = " << this->_b << endl;
	}

	A(const A & obj)
	{
		cout << "A拷贝构造" << endl;
	}

	~A()
	{
		cout << "A析构" << _a << endl;
	}
private:
	int _a;
	int _b;
};

class B : public A
{
public:
	B()
	{
		cout << "B构造" << endl;
	}

	B(const B & obj)
	{
		cout << "B拷贝构造" << endl;
	}

	~B()
	{
		cout << "B析构" << endl;
	}

private:

};

void test1()
{
	A a(1);
	A b(2);
}

int main(void)

{
	test1();
	int *p = new int();
	cout << p << endl;
	cout << *p << endl;
	//B b;
	//A *a = new A [20];
	//A c = b;
	return 0;
}