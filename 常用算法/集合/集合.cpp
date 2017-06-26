#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
//set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
//set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

#include <deque>
//#include <stack>
#include <algorithm>
//#include <set>
#include <vector>
#include <functional>

//==============������==============//
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

	//����<
	bool operator<(const Person & p) const
	{
		return this->age < p.age && this->name < p.name;
	}

	//����>
	bool operator>(const Person & p) const
	{
		return this->age > p.age && this->name > p.name;
	}

	////����=
	//void operator=(/*multiset<Person> & s, */const Person & p)
	//{
	//	this->name = p.name;
	//	this->age = p.age;
	//}
};

//==============���ߺ�������==============//
//����=
//void dTos(multiset<Person> & s, const Person & p)
//{
//	s.insert(p);
//}

//��������
class vprint
{
public:
	void operator()(Person p)
	{
		p.PrintInfomation();
	}
};

//�ص�����
void print(Person p)
{
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
	���ü����㷨

	set_intersection�㷨 ������set���ϵĽ���
	ע��:�������ϱ�������������
	@param beg1 ����1��ʼ������
	@param end1 ����1����������
	@param beg2 ����2��ʼ������
	@param end2 ����2����������
	@param dest  Ŀ��������ʼ������
	@return Ŀ�����������һ��Ԫ�صĵ�������ַ
	set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
		return (_STD set_intersection(_First1, _Last1, _First2, _Last2, _Dest, less<>()));////////////////
		_OutIt _Set_intersection_no_deprecate1(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest, _Pr& _Pred)
		{	// AND sets [_First1, _Last1) and [_First2, _Last2), using _Pred, no deprecation warnings
			for (; _First1 != _Last1 && _First2 != _Last2; )
				if (_DEBUG_LT_PRED(_Pred, *_First1, *_First2))
					++_First1;
				else if (_Pred(*_First2, *_First1))
					++_First2;
				else
					{
					*_Dest++ = *_First1++;	////////////////////
					++_First2;
					}

			return (_Dest);
		}

	set_union�㷨 ������set���ϵĲ���
	ע��:�������ϱ�������������
	@param beg1 ����1��ʼ������
	@param end1 ����1����������
	@param beg2 ����2��ʼ������
	@param end2 ����2����������
	@param dest  Ŀ��������ʼ������
	@return Ŀ�����������һ��Ԫ�صĵ�������ַ
	set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

	set_difference�㷨 ������set���ϵĲ
	ע��:�������ϱ�������������
	@param beg1 ����1��ʼ������
	@param end1 ����1����������
	@param beg2 ����2��ʼ������
	@param end2 ����2����������
	@param dest  Ŀ��������ʼ������
	@return Ŀ�����������һ��Ԫ�صĵ�������ַ
	set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
	*/

	//stack<Person> s1 = { p2, p5, p1 };//����
	/*stack<Person> s1, s2;
	s1.push(p2);
	s1.push(p5);
	s1.push(p1);

	s2.push(p1);
	s2.push(p4);
	s2.push(p3);*/
	//����ջ���ܱ���

	deque<Person> d1 = { p2, p5, p1 };
	deque<Person> d2 = { p1, p4, p3, p5 };
	//multiset<Person> s;//����setԪ�ز����޸ģ����ò���
	vector<Person> v;
	vector<Person>::iterator it;

	//����Ҫ������
	sort(d1.begin(), d1.end(), greater<Person>());
	sort(d2.begin(), d2.end(), greater<Person>());

	cout << "================set_intersection ����================" << endl;
	//����Դ�룬����< =
	//set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), s.begin());
	v.resize(min(d1.size(), d2.size()));//ȡ��Сֵ
	cout << v.size() << endl;
	//���ϲ��ҵ�˳��Ҫ������˳����ͬ
	it = set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), v.begin(), greater<Person>());
	if (it == v.begin() + 2)
	{
		cout << "������ָ�� ���һ�� Ԫ�� ���� ��λ��" << endl;
	}
	for_each(v.begin(), it, [](Person p)	//����λ���� it
	{
		p.PrintInfomation();
	});

	cout << "================set_union ����================" << endl;
	v.clear();
	v.resize(d1.size() + d2.size());
	//it = set_union(d1.begin(), d1.end(), d2.begin(), d2.end(), v.begin(), not2(less<Person>()));//�Ƚϲ��ɹ�����>=�ˣ�greater<Person>()��<
	it = set_union(d1.begin(), d1.end(), d2.begin(), d2.end(), v.begin(), greater<Person>());
	if (it == v.begin() + 5)
	{
		cout << "������ָ�� ���һ�� Ԫ�� ���� ��λ��" << endl;
	}
	for_each(v.begin(), it, vprint());

	cout << "================set_difference �================" << endl;
	v.clear();
	v.resize(max(d1.size(), d2.size()));
	cout << "d1�����d2 �Ĳ================" << endl;
	it = set_difference(d1.begin(), d1.end(), d2.begin(), d2.end(), v.begin(), greater<Person>());
	for_each(v.begin(), it, print);

	cout << "d2�����d1 �Ĳ================" << endl;
	it = set_difference(d2.begin(), d2.end(), d1.begin(), d1.end(), v.begin(), greater<Person>());
	for_each(v.begin(), it, mem_fun_ref(&Person::PrintInfomation));
}

//==============������==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
