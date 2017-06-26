#include <iostream>
//#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

//实现原理
/*
将 用户函数对象 和 用户参数 传入 bind2nd 函数：用户对象函数 自带了容器中的参数
bind2nd函数 调用了 binder2nd 函数对象，传入 用户函数对象 和 用户参数
binder2nd 类用 用户函数对象 和 用户参数 初始化
binder2nd 类重载()，
传入 用户函数对象 和 用户参数，
调用 用户函数对象，
用户函数对象 里传入参数 容器中的参数 和 用户参数
*/


//==============三元基类==============//
//书写顺序2->3 三元基类。。。定义这个是为了规范参数的类型，并让其他类和函数可以直接从这里获得所需的类型
template<typename T1, typename T2, typename T3, typename R>
//		容器参数1	  自定参数2	   自定参数3	   自定重载()函数返回值
class ternary_function
{
public:
	//为了使类型 T1 T2 T3被子类使用，需要明确声明一下这些类型的存在，否则这些类型无法被继承
	typedef T1 T1;
	typedef T2 T2;
	typedef T3 T3;
	typedef R R;
};

//==============自定义函数对象类==============//
//书写顺序1->2
class mybind : public ternary_function<int, int, int, int>
{
public:
	int  operator()(int a, int b, int c)
	{
		cout << a << " " << b << " " << c << " " << a + b + c <<endl;
		return a + b + c;
	}
};

//==============类 binder3rd==============//
//书写顺序4->5	定义 binder3rd 类，提供 函数对象 给 bind3rd 函数调用
//FUN_TYPE里面包含了各个参数的类型
template<typename FUN_TYPE>
class binder3rd
{
public:
	//binder3rd 类内接收函数对象和需要绑定的两个参数
	//为了保证安全性，并校验参数类型，从自定义函数对象的基类获取类型
	FUN_TYPE op;
	typename FUN_TYPE::T2 pa2;
	typename FUN_TYPE::T3 pa3;

public:
	//初始化
	binder3rd(FUN_TYPE fun, typename FUN_TYPE::T2 para2, typename FUN_TYPE::T3 para3)
		:op(fun), pa2(para2), pa3(para3){}

	//直接从FUN_TYPE::里面获得所需的参数类型，而不需要像源码一样重新定义一个binary_function，再去拿类型
	typename FUN_TYPE::R operator()(typename FUN_TYPE::T1 pa1)
	{
		//operator()函数可以不需要返回值，因为没有变量去接收
		//所以可以去掉 return， 将 typename FUN_TYPE::R 改成 void
		return op(pa1, pa2, pa3);
	}
};

//==============函数 bind3rd==============//
//书写顺序1->4	需要实现bind3rd这个函数，要求返回值是个函数对象
//mybind是函数对象，他的类型 FUN_TYPE 是个类，继承于 ternary_function
template<typename FUN_TYPE, typename PARA_TYPE2, typename PARA_TYPE3>
binder3rd<FUN_TYPE> bind3rd(FUN_TYPE fun, PARA_TYPE2 para2, PARA_TYPE3 para3)
{
	//返回一个函数对象，这个函数对象是用 fun ,para2 ,para3 实例化出来的
	//并且这里的 返回值 和 用户函数对象fun 的返回值没有任何关系。。。。。。
	return binder3rd<FUN_TYPE>(fun ,para2 ,para3);
}

//==============测试函数==============//
//书写顺序1
void test()
{
	vector<int> v = { 1,2,3,4,5 };
	for_each(v.begin(), v.end(), bind3rd(mybind(), 30, 20));
	//for_each返回值是个函数对象

}

//==============主函数==============//
int main(void)
{
	test();

	return 0;
}