#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <set>

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

	void PrintInfomation()const
	{
		std::cout << "name = " << name << ", age = " << age << endl;
	}

	Person & operator=(const Person & obj)
	{
		this->name = obj.name;
		this->age = obj.age;
	}

	bool operator<(const Person & obj) const
	{
		return this->age < obj.age;
	}

	bool operator>(const Person & obj) const
	{
		return this->age > obj.age;
	}

	bool operator==(const Person & obj) const
	{
		return (this->age == obj.age) && (this->name == obj.name);
	}
};

template<typename T>
class MoreToLess
{
public:
	bool operator()(const T & p1, const T &p2)const //函数对象重载()比较大小
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
	//构造 赋值 插入
	/*
	set<T> st;//set默认构造函数：
	mulitset<T> mst; //multiset默认构造函数: 
	set(const set &st);//拷贝构造函数

	set& operator=(const set &st);//重载等号操作符
	swap(st);//交换两个集合容器
	insert(elem);//在容器中插入元素。,返回pair类型
	*/
	cout << "========初始化函数中的默认参数========" << endl;
	set<Person> s = {p3, p1, p5, p2, p4};	//默认升序排列
	for (set<Person>::iterator it = s.begin(); it != s.end(); ++it)
	{
		it->PrintInfomation();
	}
	cout << "========set插入返回pair类型========" << endl;
	set<Person> s1 = s;
	set<Person> s2;
	s2 = s1;
	pair<set<Person>::iterator, bool> pa1 = s2.insert(p3);//返回pair
	pa1.first->PrintInfomation();
	cout << pa1.second << endl;
	s2.swap(s1);

	cout << "========修改默认参数改变排序方式========" << endl;
	multiset<Person, MoreToLess<Person>> ms = { p3, p1, p5, p2, p2, p4, p3 };	//指定降序排列，必须使用函数对象
	for (set<Person>::iterator it = ms.begin(); it != ms.end(); ++it)
	{
		it->PrintInfomation();
	}
	cout << "========multiset插入返回迭代器类型========" << endl;
	multiset<Person> s3;
	s3.insert(p2);
	multiset<Person>::iterator pa2 = s3.insert(p2);//返回迭代器
	pa2->PrintInfomation();

	//大小  查找
	/*
	size();//返回容器中元素的数目
	empty();//判断容器是否为空
	find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
	count(key);//查找键key的元素个数
	lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
	*/
	cout << "s1的大小 = " << s1.size() << endl;
	cout << "s1为空？： " << s1.empty() << endl;

	cout << "========find函数========" << endl;
	multiset<Person>::iterator msi = find(ms.begin(),ms.end(), Person("ddd", 40));
	if (msi == ms.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		msi->PrintInfomation();
	}

	int n = s.count(Person("ddd", 40));
	cout << "n = " << n << endl;

	cout << "========遍历========" << endl;
	for (multiset<Person>::iterator i = ms.begin(); i != ms.end(); ++i)
	{
		i->PrintInfomation();
	}

	cout << "========lower_bound函数========" << endl;
	multiset<Person>::iterator msi2 = ms.lower_bound(Person("ddd", 40));
	//auto msi2 = ms.lower_bound(Person("ddd", 40));
	msi2->PrintInfomation();

	cout << "========upper_bound函数========" << endl;
	set<Person>::iterator sit = s.upper_bound(Person("ddd", 40));
	sit->PrintInfomation();

	cout << "========ms.equal_range函数========" << endl;
	pair<multiset<Person>::iterator, multiset<Person>::iterator> pai1 = ms.equal_range(Person("ddd", 45));
	pai1.first->PrintInfomation();
	pai1.second->PrintInfomation();

	//删除
	/*
	clear();//清除所有元素
	erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
	erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
	erase(elem);//删除容器中值为elem的元素。
	*/
	cout << "========遍历s容器========" << endl;
	for (set<Person>::iterator i = s.begin(); i != s.end(); ++i)
	{
		i->PrintInfomation();//12345
	}

	set<Person>::iterator delsi = s.begin();
	delsi++;
	delsi = s.erase(delsi);
	cout << "========delsi的位置========" << endl;
	delsi->PrintInfomation();//3

	cout << "========遍历ms容器========" << endl;
	for (auto i : ms)
	{
		i.PrintInfomation();//5433221
	}

	auto delmsi = ms.begin();//5
	delmsi++;//4
	delmsi++;//3
	delmsi++;//3
	delmsi = ms.erase(++ms.begin(), ++delmsi);//5221
	cout << "========delmsi的位置========" << endl;
	delmsi->PrintInfomation();//2
	ms.erase(Person("bbb", 20));//51
	cout << "========遍历ms容器========" << endl;
	for (multiset<Person>::iterator i = ms.begin(); i != ms.end(); ++i)
	{
		i->PrintInfomation();//51
	}
	ms.clear();
}

//==============主函数==============//
int main(void)
{
	test();
	cout << endl << "Compelete" << endl;
	return 0;
}
