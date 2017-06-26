#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;
#include <vector>
#include <ctime>

//merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
//sort(iterator beg, iterator end, _callback)
//random_shuffle(iterator beg, iterator end)
//reverse(iterator beg, iterator end)

//==============测试类==============//
#include <string>
class Person
{
private:
	mutable string name;
	mutable int age;
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

	//重载>
	bool operator>(const Person & p)const
	{
		return this->age > p.age;//将>改成>=可解决程序崩溃问题
	}

	//重载<
	bool operator<(const Person & p)const
	{
		return this->age <= p.age;
	}
};

//==============自定义函数工具、类工具==============//
class trans
{
public:
	Person operator()(Person p)
	{
		return p;
	}
};

//普通函数作为打印函数
void npri(Person p)
{
	p.PrintInfomation();
}

//==============测试函数==============//
void test()
{
	/*
	常用排序算法

	merge算法 容器元素合并，并存储到另一容器中
	注意:两个容器必须是有序的
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

	sort算法 容器元素排序
	只适用于有随机访问迭代器的容器，会根据容器中元素的数量选择排序方法（堆排序，栈排序、插入排序等）
	@param beg 容器1开始迭代器
	@param end 容器1结束迭代器
	@param _callback 回调函数或者谓词(返回bool类型的函数对象)
	sort(iterator beg, iterator end, _callback)

	random_shuffle算法 对指定范围内的元素随机调整次序
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	random_shuffle(iterator beg, iterator end)

	reverse算法 反转指定范围的元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	reverse(iterator beg, iterator end)
	*/

	/*
		//初始化
	multiset<Person, greater<Person>> m =	//需要重载<使greater函数获取复杂类型比较规则
	{
		Person("ccc", 30),
		Person("aaa", 10),
		Person("eee", 50),
		Person("bbb", 20),
		Person("ddd", 40)
	};
	//再初始化一个
	multiset<Person, greater<Person>> n;	//排序类型要匹配
	n.insert(Person("a", 10));
	n.insert(Person("b", 20));
	n.insert(Person("c", 30));
	n.insert(Person("d", 40));
	n.insert(Person("e", 50));

	//transform拷贝元素
	transform(m.begin(), m.end(), n.begin(), [](Person p)
	{
		return p;
	});
	for_each(n.begin(), n.end(), [](Person p)
	{
		p.PrintInfomation();
	});

	transform(m.begin(), m.end(), n.begin(), trans());
	for_each(n.begin(), n.end(), [](Person p)
	{
		p.PrintInfomation();
	});*/
	//问题代码，出错原因：map和set容器的值不可修改，只能删除和插入

	vector<Person> v1 =	//需要重载<使greater函数获取复杂类型比较规则
	{
		Person("ccc", 30),
		Person("aaa", 10),
		Person("eee", 50),
		Person("bbb", 20),
		Person("ddd", 40)
	};

	vector<Person> v2;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), trans());
	//not2 适配器使用
	sort(v1.begin(), v1.end(), not2(less<Person>()));//降序
	sort(v2.begin(), v2.end(), greater<Person>());
	cout << "==============v2==============" << endl;
	//lambda表达式
	for_each(v2.begin(), v2.end(), [](Person p)
	{
		p.PrintInfomation();
	});

	cout << "==============merge==============" << endl;
	vector<Person> v3;
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), greater<Person>());
	//成员函数作为打印函数
	for_each(v3.begin(), v3.end(), mem_fun_ref(&Person::PrintInfomation));

	cout << "==============sort==============" << endl;
	//对v3排列
	//sort(v3.begin(), v3.end(), not2(greater<Person>()));//此处用not2程序会挂掉
	//sort(v1.begin(), v1.end(), not2(greater<Person>()));//此处用not2程序会挂掉
	sort(v3.begin(), v3.end(), not2(less<Person>()));
	//普通函数作为打印函数——回调函数
	for_each(v3.begin(), v3.end(), npri);
	//for_each(v1.begin(), v1.end(), npri);

	cout << "==============random_shuffle==============" << endl;
	//防止每次产生的结果一样
	srand((unsigned)time(NULL));
	random_shuffle(v3.begin() + 2, v3.end() - 3);
	//auto
	for (auto p : v3)
	{
		p.PrintInfomation();
	}

	cout << "==============reverse==============" << endl;
	reverse(v1.begin(), v1.end());
	//it
	for (vector<Person>::iterator i = v1.begin(); i != v1.end(); ++i)
	{
		i->PrintInfomation();
	}
}

//==============主函数==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
