#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <map>
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

	void PrintInfomation()const//必须加const，要与map函数兼容
	{
		std::cout << "name = " << name << ", age = " << age << endl;
	}
	////重载等号
	//Person & operator= (Person & p)
	//{
	//	this->name = p.name;
	//	this->age = p.age;
	//	return *this;
	//}
	//重载<号
	bool operator<(const Person & p)const
	{
		return this->age < p.age;
	}
	//重载>号
	bool operator>(const Person & p)
	{
		return this->age > p.age;
	}
};

template<typename T>
class MoreToLess
{
public:
	bool operator()(T p1, T p2)
	{
		return p1 > p2;
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

	cout << "==========构造，赋值，插入==========" << endl;
	/*
	map<T1, T2> mapTT;//map默认构造函数: 
	map(const map &mp);//拷贝构造函数

	map& operator=(const map &mp);//重载等号操作符
	swap(mp);//交换两个集合容器

	map.insert(...); //往容器插入元素，返回pair<iterator,bool>
	map<int, string> mapStu;
	// 第一种 通过pair的方式插入对象
	mapStu.insert(pair<int, string>(3, "小张"));
	// 第二种 通过pair的方式插入对象
	mapStu.inset(make_pair(-1, "校长"));
	// 第三种 通过value_type的方式插入对象
	mapStu.insert(map<int, string>::value_type(1, "小李"));
	// 第四种 通过数组的方式插入值
	mapStu[3] = "小刘";
	mapStu[5] = "小王";
	*/
	map<Person, int> m, m1;
	pair<map<Person, int>::iterator, bool> gmit;
	//map.insert()函数返回类型是pair
	gmit = m.insert(pair<Person, int>(p2, 2));
	m.insert(make_pair(p5, 5));
	m.insert(map<Person, int>::value_type(p1, 1));
	m[p3] = 3; m[p4] = 4;
	cout << "==========gmit插入检测==========" << endl;
	cout << "插入状态：" << gmit.second << ", 数据：";
	cout << gmit.first->second << ", ";
	gmit.first->first.PrintInfomation();

	m1 = m;
	cout << "==========遍历m1==========" << endl;
	for (map<Person, int>::iterator i = m1.begin(); i!= m1.end(); ++i)
	{
		cout << i->second << ", ";
		i->first.PrintInfomation();
	}

	//传入函数对象改变排列顺序
	multimap<int, Person, MoreToLess<int>> mm = { {30, p3}, {20, p2}, {10, p1}, {50, p5}, {40, p4} };
	multimap<int, Person>::iterator gmmit;
	mm.insert(map<int, Person>::value_type(30, p2));
	//multimap.insert()函数的返回类型是迭代器

	gmmit = mm.insert(pair<int, Person>(10, p1));
	cout << "==========gmmit插入检测==========" << endl;
	cout << gmmit->first << ", ";
	gmmit->second.PrintInfomation();

	cout << "==========遍历mm1==========" << endl;
	multimap<int, Person, MoreToLess<int>> mm1 = mm;//传入函数对象改变排列顺序
	for (auto val : mm1)
	{
		cout << val.first << ", ";
		val.second.PrintInfomation();
	}
	cout << "==========查找，大小，删除==========" << endl;
	/*
	find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
	count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
	lower_bound(keyElem);//返回第一个key<=keyElem元素的迭代器。
	upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

	size();//返回容器中元素的数目
	empty();//判断容器是否为空

	clear();//删除所有元素
	erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
	erase(beg,end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
	erase(keyElem);//删除容器中key为keyElem的对组。
	*/
	cout << "==========finditm==========" << endl;
	map<Person, int>::iterator finditm;
	finditm = m.find(p3);//查找是时候只需要传入键，不用传值
	if (finditm == m.end())
	{
		cout << "没有这个键" << endl;
	}
	else
	{
		finditm->first.PrintInfomation();
	}
	cout << "==========count_m==========" << endl;
	cout << m.count(p3) << endl;
	cout << "==========lower_bound_m==========" << endl;
	map<Person, int>::iterator lm;
	lm = m.lower_bound(p4);
	cout << lm->second << ", ";
	lm->first.PrintInfomation();
	cout << "==========upper_bound_m==========" << endl;
	lm = m.upper_bound(p4);
	cout << lm->second << ", ";
	lm->first.PrintInfomation();
	cout << "==========equal_range_m==========" << endl;
	pair<map<Person, int>::iterator, map<Person, int>::iterator> pm;
	pm = m.equal_range(p4);
	cout << pm.first->second << ", ";
	pm.first->first.PrintInfomation();
	cout << pm.second->second << ", ";
	pm.second->first.PrintInfomation();
	cout << "==========size_m==========" << endl;
	cout << m.size() << endl;
	cout << m.empty() << endl;
	cout << "==========erase_m_m.begin()==========" << endl;
	lm = m.erase(m.begin());
	cout << lm->second << ", ";
	lm->first.PrintInfomation();
	cout << "==========erase_m_m.begin(), ++m.begin()==========" << endl;
	lm = m.erase(m.begin(), ++m.begin());
	cout << lm->second << ", ";
	lm->first.PrintInfomation();
	cout << "==========erase_m_p5==========" << endl;
	m.erase(p5);
	for (auto val : m)
	{
		cout << val.second << ", ";
		val.first.PrintInfomation();
	}
}

//==============主函数==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
