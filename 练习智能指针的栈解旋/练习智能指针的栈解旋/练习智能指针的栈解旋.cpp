#include <iostream>
#include <exception>//异常处理头文件
#include <string>
using namespace std;

//==============创建测试类==============//
class Person
{
public:
	int age;
	char name[];

public:
	Person(int a)
	{
		age = a;
		cout << "Person 构造函数：" << age << endl;
	}

	~Person()
	{
		cout << "Person 析构函数：" << age << endl;
	}
};

//==============构建智能指针==============//
class Pointer
{
private:
	Person * person;

public:
	//构造函数传入测试类的指针，
	Pointer(Person * transin_person)
	{
		this->person = transin_person;//获得测试类对象的堆空间地址
	}
	//重载->操作符
	Person * operator->()//返回对象指针，恢复->操作符含义
	{
		return this->person;//该地址返回不会失效
	}
	//重载解引用操作符
	Person & operator*()//注意返回引用，用.操作符操作
	{
		return *(this->person);//该地址、引用返回不会失效
	}
	//当作用域结束时，调用智能指针析构函数，使测试类对象自动析构
	~Pointer()
	{
		if (NULL != person)
		{
			delete person;
			person = NULL;
		}
	}
};

//==============创建自己的异常捕获类==============//
class myException : public exception
{
private:
	string message;
public:
	//string初始化的构造函数
	myException(string s)
	{
		message = s;
	}
	//what方法
	string & what()
	{
		return message;
	}
};

//==============抛出异常函数==============//
void throwException(int a)
{
	Person p1(20);				//栈变量
	Person *p2 = new Person(21);//堆空间，栈解旋内存泄漏
	Pointer p3(new Person(23));	//智能指针堆空间

	if (a == 0)
	{
		throw myException("异常捕获");	//开始栈解旋
	}
	
	Person p4(24);				//栈变量，栈解旋不会执行
}

//==============异常处理函数==============//
void exceptionTest()
{
	try
	{
		throwException(0);	//结束栈解旋
	}
	catch (const exception & ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}
}

//==============智能指针构建测试函数==============//
void pointertest()
{
	Pointer p(new Person(10));//p是栈变量
	cout << p->age << endl;
	cout << (*p).age << endl;
}

//==============主函数==============//
int main(void)
{
	//pointertest();

	exceptionTest();

	return 0;
}
