#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <string>
using namespace std;

//==============用户自定数据类型==============//
class Person
{
private:
	int age;
	string name;
public:
	Person()
	{

	}
	Person(int a, string n)
	{
		age = a;
		name = n;
	}
	void Prnt()
	{
		cout << name << " " << age << endl;
	}
};

void dequeAPI()
{
	Person p1(10, "aa");
	Person p2(20, "bb");
	Person p3(30, "cc");
	Person p4(40, "dd");
	Person p5(50, "ee");
//==============构造==============//
	/*
	deque<T> deqT;//默认构造形式
	deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
	deque(n, elem);//构造函数将n个elem拷贝给本身。
	deque(const deque &deq);//拷贝构造函数。
	*/
	deque<Person> d1;
	deque<Person> d2(d1.begin(), d1.end());
	deque<Person> d3(3, p5);
	deque<Person> d4 = d3;
	deque<Person> d5(d4);
//==============插入删除==============//
	/*
	push_back(elem);//在容器尾部添加一个数据
	push_front(elem);//在容器头部插入一个数据
	insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
	insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
	insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
	*/
	d1.push_back(p1);
	d1.push_front(p2);
	d1.insert(d1.begin() + 1, p3);
	d1.insert(d1.begin(), 2, p4);
	d1.insert(d1.begin() + 2, d3.begin(), d3.begin() + 1);
	for (deque<Person>::iterator i = d1.begin(); i != d1.end(); ++i)
	{
		i->Prnt();
	}
//=============删除===============//
	/*
	pop_back();//删除容器最后一个数据
	pop_front();//删除容器第一个数据
	clear();//移除容器的所有数据
	erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
	erase(pos);//删除pos位置的数据，返回下一个数据的位置。
	*/
	d2 = d1;
	d2.pop_back();
	d2.pop_front();
	d2.erase(d2.begin() + 1);
	d2.erase(d2.end() - 2, d2.end());
	d2.clear();
//==============查询==============//
	/*
	at(idx);//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
	operator[];//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
	front();//返回第一个数据。
	back();//返回最后一个数据
	*/
	d1.at(1);
	d1[2];
	d1.front();
	d1.back();
//==============赋值==============//
	/*
	assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
	assign(n, elem);//将n个elem拷贝赋值给本身。
	deque& operator=(const deque &deq); //重载等号操作符 
	swap(deq);// 将deq与本身的元素互换
	*/
	d2.assign(d1.begin() + 1, d1.end());
	d3.assign(3, p3);
	d4 = d2;
	d3.swap(d2);
//==============大小==============//
	/*
	deque.size();//返回容器中元素的个数
	deque.empty();//判断容器是否为空
	deque.resize(num);//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
	deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。
	*/
	d1.size();
	d1.empty();
	d1.resize(10);
	d1.resize(20, p2);
}

int main(void)
{
	dequeAPI();

	cout << "Compelete" << endl;
	return 0;
}
