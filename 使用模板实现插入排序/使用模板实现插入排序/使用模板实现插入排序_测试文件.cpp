#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

#include "使用模板实现插入排序.hpp"

class CHILD
{
public:
	CHILD(){}
	CHILD(int a, string n)
	{
		age = a;
		name = n;
	}

	bool operator< (CHILD & c)
	{
		return this->age < c.age;
	}

	friend ostream & operator<<(ostream & out, CHILD & child);

private:
	int age;
	string name;
};

ostream & operator<<(ostream& out, CHILD & child)
{
	out << child.name << child.age;
	return out;
}

void test1()
{
	int arr[5] = { 9, 5, 3, 4, 2 };
	InsertSort<int>(arr, 5, COMPARE<int>());
	Print<int>(arr, 5);

	char arrc[] = "ksjagc";
	int len = strlen(arrc);
	InsertSort<char>(arrc, len, COMPARE<char>());
	Print<char>(arrc, len);
}

void test2()
{
	CHILD c1(10, "aaa");
	CHILD c2(11, "bbb");
	CHILD c3(12, "ccc");
	CHILD c4(13, "ddd");
	//COMPARE<CHILD> com;

	CHILD arr[4] = { c4, c2, c1, c3 };
	InsertSort<CHILD>(arr, 4, COMPARE<CHILD>());
	Print<CHILD>(arr, 4);
}

int main(void)
{
	test1();
	test2();
	cout << "Compelete" << endl;
	return 0;
}
