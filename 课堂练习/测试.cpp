#include <iostream>

using namespace std;

class A
{
public:
	A()
	{ 
		cout << "A����" << endl;
	}
	A(int a)
	{
		_a = a;
		cout << "A����" << a << endl;
	}
	void show()
	{
		cout << "a = " << this->_a << " b = " << this->_b << endl;
	}

	A(const A & obj)
	{
		cout << "A��������" << endl;
	}

	~A()
	{
		cout << "A����" << _a << endl;
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
		cout << "B����" << endl;
	}

	B(const B & obj)
	{
		cout << "B��������" << endl;
	}

	~B()
	{
		cout << "B����" << endl;
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