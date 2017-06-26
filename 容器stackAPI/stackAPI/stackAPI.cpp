#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stack>

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

	Person & operator= (const Person & obj)//必须加const
	{
		name = obj.name;
		age = obj.age;
		return *this;
	}
};

//==============测试函数==============//
void test()
{
	//测试类
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	stack<Person> s4;
	stack<Person> s5;
	s5 = s4;

	//初始化
	//stack<T> stkT;//stack采用模板类实现， stack对象的默认构造形式： 
	//stack(const stack &stk);//拷贝构造函数
	stack<Person> s1;		//默认构造
	stack<Person> s2 = s1;	//拷贝构造
	stack<Person> s3;


	//插入
	s1.push(p1);
	s1.push(p2);
	s1.push(p3);
	s1.push(p4);
	s1.push(p5);

	//push(elem);	//向栈顶添加元素
	//pop();		//从栈顶移除第一个元素
	//top();		//返回栈顶元素
	//empty();		//判断堆栈是否为空
	//size();		//返回堆栈的大小
	//stack& operator=(const stack &stk);//重载等号操作符
	s3 = s2;			//赋值
	Person a = s1.top();//读栈顶
	s1.pop();			//删栈顶
	a.PrintInfomation();
	cout << s1.size() << endl;	//大小
	cout << s1.empty() << endl;	//大小
	//s2.swap(s1);		//交换
}
//栈不能随机访问，没有迭代器
//==============主函数==============//
int main(void)
{
	test();
	cout << "Compelete" << endl;
	return 0;
}
