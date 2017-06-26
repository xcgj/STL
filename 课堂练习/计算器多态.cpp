#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//==============抽象类==============//

class CALCULATE
{
public:
	virtual int calculate(int, int) = 0;
};

//==============加==============//

class PLUS : public CALCULATE
{
public:
	virtual int calculate(int a, int b)
	{
		return a + b;
	}
};

//==============减==============//

class MIN : public CALCULATE
{
public:
	virtual int calculate(int a, int b)
	{
		return a - b;
	}
};

//==============除==============//

class DIV : public CALCULATE
{
public:
	virtual int calculate(int a, int b)
	{
		if (0 == b)
		{
			cout << "被除数非法" << endl;
			return 0;
		}
		return a / b;
	}
};

//==============乘==============//

class MUL : public CALCULATE
{
public:
	virtual int calculate(int a, int b)
	{
		return a * b;
	}
};

//==============增加新模块——膜==============//

class MOD : public CALCULATE
{
public:
	virtual int calculate(int a, int b)
	{
		return a % b;
	}
};

//==============测试函数==============//

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

//==============主函数==============//

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
