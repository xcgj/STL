#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "数组类.h"

std::ostream & operator<<(std::ostream & out, myArray & obj)
{
	for (int i = 0; i < obj.msize; i++)
	{
		out << obj.array[i] << " ";
	}
	out << endl;
	return out;
}

//默认有参
myArray::myArray(int cap)
{
	mcapacity = cap;
	msize = 0;
	array = new int[mcapacity];
	for (int i = 0; i < mcapacity; i++)
	{
		array[i] = 0;
	}
}

//拷贝构造
myArray::myArray(const myArray & obj)
{
	mcapacity = obj.mcapacity;
	msize = obj.msize;
	array = new int[mcapacity];
	for (int i = 0; i < mcapacity; i++)
	{
		array[i] = obj.array[i];
	}
}

//析构
myArray::~myArray()
{
	if (NULL != array)
	{
		delete[] array;
		array = 0;
		msize = 0;
		mcapacity = 0;
	}
}

//赋值，重载=
myArray & myArray::operator=(const  myArray & obj)
{
	if (NULL != array)
	{
		delete[] array;
		array = 0;
		msize = 0;
		mcapacity = 0;
	}

	mcapacity = obj.mcapacity;
	msize = obj.msize;
	array = new int[mcapacity];
	for (int i = 0; i < mcapacity; i++)
	{
		array[i] = obj.array[i];
	}

	return *this;
}

//重载[]
int & myArray::operator[](int index)//考虑函数返回值当左值
{
	if (index < 0 || index > msize)
	{
		cout << "越界" << endl;
	}
	return array[index];
}

//重载<<
myArray & myArray::operator<<(const int & val)
{
	this->pushback(val);
	return *this;
}

//函数对象
bool myArray::operator()(myArray & obj)
{
	if (msize > obj.msize)
	{
		return true;
	}

	return false;
}

//插入
void myArray::pushback(const int & a)
{
	if (msize == mcapacity)
	{
		mcapacity *= 2;
		int * tmp = new int[mcapacity];
		int i = 0;
		for (; i < msize; i++)
		{
			tmp[i] = array[i];
		}
		for (; i < mcapacity; i++)
		{
			tmp[i] = 0;
		}
		delete[] array;
		array = tmp;
	}

	array[msize] = a;
	msize++;
}

//删除
void myArray::pop()
{
	if (0 == msize)
	{
		return;
	}

	array[msize - 1] = 0;
	msize--;
}

//查大小
int myArray::size()
{
	return msize;
}