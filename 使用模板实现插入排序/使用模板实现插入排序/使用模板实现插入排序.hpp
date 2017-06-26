#pragma once

#include <iostream>

template<typename T>
class COMPARE
{
public:
	COMPARE(){}
	bool operator()(T t1, T t2)
	{
		return t1 < t2;
	}
};

template<typename T>
void InsertSort(T * array, int length, COMPARE<T> com)
{
	for (int i = 1; i < length; ++i)
	{
		if (com(array[i], array[i - 1]))//ÉýÐò <
		{
			T tmp = array[i];
			int j = i - 1;
			for (;j >= 0 && com(tmp, array[j]); --j)
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = tmp;
		}
	}
}

template<typename T>
void Print(T * array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	cout << std::endl;
}