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

//ʵ��ԭ��
/*
�� �û��������� �� �û����� ���� bind2nd ���������û������� �Դ��������еĲ�����
bind2nd���� ������ binder2nd �������󣬴��� �û��������� �� �û�����
binder2nd ���� �û��������� �� �û����� ��ʼ��
binder2nd ������()��
	���� �û��������� �� �û�������
	���� �û���������
		�û��������� �ﴫ����� �����еĲ��� �� �û�����
*/

#if 0
//���� binary_function ��Դ��
// TEMPLATE STRUCT binary_function
template<class _Arg1, class _Arg2, class _Result>
struct binary_function
{	
	//������ ����1 ������
	typedef _Arg1	first_argument_type;
	//������ ����2 ������
	typedef _Arg2	second_argument_type;
	//������ ����ֵ ������
	typedef _Result	result_type;
};

//����һԪ unary_function ��Դ��
template<class _Arg, class _Result>
struct unary_function
{	
	//������ ���� ������
	typedef _Arg	argument_type;
	//������ ����ֵ ������
	typedef _Result result_type;
};

#endif

#if 0

//Դ�룺

template<class _Fn2, class _Ty> 
//bind2nd ��һ��ģ�庯��������ֵ�� result_type���� �û��������� �ķ���ֵ
inline binder2nd<_Fn2> bind2nd(const _Fn2& _Func, const _Ty& _Right)
{	
	//�û���� ����2 ���ͳ�ʼ��һ����������������������ֵ�� ����Ĳ���2
	typename _Fn2::second_argument_type _Val(_Right);
	//���ú�������binder2nd()����<����1������>ʵ����������ֵ�� ʵ�����Ķ���
	return (binder2nd<_Fn2>(_Func, _Val));
}

//binder2nd ���Դ��
template<class _Fn2>
class binder2nd : public unary_function<typename _Fn2::first_argument_type, typename _Fn2::result_type>
//												���� ������������ �� ����1 ����		���뺯���������͵� ����ֵ ����
{	// functor adapter _Func(left, stored)
protected:
	//���������û��Զ���ĺ�������
	_Fn2 op;	// the functor to apply
	//���������û������ ��Ҫ�� �Ĳ���
	typename _Fn2::second_argument_type value;	// the right operand

public:
	//���������� unary_function ��������������Ϊ����()�����ṩ���ͣ���Щ����Ҳ����ֱ�Ӵ�_Fn2::������
	typedef unary_function<typename _Fn2::first_argument_type, typename _Fn2::result_type>	_Base;
	//���������� unary_function �е� ���� ����������ʵ���Ǵ���� ������������ �� ����1
	typedef typename _Base::argument_type		argument_type;
	//���������� unary_function �е� ����ֵ ����������ʵ���Ǵ���� ������������ �� ����ֵ
	typedef typename _Base::result_type			result_type;

	//binder2nd �Ĺ��캯�� �Լ�  ��ʼ���б�
	//�����û��ĺ������� �� ��Ҫ�󶨵Ĳ�����ֵ��
	//value(_Right)�ǲ����ĸ���������ֵ��ԭ����һ��
	binder2nd(const _Fn2& _Func, const typename _Fn2::second_argument_type& _Right) : op(_Func), value(_Right)
	{	// construct from functor and right operand
	}

	//�����������洫��Ĳ�����Ȼ����� op �������󣬽����������Ͱ󶨲���һ�𴫽�ȥ
	//�� �������� �� ����ֵ �𼶷���
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