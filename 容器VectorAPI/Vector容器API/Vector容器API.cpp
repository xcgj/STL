#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

//==============用户自定数据类型==============//
class Person
{
public:
	int age;
	string name;
public:
	Person(int a, string n)
	{
		age = a;
		name = n;
	}
};

void APItest()
{
	Person p1(10, "aa");
	Person p2(20, "bb");
	Person p3(30, "cc");
	Person p4(40, "dd");
	Person p5(50, "ee");
//==============构造函数==============//
	/*
	vector<T> v; //采用模板实现类实现，默认构造函数
	vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
	vector(n, elem);//构造函数将n个elem拷贝给本身。
	vector(const vector &vec);//拷贝构造函数。
	*/
	vector<Person> v1(5, Person(10, "dd"));
	vector<Person> v2 = v1;
	vector<Person> v3(v2);
	vector<Person> v4(v3.begin() + 1, v3.end() - 1);
	vector<Person> v5;
	cout << "构造函数v3" << endl;
	for (auto val : v3)
	//for (vector<Person>::iterator val : v3)
	{
		cout << val.name << " " << val.age << endl;
	}
	cout << "构造函数v4" << endl;
	for(vector<Person>::iterator it = v4.begin(); it != v4.end(); ++it)
	{
		cout << it->name << " " << (*it).age << endl;
	}

//==============插入删除==============//
	/*
	insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
	push_back(ele); //尾部插入元素ele
	pop_back();//删除最后一个元素
	erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
	erase(const_iterator pos);//删除迭代器指向的元素
	clear();//删除容器中所有元素
	*/
	v1.clear();
	vector<Person*> v;
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.insert(v.begin() + 1, 1, &p4);
	v.insert(v.begin() + 1, 1, &p5);
	cout << "插入" << endl;
	for (auto val : v)
	{
		cout << val->name << " " << val->age << endl;
	}
	cout << "删除" << endl;
	v.pop_back();
	v.erase(v.begin(), v.begin() + 1);
	v.erase(v.begin() + 2);
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it)->name << " " << (*it)->age << endl;
	}
//==============赋值==============//
	/*
	assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
	assign(n, elem);//将n个elem拷贝赋值给本身。
	vector& operator=(const vector  &vec);//重载等号操作符
	swap(vec);// 将vec与本身的元素互换。
	*/
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);//54123
	vector<Person *> v6, v7, v8, v9;
	v6.assign(v.begin(), v.begin() + 4);//5412
	v7.assign(3, *(v6.begin() + 1));//444
	v8 = v7;
	v9.swap(v8);
	cout << "v6赋值" << endl;
	for (auto val : v6)
	//for (vector<Person*> val : &v6)
	{
		cout << (*val).age << " " << val->name << endl;
	}
	cout << "v9赋值" << endl;
	for (vector<Person*>::iterator it = v9.begin(); it != v9.end(); ++it)
	{
		cout << (*it)->name << " " << (*it)->age << endl;
	}
//==============大小==============//
	/*
	size();//返回容器中元素的个数
	empty();//判断容器是否为空
	resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
	resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
	capacity();//容器的容量
	reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
	*/
	v.size();
	v.empty();
	v.resize(8);
	v.resize(10, &p1);
	v.capacity();
	v.reserve(20);
//==============存取==============//
	/*
	at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
	operator[];//返回索引idx所指的数据，越界时，运行直接报错
	front();//返回容器中第一个数据元素
	back();//返回容器中最后一个数据元素
	*/
	v.at(3);
	v[2];
	v.front();
	v.back();
}

//==============收缩空间==============/
void shrink()
{
	vector<int> v;
	v.resize(1000);	//v.capacity() 1000;	v.size()1000
	v.resize(10);	//v.capacity() 1000;	v.size()10
	vector<int>(v).swap(v);//指向匿名对象的指针变量 和 指向 v 的指针变量 交换指针指向后，匿名对象的指针变量将指向的空间释放
	cout << v.size() << v.capacity();//10 10
}

//==============容器嵌套容器==============//
void vectorinvector()
{
	//先生成子容器
	vector<Person> v1;
	vector<Person> v2;
	vector<Person> v3;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(Person(10 * i + 1, "a"));
		v2.push_back(Person(10 * i + 2, "b"));
		v3.push_back(Person(10 * i + 3, "c"));
	}
	//主容器包含子容器
	vector< vector<Person> > v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	//遍历容器
	for (vector< vector<Person> >::iterator it = v.begin(); it != v.end(); ++it)
	{
		for (vector<Person>::iterator i = it->begin(); i != it->end() ; ++i)
		{
			cout << i->name << " " << i->age << endl;
		}
	}
}

//==============主函数==============//
int main(void)
{
	//APItest();
	//shrink();
	vectorinvector();

	cout << "Compelete" << endl;
	return 0;
}
