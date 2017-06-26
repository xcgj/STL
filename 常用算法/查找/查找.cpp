#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <numeric>
using namespace std;

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

	//重载==
	bool operator==(Person &  p)
	{
		return this->name == p.name && this->age == p.age;
	}

	//重载<
	bool operator<(Person & p)
	{
		return this->age < p.age;
	}
};

//==============工具==============//
//遍历函数对象
class Print
{
public:
	void operator()(pair<int, Person> p)
	{
		p.second.PrintInfomation();
	}
};

//普通函数
void print(pair<int, Person> p)
{
	p.second.PrintInfomation();
}

//重载==
bool operator==(pair<int, Person> a, int b)
{
	return a.first == b;
}

//比较函数对象
class BigThan : public binary_function<pair<int, Person>, int, bool>
{
public:
	bool operator()(pair<int, Person> a, int b)const
	{
		return a.first >= b;
	}
};

class adjacentfind
{
public:
	bool operator()(pair<int, Person> a, pair<int, Person> b)
	{
		return a.first == b.first && a.second == b.second;
	}
};

//binary_search ==
//class binarysearch : public binary_function<pair<int, Person>, int, bool>
//{
//public:
//	bool operator()(pair<int, Person> a, int b)const
//	{
//		return a.first == b;
//	}
//};

//binary_search重载<
//class bless
//{
//public:
//	bool operator()(pair<int, Person> a, int b)const
//	{
//		return a.first < b;
//	}
//};
//
//bool operator<(const pair<int, Person> a, const int b)
//{
//	return a.first < b;
//}
//
//class bser
//{
//public:
//	bool operator()(pair<int, Person> a, pair<int, Person> b)
//	{
//		return a.first < b.first;
//	}
//};

//重载两个pair<int, Person>对象的<号，可按键、值、键值匹配，以键为例
bool operator<(pair<int, Person> a, pair<int, Person> b)
{
	return a.second < b.second;
}

class myless
{
public:
	bool operator()(pair<int, Person> a, pair<int, Person> b)
	{
		return a.first < b.first;
	}
};

//==============测试函数==============//
void test()
{
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	/*
	常用查找算法

	find算法 查找元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value 查找的元素
	@return 返回查找元素的位置
	find(iterator beg, iterator end, value)

	adjacent_find算法 查找相邻重复元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  _callback 回调函数或者谓词(返回bool类型的函数对象)
	@return 返回相邻元素的第一个位置的迭代器
	adjacent_find(iterator beg, iterator end, _callback);

	binary_search算法 二分查找法
	注意: 在无序序列中不可用
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value 查找的元素
	@return bool 查找返回true 否则false
	bool binary_search(iterator beg, iterator end, value);

	find_if算法 条件查找
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  callback 回调函数或者谓词(返回bool类型的函数对象)
	@return bool 查找返回true 否则false
	bool find_if(iterator beg, iterator end, _callback);

	count算法 统计元素出现次数
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  value回调函数或者谓词(返回bool类型的函数对象)
	@return int返回元素个数
	size_t count(iterator beg, iterator end, value);

	count_if算法 统计元素出现次数
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  callback 回调函数或者谓词(返回bool类型的函数对象)
	@return int返回元素个数
	size_t count_if(iterator beg, iterator end, _callback);
	*/
	//multimap<int, Person, not2(less<int>)> m;//less<int>是类型，not12修饰的是函数对象的返回值
	multimap<int, Person, less<int>> m;
	m.insert(pair<int, Person>(1, Person("aaa", 10)));
	m.insert(make_pair(2, Person("bbb", 20)));
	m.insert(map<int, Person>::value_type(3, Person("ccc", 30)));
	m.insert(pair<int, Person>(1, Person("aaa", 10)));
	//m[4] = Person("ddd", 40);	multimap不能使用[]，产生二义性，是修改还是增加

	//函数对象、函数指针、lambda表达式、成员函数、普通函数
	//for_each(m.begin(), m.end(), mem_fun_ref(&Person::PrintInfomation));类型转化失败
	cout << "================普通函数 遍历================" << endl;
	for_each(m.begin(), m.end(), ptr_fun(print));
	cout << "================find================" << endl;

	multimap<int, Person>::iterator it;
	it = find(m.begin(), m.end(), 2);//find不是m.find，复杂类型，需要重载==
	it->second.PrintInfomation();

	cout << "================find_if================" << endl;
	it = find_if(m.begin(), m.end(), bind2nd(BigThan(), 2));
	it->second.PrintInfomation();

	cout << "================adjacent_find================" << endl;
	it = adjacent_find(m.begin(), m.end(), adjacentfind());//对组和对组的比较
	it->second.PrintInfomation();

	cout << "================binary_search================" << endl;
	//bool bs = binary_search(m.begin(), m.end(), bind2nd(binarysearch(), 2)/*, bless()*/);//错误
	//binary_search每次都是将键值对整体拿出来比较，因此
	//参数三 或 参数三的返回值 需要是pair<int, Person>
	//参数四需要用pair<int, Person>类型比较，重载两个pair<int, Person>对象的<号
	//bool bs = binary_search(m.begin(), m.end(), pair<int, Person>(0, Person("aaa", 20))/*, less<pair<int, Person>>()*/);//正确
	bool bs = binary_search(m.begin(), m.end(), pair<int, Person>(2, Person())/*, myless()*/);//正确
	//bool bs = binary_search(m.begin(), m.end(), Person(), myless());//错误
	cout << bs << endl;

	cout << "================count================" << endl;
	int cnt = count(m.begin(), m.end(), 1);
	cout << "cnt = " << cnt << endl;

	cout << "================count_if================" << endl;
	cnt = count_if(m.begin(), m.end(), bind2nd(BigThan(), 1));
	cout << "cnt = " << cnt << endl;
}

//==============主函数==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
