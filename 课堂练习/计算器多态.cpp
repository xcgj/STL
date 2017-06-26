#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//==============������==============//

class CALCULATE
{
public:
	virtual int calculate(int, int) = 0;
};

//==============��==============//

class PLUS : public CALCULATE
{
public:
	virtual int calculate(int a, int b)
	{
		return a + b;
	}
};

//==============��==============//

class MIN : public CALCULATE
{
public:
	virtual int calculate(int a, int b)
	{
		return a - b;
	}
};

//==============��==============//

class DIV : public CALCULATE
{
public:
	virtual int calculate(int a, int b)
	{
		if (0 == b)
		{
			cout << "�������Ƿ�" << endl;
			return 0;
		}
		return a / b;
	}
};

//==============��==============//

class MUL : public CALCULATE
{
public:
	virtual int calculate(int a, int b)
	{
		return a * b;
	}
};

//==============������ģ�顪��Ĥ==============//

class MOD : public CALCULATE
{
public:
	virtual int calculate(int a, int b)
	{
		return a % b;
	}
};

//==============���Ժ���==============//

void test1()
{
	CALCULATE * cal = NULL;
	cal = new PLUS;
	cout << cal->calculate(10, 20) << endl;
}

void test2(int a, int b, CALCULATE * cal)
{
	cout << cal->calculate(a, b) << endl;
}

//==============������==============//

int main(void)
{
	//test1();
	MIN * m = new MIN;
	test2(30, 50, m);

	DIV * d = new DIV;
	test2(10, 0, d);

	MOD * mod = new MOD;
	test2(30, 20, mod);

	cout << "Compelete" << endl;
	return 0;
}
