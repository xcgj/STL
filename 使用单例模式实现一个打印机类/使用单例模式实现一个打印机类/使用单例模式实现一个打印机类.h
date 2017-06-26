#pragma once
/*
使用单例模式实现一个打印机类
打印传入的字符串
累计打印次数
*/
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::wstring;

//=============实现单例==============//
class SINGLETON
{
private:
	static SINGLETON * st;
	static int count;
	string * str;
private:
	SINGLETON();
	SINGLETON(const SINGLETON & obj);
	~SINGLETON();
public:
	static SINGLETON * GetSingleton();
	
	static int GetCount();

	void print(const string & s);
};