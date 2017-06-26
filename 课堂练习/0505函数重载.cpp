#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Concrete
{
	friend Concrete operator-(int a, Concrete & obj);
public:
	Concrete(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	Concrete operator-(int c)//成员函数重载 -
	{
		Concrete temp(a + c, b - c);
		return temp;
	}

	void print()
	{
		cout << "a = " << a << ", b = " << b << endl;
	}

private:
	int a = 100;
	int b = 200;
};

//重载[]
class Drive
{
public:
	Drive(int len)
	{
		if (len < 0)
		{
			len = 0;
		}
		length = len;
		a = new int[length];
	}

	Drive(const Drive & obj)
	{
		length = obj.length;
		a = new int[length];
		for (int i = 0; i < length; i++)
		{
			a[i] = obj.a[i];
		}
	}

	~Drive()
	{
		delete[] a;
		a = NULL;
	}

	int& operator[](int index)
	{
		try
		{
			if (index < 0 || index >= length)
			{
				throw index;
			}
		}
		catch (int)
		{
			cout << "非法" << endl;
		}
		
		return a[index];
	}

	Drive & operator=(const Drive & obj)
	{
		if (NULL != a)
		{
			delete[] a;
			a = NULL;
			length = 0;
		}

		length = obj.length;
		a = new int[length];
		for (int i = 0; i < length; i++)
		{
			a[i] = obj.a[i];
		}

		return *this;
	}

private:
	int *a;
	int length;
};


//全局函数重载 -
Concrete operator-(int a, Concrete & obj)
{
	Concrete tmp(a - obj.a, a + obj.b);
	return tmp;
}

int test1(void)
{
	Concrete cre(400, 500);

	Concrete c1 = cre - 100;
	c1.print();

	Concrete c2 = 100 - cre;
	c2.print();

	cout << "Compelete" << endl;;
	return 0;
}

void test2(void)
{
	Drive xc(3);
	xc[0] = 1;
	xc[1] = 3;
	xc[2] = 5;
	//xc[3] = 7;

	Drive gj = xc;
	cout << "a[0]" << gj[0] << endl;
	cout << "a[1]" << gj[1] << endl;
	cout << "a[2]" << gj[2] << endl;

	Drive rb(100);
	rb = gj;
	cout << "a[0]" << rb[0] << endl;
	cout << "a[1]" << rb[1] << endl;
	cout << "a[2]" << rb[2] << endl;

}

int main(void)
{
	//test1();
	test2();
	return 0;
}

