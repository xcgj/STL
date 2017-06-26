#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//==============重载友元函数实现==============//
template<typename T>
class BASE
{
	//==============<<操作符重载==============//
	friend ostream& operator<< <> (ostream & out, BASE & base);
	//	<>的作用是强制模板化，是告诉编译器，这个友元是函数模板的声明，不是普通函数的声明，链接的时候找函数模板
};

template<typename T>
ostream& operator<<(ostream & out, BASE<T> & base)
{
	out << "<<重载" << endl;
	return out;
}
//
//template<typename T>
//operator()(T a)
//{
//	cout << "()重载" << a << endl;
//}

//==============普通友元函数实现==============//
//先声明类
template<typename T> class DERIVE;
//再声明函数
template<typename T> void visit(DERIVE<T> & d);

//void normalfunc();

//再实现类
template<typename T>
class DERIVE
{
private:
	T a;
public:
	DERIVE()
	{
		a = 10;
	}
	//template<typename T2> 要声明是模板函数
	//注意，DERIVE虽然在自身的类里面，但它也是在友元函数模板的声明里，类属是友元函数模板的类属，因此，，
	//一定要加上<T2>，易错点。。。。。。。。。。。。。。。。
	template<typename T2> friend void visit(DERIVE<T2> & d);


	//普通函数实现
	friend void normalfunc();
	//成员函数
	void memberfunc(){}
};

//最后实现函数
template<typename T>
void visit(DERIVE<T> & d)
{
	cout << "类外实现友元模板函数" << d.a << endl;	//编译不报错
}

void normalfunc()
{
	cout << "只是一个普通友元函数" << endl;
}

//==============普通类==============//
class A
{
	int a = 10;
	friend void func(A & b);
};

void func(A & b)
{
	cout << "a = " << b.a << endl;
}
//==============测试函数==============//
void test1()
{
	BASE<int> a;
	cout << a << endl;
}

void test2()
{
	DERIVE<int> c;
	visit(c);//不用加<int>			//报错，无法访问a；
	//normalfunc();
}

void test3()
{
	A test;
	func(test);
}
//==============主函数==============//

int main(void)
{
	//test1();
	test2();
	//test3();
	cout << "Compelete" << endl;
	return 0;
}
