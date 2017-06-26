
#include "实现一个字符串类.h"

//==============成员函数==============//
//无参构造
MyString::MyString()
{
	mSize = 0;
	pAddress = new char[mSize + 1];
	pAddress[mSize] = '\0';
}

//有参构造，指定大小和初始值
MyString::MyString(int n, char c)
{
	if (n < 0)
	{
		n = 0;
	}
	mSize = n;
	pAddress = new char[mSize + 1];
	for (int i = 0; i < mSize; ++i)
	{
		pAddress[i] = c;
	}
	pAddress[mSize] = '\0';
}

//拷贝构造
MyString::MyString(const MyString & str)
{
	mSize = str.mSize;
	pAddress = new char[mSize + 1];
	strcpy(pAddress, str.pAddress);
}

//析构函数
MyString::~MyString()
{
	if (pAddress != NULL)
	{
		delete[] pAddress;
		pAddress = NULL;
	}
	mSize = 0;
}

//返回字符串长度
int MyString::Size()
{
	return mSize;
}

//==============成员函数运算符重载==============//
// 赋值运算符重载
MyString& MyString::operator=(const MyString& str)
{
	if (NULL != pAddress)
	{
		delete[] pAddress;
		pAddress = NULL;
		mSize = 0;
	}
	mSize = str.mSize;
	pAddress = new char[mSize + 1];
	strcpy(pAddress, str.pAddress);
	return *this;
}

MyString& MyString::operator=(const char* str)
{
	if (NULL != pAddress)
	{
		delete[] pAddress;
		pAddress = NULL;
		mSize = 0;
	}
	if (NULL == str)
	{
		mSize = 0;
	}
	else
	{
		mSize = strlen(str);
	}
	pAddress = new char[mSize + 1];
	strcpy(pAddress, str);
	pAddress[mSize] = '\0';
	return *this;
}

//加号运算符重载
MyString MyString::operator+(const MyString& str)
{
	MyString tmp;
	if (NULL != tmp.pAddress)
	{
		delete tmp.pAddress;
		tmp.pAddress = NULL;
		tmp.mSize = 0;
	}

	tmp.mSize = this->mSize + str.mSize;
	tmp.pAddress = new char[tmp.mSize + 1];

	strcpy(tmp.pAddress, this->pAddress);
	strcat(tmp.pAddress, str.pAddress);
	(tmp.pAddress)[tmp.mSize] = '\0';

	return tmp;
}

MyString MyString::operator+(const char *s)
{
	MyString tmp;
	if (NULL != tmp.pAddress)
	{
		delete tmp.pAddress;
		tmp.pAddress = NULL;
		tmp.mSize = 0;
	}

	tmp.mSize = this->mSize + strlen(s);
	tmp.pAddress = new char[tmp.mSize + 1];

	strcpy(tmp.pAddress, this->pAddress);
	strcat(tmp.pAddress, s);
	(tmp.pAddress)[tmp.mSize] = '\0';
	return tmp;
}

//加等运算符重载
MyString& MyString::operator+=(const MyString& str)
{
	MyString tmp = *this;
	if (NULL != pAddress)
	{
		delete pAddress;
		pAddress = NULL;
		mSize = 0;
	}

	*this = tmp + str;

	return *this;
}

MyString& MyString::operator+=(const char *s)
{
	MyString tmp = *this;
	if (NULL != pAddress)
	{
		delete pAddress;
		pAddress = NULL;
		mSize = 0;
	}

	*this = tmp + s;

	return *this;
}

//下标运算符重载
char& MyString::operator[](int index)
{
	if (index < 0 || index >= mSize)
	{
		throw out_of_range("下标越界");
	}
	return pAddress[index];
}

//==============友元函数==============//
//输出运算符重载
ostream& operator<<(ostream &out, MyString &str)
{
	out << str.pAddress;
	return out;
}

//输入运算符重载
istream& operator >> (istream &in, MyString &str)
{
	char buf[1024] = { 0 };
	in >> buf;
	str = buf;
	return in;
}