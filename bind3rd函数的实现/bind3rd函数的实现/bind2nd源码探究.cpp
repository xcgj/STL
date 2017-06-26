#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

class mybind : public binary_function<int, int, void>
{
public:
	void operator()(int a, int b)const
	{
		cout << a << " " << b << endl;
	}
};

void test1()
{
	vector<int> v = { 1,2,3,4,5 };
	for_each(v.begin(), v.end(), bind2nd(mybind(), 100));
}

int main01(void)
{
	test1();
	return 0;
}

//实现原理
/*
将 用户函数对象 和 用户参数 传入 bind2nd 函数：（用户对象函数 自带了容器中的参数）
bind2nd函数 调用了 binder2nd 函数对象，传入 用户函数对象 和 用户参数
binder2nd 类用 用户函数对象 和 用户参数 初始化
binder2nd 类重载()，
	传入 用户函数对象 和 用户参数，
	调用 用户函数对象，
		用户函数对象 里传入参数 容器中的参数 和 用户参数
*/

#if 0
//基类 binary_function 的源码
// TEMPLATE STRUCT binary_function
template<class _Arg1, class _Arg2, class _Result>
struct binary_function
{	
	//重命名 参数1 的类型
	typedef _Arg1	first_argument_type;
	//重命名 参数2 的类型
	typedef _Arg2	second_argument_type;
	//重命名 返回值 的类型
	typedef _Result	result_type;
};

//基类一元 unary_function 的源码
template<class _Arg, class _Result>
struct unary_function
{	
	//重命名 参数 的类型
	typedef _Arg	argument_type;
	//重命名 返回值 的类型
	typedef _Result result_type;
};

#endif

#if 0

//源码：

template<class _Fn2, class _Ty> 
//bind2nd 是一个模板函数，返回值是 result_type，是 用户函数对象 的返回值
inline binder2nd<_Fn2> bind2nd(const _Fn2& _Func, const _Ty& _Right)
{	
	//用基类的 参数2 类型初始化一个辅助变量，辅助变量的值是 传入的参数2
	typename _Fn2::second_argument_type _Val(_Right);
	//调用函数对象：binder2nd()，用<参数1的类型>实例化，返回值是 实例化的对象
	return (binder2nd<_Fn2>(_Func, _Val));
}

//binder2nd 类的源码
template<class _Fn2>
class binder2nd : public unary_function<typename _Fn2::first_argument_type, typename _Fn2::result_type>
//												传入 函数对象类型 的 参数1 类型		传入函数对象类型的 返回值 类型
{	// functor adapter _Func(left, stored)
protected:
	//用来接收用户自定义的函数对象
	_Fn2 op;	// the functor to apply
	//用来接收用户传入的 需要绑定 的参数
	typename _Fn2::second_argument_type value;	// the right operand

public:
	//将基类类型 unary_function 重命名，作用是为重载()函数提供类型，这些类型也可以直接从_Fn2::里面获得
	typedef unary_function<typename _Fn2::first_argument_type, typename _Fn2::result_type>	_Base;
	//将基类类型 unary_function 中的 参数 重命名，其实就是传入的 函数对象类型 的 参数1
	typedef typename _Base::argument_type		argument_type;
	//将基类类型 unary_function 中的 返回值 重命名，其实就是传入的 函数对象类型 的 返回值
	typedef typename _Base::result_type			result_type;

	//binder2nd 的构造函数 以及  初始化列表，
	//传入用户的函数对象 和 需要绑定的参数的值，
	//value(_Right)是参数的辅助变量，值和原参数一致
	binder2nd(const _Fn2& _Func, const typename _Fn2::second_argument_type& _Right) : op(_Func), value(_Right)
	{	// construct from functor and right operand
	}

	//接收容器里面传入的参数，然后调用 op 函数对象，将容器参数和绑定参数一起传进去
	//将 函数对象 的 返回值 逐级返回
	result_type operator()(const argument_type& _Left) const
	{	// apply functor to operands
		return (op(_Left, value));
	}

	result_type operator()(argument_type& _Left) const
	{	// apply functor to operands
		return (op(_Left, value));
	}
};

#endif