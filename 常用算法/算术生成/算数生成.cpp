#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include <deque>
#include <functional>
//#include <algorithm>
#include <numeric>
#include <algorithm>

//accumulate(iterator beg, iterator end, value)
//fill(iterator beg, iterator end, value)

//==============测试类==============//
#include <string>
class Person
{
	friend int operator+(int a, Person p);
	friend class mycalc;
private:
	string name;
	int age;
public:
	Person(string n = "abc", int a = 0)
	{
		name = n;
		age = a;
	}

	string GetName()
	{
		return name;
	}

	int GetAge()
	{
		return age;
	}

	void PrintInfomation()
	{
		std::cout << "name = " << name << ", age = " << age << endl;
	}

	//重载=
	//for (; _First != _Last; ++_First) *_First = _Val;
	void operator=(int a)
	{
		this->age = a;
	}

	void operator=(string s)
	{
		this->name = s;
	}
};

//==============工具函数、类==============//
//重载+，根据源码得知返回的是参数3，迭代器在第二参数
//for (; _First != _Last; ++_First) _Val = _Func(_Val, *_First); return (_Val);
int operator+(int a, Person p)
{
	return p.age + a;
}

class mycalc
{
public:
	//参数严格按照源码顺序匹配，第一个一定是参数3的类型
	/*int & operator()(int & a, Person p)
	{
		a = p.age * a;
		return a;
	}*/

	int operator()(int a, Person p)
	{
		return p.age * a;
	}
};

//普通函数打印
void Print(int a, Person p)
{
	p = a + p;
	p.PrintInfomation();
}

//==============测试函数==============//
void test()
{
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	/*
	常用算数生成算法

	accumulate算法 计算容器元素累计总和
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value累加值
	@return 返回value
	accumulate(iterator beg, iterator end, value)

	_Ty _Accumulate_unchecked(_InIt _First, _InIt _Last, _Ty _Val, _Fn2& _Func)
	{	// return sum of _Val and all in [_First, _Last), using _Func
	for (; _First != _Last; ++_First)
	_Val = _Func(_Val, *_First);
	return (_Val);
	}
	_Func：默认是plus<>()



	fill算法 向容器中添加元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value t填充元素
	@return 返回void
	fill(iterator beg, iterator end, value)

	void _Fill_unchecked1(_FwdIt _First, _FwdIt _Last, const _Ty& _Val, false_type)
	{	// copy _Val through [_First, _Last), no special optimization
	for (; _First != _Last; ++_First)
	*_First = _Val;
	}
	//需要重载=
	*/
	deque<Person> q1 = { p1, p2, p4, p5, p3 };
	deque<Person> q2;
	q2 = q1;
	cout << "================accumulate================" << endl;
	//包含在头文件<numeric>中
	//使用默认plus<>()函数对象
	int sum = accumulate(q1.begin(), q1.end(), 0);
	cout << "sum = " << sum << endl;
	//使用自定义函数对象
	int multi = accumulate(q1.begin(), q1.end(), 1, mycalc());
	cout << "multi = " << multi << endl;

	cout << "================fill================" << endl;
	cout << "改年龄================" << endl;
	fill(q1.begin(), q1.end(), 35);//需要重载=
	//普通函数适配器打印
	//先用ptr_fun转成函数对象
	//再绑定
	for_each(q1.begin(), q1.end(), bind1st(ptr_fun(Print), 10));
	cout << "改名字================" << endl;
	fill(q1.begin(), q1.end(), string("zzz")); //需要重载 =,否则Person全部替换，年龄为0
	//成员函数打印
	for_each(q1.begin(), q1.end(), mem_fun_ref(&Person::PrintInfomation));
}

//==============主函数==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
