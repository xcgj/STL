#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include <algorithm>
#include <numeric>
#include <functional>

//for_each()
//transform()

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

	//重载+
	Person operator+(int val)
	{
		Person temp;
		temp.name = this->name;
		temp.age = this->age + val;
		return temp;
	}
};

//==============工具==============//
//回调函数
bool compare(int a, int b)
{
	return a < b;
}

void print(pair<int, Person> callback)
{
	callback.second.PrintInfomation();
}

Person trans(pair<int, Person> p)//m容器中元素是对组类型的，v容器只需要接受Person类型，所以，提取部分再放入就行
{
	return p.second + 10;		//重载+
}

//函数对象
template <typename T>
class COMPARE
{
public:
	bool operator()(const T a, const T b)const	//只读属性
	{
		return a > b;
	}
};

class ERGODIC
{
public:
	void operator()(pair<int, Person> print)
	{
		print.second.PrintInfomation();
	}
};

class TRANS : public binary_function<pair<int, Person>, int, Person>
{
public:
	Person operator()(pair<int, Person> a, int b)const
	{
		return a.second + b;
	}
};
//==============测试函数==============//
void test()
{
	//map<int, Person, greater<int>> m;
	//map<int, Person, compare> m;	//错误，map需要传入类型名，map<int, Person, compare>是一个类型
	map<int, Person, COMPARE<int>> m;
	m.insert(pair<int, Person>(1, Person("aaa", 10)));
	m.insert(map<int, Person>::value_type(2, Person("bbb", 20)));
	m.insert(make_pair(3, Person("ccc", 30)));
	m[4] = Person("ddd", 40);

	/*
	常用遍历算法

	遍历算法 遍历容器元素
	@param beg 开始迭代器
	@param end 结束迭代器
	@param _callback  函数回调或者函数对象
	@return 函数对象
	for_each(iterator beg, iterator end, _callback);

	transform算法 将指定容器区间元素搬运到另一容器中
	注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
	@param beg1 源容器开始迭代器
	@param end1 源容器结束迭代器
	@param beg2 目标容器开始迭代器
	@param _cakkback 回调函数或者函数对象
	@return 返回目标容器迭代器
	transform(iterator beg1, iterator end1, iterator beg2, _callbakc)
	*/
	cout << "=============lambda 表达式遍历==============" << endl;
	for_each(m.begin(), m.end(), [](pair<int, Person> p)
	{
		p.second.PrintInfomation();
	});
	cout << "=============回调函数 遍历==============" << endl;
	for_each(m.begin(), m.end(), print);
	cout << "=============函数对象 遍历==============" << endl;
	for_each(m.begin(), m.end(), ERGODIC());
	

	//map<int, Person> m2;
	vector<Person> v;
	v.resize(m.size());
	cout << "=============lambda 表达式转移==============" << endl;
	transform(m.begin(), m.end(), v.begin(), [](pair<int, Person> p)	//这里接受每次传入的m容器的对象
	{
		return p.second + 20;	//返回值是返到v容器里面的
	});
	for (Person val : v)
	{
		val.PrintInfomation();
	}
	cout << "=============回调函数 转移==============" << endl;
	transform(m.begin(), m.end(), v.begin(), trans);
	for (Person val : v)
	{
		val.PrintInfomation();
	}
	cout << "=============函数对象 转移==============" << endl;
	vector<Person>::iterator vit = transform(m.begin(), m.end(), v.begin(), bind2nd(TRANS(), 5));
	if (vit == v.end())
	{
		cout << "迭代器指向的位置是v.end()" << endl;
	}
	for (auto val : v)
	{
		val.PrintInfomation();
	}
}

//==============主函数==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
