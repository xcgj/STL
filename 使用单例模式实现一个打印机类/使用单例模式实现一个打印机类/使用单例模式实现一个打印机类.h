#pragma once
/*
ʹ�õ���ģʽʵ��һ����ӡ����
��ӡ������ַ���
�ۼƴ�ӡ����
*/
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::wstring;

//=============ʵ�ֵ���==============//
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