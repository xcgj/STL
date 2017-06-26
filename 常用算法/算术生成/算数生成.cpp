#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include <deque>
#include <functional>
//#include <algorithm>
#include <numeric>
#include <algorithm>

//accumulate(iterator beg, iterator end, value)
//fill(iterator beg, iterator end, value)

//==============������==============//
#include <string>
class Person
{
	friend int operator+(int a, Person p);
	friend class mycalc;
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

	//����=
	//for (; _First != _Last; ++_First) *_First = _Val;
	void operator=(int a)
	{
		this->age = a;
	}

	void operator=(string s)
	{
		this->name = s;
	}
};

//==============���ߺ�������==============//
//����+������Դ���֪���ص��ǲ���3���������ڵڶ�����
//for (; _First != _Last; ++_First) _Val = _Func(_Val, *_First); return (_Val);
int operator+(int a, Person p)
{
	return p.age + a;
}

class mycalc
{
public:
	//�����ϸ���Դ��˳��ƥ�䣬��һ��һ���ǲ���3������
	/*int & operator()(int & a, Person p)
	{
		a = p.age * a;
		return a;
	}*/

	int operator()(int a, Person p)
	{
		return p.age * a;
	}
};

//��ͨ������ӡ
void Print(int a, Person p)
{
	p = a + p;
	p.PrintInfomation();
}

//==============���Ժ���==============//
void test()
{
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	/*
	�������������㷨

	accumulate�㷨 ��������Ԫ���ۼ��ܺ�
	@param beg ������ʼ������
	@param end ��������������
	@param value�ۼ�ֵ
	@return ����value
	accumulate(iterator beg, iterator end, value)

	_Ty _Accumulate_unchecked(_InIt _First, _InIt _Last, _Ty _Val, _Fn2& _Func)
	{	// return sum of _Val and all in [_First, _Last), using _Func
	for (; _First != _Last; ++_First)
	_Val = _Func(_Val, *_First);
	return (_Val);
	}
	_Func��Ĭ����plus<>()



	fill�㷨 �����������Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param value t���Ԫ��
	@return ����void
	fill(iterator beg, iterator end, value)

	void _Fill_unchecked1(_FwdIt _First, _FwdIt _Last, const _Ty& _Val, false_type)
	{	// copy _Val through [_First, _Last), no special optimization
	for (; _First != _Last; ++_First)
	*_First = _Val;
	}
	//��Ҫ����=
	*/
	deque<Person> q1 = { p1, p2, p4, p5, p3 };
	deque<Person> q2;
	q2 = q1;
	cout << "================accumulate================" << endl;
	//������ͷ�ļ�<numeric>��
	//ʹ��Ĭ��plus<>()��������
	int sum = accumulate(q1.begin(), q1.end(), 0);
	cout << "sum = " << sum << endl;
	//ʹ���Զ��庯������
	int multi = accumulate(q1.begin(), q1.end(), 1, mycalc());
	cout << "multi = " << multi << endl;

	cout << "================fill================" << endl;
	cout << "������================" << endl;
	fill(q1.begin(), q1.end(), 35);//��Ҫ����=
	//��ͨ������������ӡ
	//����ptr_funת�ɺ�������
	//�ٰ�
	for_each(q1.begin(), q1.end(), bind1st(ptr_fun(Print), 10));
	cout << "������================" << endl;
	fill(q1.begin(), q1.end(), string("zzz")); //��Ҫ���� =,����Personȫ���滻������Ϊ0
	//��Ա������ӡ
	for_each(q1.begin(), q1.end(), mem_fun_ref(&Person::PrintInfomation));
}

//==============������==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
