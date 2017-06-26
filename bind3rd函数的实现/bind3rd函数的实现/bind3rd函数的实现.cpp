#include <iostream>
//#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

//ʵ��ԭ��
/*
�� �û��������� �� �û����� ���� bind2nd �������û������� �Դ��������еĲ���
bind2nd���� ������ binder2nd �������󣬴��� �û��������� �� �û�����
binder2nd ���� �û��������� �� �û����� ��ʼ��
binder2nd ������()��
���� �û��������� �� �û�������
���� �û���������
�û��������� �ﴫ����� �����еĲ��� �� �û�����
*/


//==============��Ԫ����==============//
//��д˳��2->3 ��Ԫ���ࡣ�������������Ϊ�˹淶���������ͣ�����������ͺ�������ֱ�Ӵ����������������
template<typename T1, typename T2, typename T3, typename R>
//		��������1	  �Զ�����2	   �Զ�����3	   �Զ�����()��������ֵ
class ternary_function
{
public:
	//Ϊ��ʹ���� T1 T2 T3������ʹ�ã���Ҫ��ȷ����һ����Щ���͵Ĵ��ڣ�������Щ�����޷����̳�
	typedef T1 T1;
	typedef T2 T2;
	typedef T3 T3;
	typedef R R;
};

//==============�Զ��庯��������==============//
//��д˳��1->2
class mybind : public ternary_function<int, int, int, int>
{
public:
	int  operator()(int a, int b, int c)
	{
		cout << a << " " << b << " " << c << " " << a + b + c <<endl;
		return a + b + c;
	}
};

//==============�� binder3rd==============//
//��д˳��4->5	���� binder3rd �࣬�ṩ �������� �� bind3rd ��������
//FUN_TYPE��������˸�������������
template<typename FUN_TYPE>
class binder3rd
{
public:
	//binder3rd ���ڽ��պ����������Ҫ�󶨵���������
	//Ϊ�˱�֤��ȫ�ԣ���У��������ͣ����Զ��庯������Ļ����ȡ����
	FUN_TYPE op;
	typename FUN_TYPE::T2 pa2;
	typename FUN_TYPE::T3 pa3;

public:
	//��ʼ��
	binder3rd(FUN_TYPE fun, typename FUN_TYPE::T2 para2, typename FUN_TYPE::T3 para3)
		:op(fun), pa2(para2), pa3(para3){}

	//ֱ�Ӵ�FUN_TYPE::����������Ĳ������ͣ�������Ҫ��Դ��һ�����¶���һ��binary_function����ȥ������
	typename FUN_TYPE::R operator()(typename FUN_TYPE::T1 pa1)
	{
		//operator()�������Բ���Ҫ����ֵ����Ϊû�б���ȥ����
		//���Կ���ȥ�� return�� �� typename FUN_TYPE::R �ĳ� void
		return op(pa1, pa2, pa3);
	}
};

//==============���� bind3rd==============//
//��д˳��1->4	��Ҫʵ��bind3rd���������Ҫ�󷵻�ֵ�Ǹ���������
//mybind�Ǻ��������������� FUN_TYPE �Ǹ��࣬�̳��� ternary_function
template<typename FUN_TYPE, typename PARA_TYPE2, typename PARA_TYPE3>
binder3rd<FUN_TYPE> bind3rd(FUN_TYPE fun, PARA_TYPE2 para2, PARA_TYPE3 para3)
{
	//����һ������������������������� fun ,para2 ,para3 ʵ����������
	//��������� ����ֵ �� �û���������fun �ķ���ֵû���κι�ϵ������������
	return binder3rd<FUN_TYPE>(fun ,para2 ,para3);
}

//==============���Ժ���==============//
//��д˳��1
void test()
{
	vector<int> v = { 1,2,3,4,5 };
	for_each(v.begin(), v.end(), bind3rd(mybind(), 30, 20));
	//for_each����ֵ�Ǹ���������

}

//==============������==============//
int main(void)
{
	test();

	return 0;
}