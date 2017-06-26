#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
//set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
//set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

#include <deque>
//#include <stack>
#include <algorithm>
//#include <set>
#include <vector>
#include <functional>

//==============测试类==============//
#include <string>
class Person
{
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

	//重载<
	bool operator<(const Person & p) const
	{
		return this->age < p.age && this->name < p.name;
	}

	//重载>
	bool operator>(const Person & p) const
	{
		return this->age > p.age && this->name > p.name;
	}

	////重载=
	//void operator=(/*multiset<Person> & s, */const Person & p)
	//{
	//	this->name = p.name;
	//	this->age = p.age;
	//}
};

//==============工具函数、类==============//
//重载=
//void dTos(multiset<Person> & s, const Person & p)
//{
//	s.insert(p);
//}

//函数对象
class vprint
{
public:
	void operator()(Person p)
	{
		p.PrintInfomation();
	}
};

//回调函数
void print(Person p)
{
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
	常用集合算法

	set_intersection算法 求两个set集合的交集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
	set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
		return (_STD set_intersection(_First1, _Last1, _First2, _Last2, _Dest, less<>()));////////////////
		_OutIt _Set_intersection_no_deprecate1(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest, _Pr& _Pred)
		{	// AND sets [_First1, _Last1) and [_First2, _Last2), using _Pred, no deprecation warnings
			for (; _First1 != _Last1 && _First2 != _Last2; )
				if (_DEBUG_LT_PRED(_Pred, *_First1, *_First2))
					++_First1;
				else if (_Pred(*_First2, *_First1))
					++_First2;
				else
					{
					*_Dest++ = *_First1++;	////////////////////
					++_First2;
					}

			return (_Dest);
		}

	set_union算法 求两个set集合的并集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
	set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

	set_difference算法 求两个set集合的差集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
	set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
	*/

	//stack<Person> s1 = { p2, p5, p1 };//错误
	/*stack<Person> s1, s2;
	s1.push(p2);
	s1.push(p5);
	s1.push(p1);

	s2.push(p1);
	s2.push(p4);
	s2.push(p3);*/
	//错误，栈不能遍历

	deque<Person> d1 = { p2, p5, p1 };
	deque<Person> d2 = { p1, p4, p3, p5 };
	//multiset<Person> s;//错误，set元素不能修改，不好操作
	vector<Person> v;
	vector<Person>::iterator it;

	//容器要求有序
	sort(d1.begin(), d1.end(), greater<Person>());
	sort(d2.begin(), d2.end(), greater<Person>());

	cout << "================set_intersection 交集================" << endl;
	//根据源码，重载< =
	//set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), s.begin());
	v.resize(min(d1.size(), d2.size()));//取最小值
	cout << v.size() << endl;
	//集合查找的顺序要和容器顺序相同
	it = set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), v.begin(), greater<Person>());
	if (it == v.begin() + 2)
	{
		cout << "迭代器指向 最后一个 元素 后面 的位置" << endl;
	}
	for_each(v.begin(), it, [](Person p)	//结束位置在 it
	{
		p.PrintInfomation();
	});

	cout << "================set_union 并集================" << endl;
	v.clear();
	v.resize(d1.size() + d2.size());
	//it = set_union(d1.begin(), d1.end(), d2.begin(), d2.end(), v.begin(), not2(less<Person>()));//比较不成功，是>=了，greater<Person>()是<
	it = set_union(d1.begin(), d1.end(), d2.begin(), d2.end(), v.begin(), greater<Person>());
	if (it == v.begin() + 5)
	{
		cout << "迭代器指向 最后一个 元素 后面 的位置" << endl;
	}
	for_each(v.begin(), it, vprint());

	cout << "================set_difference 差集================" << endl;
	v.clear();
	v.resize(max(d1.size(), d2.size()));
	cout << "d1相较于d2 的差集================" << endl;
	it = set_difference(d1.begin(), d1.end(), d2.begin(), d2.end(), v.begin(), greater<Person>());
	for_each(v.begin(), it, print);

	cout << "d2相较于d1 的差集================" << endl;
	it = set_difference(d2.begin(), d2.end(), d1.begin(), d1.end(), v.begin(), greater<Person>());
	for_each(v.begin(), it, mem_fun_ref(&Person::PrintInfomation));
}

//==============主函数==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
