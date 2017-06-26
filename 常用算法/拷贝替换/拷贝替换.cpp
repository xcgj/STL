#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
using namespace std;

#include <algorithm>
#include <functional>

//copy(iterator beg, iterator end, iterator dest)
//replace(iterator beg, iterator end, oldvalue, newvalue)
//replace_if(iterator beg, iterator end, _callback, newvalue)
//swap(container c1, container c2)

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

	//重<
	bool operator<(Person p)const
	{
		return this->age < p.age;
	}

	//重>
	bool operator>(Person p) const
	{
		return this->age > p.age;
	}

	bool operator>(int a)
	{
		return this->age > a;
	}

	//重载==
	bool operator==(Person p)
	{
		return this->age == p.age && this->name == p.name;
	}

	//重载+=
	Person & operator+= (int a)
	{
		this->age += a;
		return *this;
	}
};

//==============工具函数、类==============//
//普通函数打印
void normalPrint(Person p)
{
	p.PrintInfomation();
}
//适配器绑定普通函数
void normalPrintAdp(Person p, int a)
{
	p += 5;	//重载+=
	p.PrintInfomation();
}
//函数对象打印
class cPrint
{
public:
	void operator()(Person & p)
	{
		p.PrintInfomation();
	}
};
//函数对象替换，采用适配器替换
class replaceIf : public binary_function<Person, int, bool>
{
public:
	bool operator()(Person p, int a)const
	{
		return p > a;
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
	常用拷贝和替换算法

	copy算法 将容器内指定范围的元素拷贝到另一容器中
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param dest 目标容器结束迭代器
	@return 返回目标容器的迭代器
	copy(iterator beg, iterator end, iterator dest)

	replace算法 将容器内指定范围的旧元素修改为新元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param oldvalue 旧元素
	@param newvalue 新元素
	@return 返回void
	replace(iterator beg, iterator end, oldvalue, newvalue)

	replace_if算法 将容器内指定范围满足条件的元素替换为新元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param callback函数回调或者谓词(返回Bool类型的函数对象)
	@param newvalue 新元素
	@return 返回void
	replace_if(iterator beg, iterator end, _callback, newvalue)

	swap算法 互换两个容器的元素
	@param c1容器1
	@param c2容器2
	@return 返回void
	swap(container c1, container c2)
	*/
	list<Person> lis1 = { p1, p3, p5, p4, p2 };

	cout << "lambda 打印================" << endl;
	for_each(lis1.begin(), lis1.end(), [](Person p)
	{
		p.PrintInfomation();
	});

	list<Person> lis2 = lis1;
	//list 排序函数
	//lis2.sort();
	//lis2.sort(not2(greater<Person>()));
	lis2.sort(not2(less<Person>()));//需要重载比较符号
	cout << "普通函数打印================" << endl;
	for_each(lis2.begin(), lis2.end(), normalPrint);

	//用来查看返回值的迭代器
	list<Person>::iterator it;
	cout << "================copy================" << endl;
	it = copy(lis2.begin(), lis2.end(), lis1.begin());
	//it的值
	if (it == lis1.end())
	{
		cout << "it 到达目标容器结尾" << endl;
	}
	//遍历拷贝出来的容器，函数对象打印
	cout << "函数对象打印================" << endl;
	for_each(lis1.begin(), lis1.end(), cPrint());

	cout << "================replace================" << endl;
	replace(lis1.begin(), lis1.end(), p4, p1);//需要重载==，=可重载可使用默认
	cout << "成员函数打印================" << endl;
	for_each(lis1.begin(), lis1.end(), mem_fun_ref(&Person::PrintInfomation));

	cout << "================replace_if================" << endl;/////////难点
	//将年龄大于30的人都换成p3，用函数对象适配器的方法
	replace_if(lis1.begin(), lis1.end(), bind2nd(replaceIf(), 30), p3);
	cout << "适配器绑定普通函数打印================" << endl;
	//先用ptr_fun转换成函数对象，再绑定
	//ptr_fun将一个函数指针转换为一个binary_function的继承类pointer_to_binary_function
	//本例普通函数需要2个参数，一个来自迭代器，一个是自定义，规则在打印函数中定义
	for_each(lis1.begin(), lis1.end(), bind2nd(ptr_fun(normalPrintAdp), 5));

	cout << "================swap================" << endl;
	swap(lis1, lis2);
	cout << "it打印lis2================" << endl;
	for (list<Person>::iterator i = lis2.begin(); i != lis2.end(); ++i)
	{
		i->PrintInfomation();
	}
	cout << "auto打印lis1================" << endl;
	for (auto i : lis1)
	{
		i.PrintInfomation();
	}
}

//==============主函数==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
