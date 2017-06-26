/*
使用单例模式实现一个打印机类
	打印传入的字符串
	累计打印次数
*/
#include "使用单例模式实现一个打印机类.h"

//==============静态变量初始化==============//

SINGLETON * SINGLETON::st = new SINGLETON;

int SINGLETON::count = 0;

//==============成员函数实现==============//
//构造
SINGLETON::SINGLETON()
{
	str = NULL;
}

//拷贝构造
SINGLETON::SINGLETON(const SINGLETON & obj) {}

//析构
SINGLETON::~SINGLETON()
{
	if (NULL != st)
	{
		delete st;
		st = NULL;
	}
}

//单例指针
SINGLETON * SINGLETON::GetSingleton()
{
	return st;
}

//打印
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

//打印次数
int SINGLETON::GetCount()
{
	return count;
}