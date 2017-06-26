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

	//��<
	bool operator<(Person p)const
	{
		return this->age < p.age;
	}

	//��>
	bool operator>(Person p) const
	{
		return this->age > p.age;
	}

	bool operator>(int a)
	{
		return this->age > a;
	}

	//����==
	bool operator==(Person p)
	{
		return this->age == p.age && this->name == p.name;
	}

	//����+=
	Person & operator+= (int a)
	{
		this->age += a;
		return *this;
	}
};

//==============���ߺ�������==============//
//��ͨ������ӡ
void normalPrint(Person p)
{
	p.PrintInfomation();
}
//����������ͨ����
void normalPrintAdp(Person p, int a)
{
	p += 5;	//����+=
	p.PrintInfomation();
}
//���������ӡ
class cPrint
{
public:
	void operator()(Person & p)
	{
		p.PrintInfomation();
	}
};
//���������滻�������������滻
class replaceIf : public binary_function<Person, int, bool>
{
public:
	bool operator()(Person p, int a)const
	{
		return p > a;
	}
};
//==============���Ժ���==============//
void test()
{
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	/*
	���ÿ������滻�㷨

	copy�㷨 ��������ָ����Χ��Ԫ�ؿ�������һ������
	@param beg ������ʼ������
	@param end ��������������
	@param dest Ŀ����������������
	@return ����Ŀ�������ĵ�����
	copy(iterator beg, iterator end, iterator dest)

	replace�㷨 ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param oldvalue ��Ԫ��
	@param newvalue ��Ԫ��
	@return ����void
	replace(iterator beg, iterator end, oldvalue, newvalue)

	replace_if�㷨 ��������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param callback�����ص�����ν��(����Bool���͵ĺ�������)
	@param newvalue ��Ԫ��
	@return ����void
	replace_if(iterator beg, iterator end, _callback, newvalue)

	swap�㷨 ��������������Ԫ��
	@param c1����1
	@param c2����2
	@return ����void
	swap(container c1, container c2)
	*/
	list<Person> lis1 = { p1, p3, p5, p4, p2 };

	cout << "lambda ��ӡ================" << endl;
	for_each(lis1.begin(), lis1.end(), [](Person p)
	{
		p.PrintInfomation();
	});

	list<Person> lis2 = lis1;
	//list ������
	//lis2.sort();
	//lis2.sort(not2(greater<Person>()));
	lis2.sort(not2(less<Person>()));//��Ҫ���رȽϷ���
	cout << "��ͨ������ӡ================" << endl;
	for_each(lis2.begin(), lis2.end(), normalPrint);

	//�����鿴����ֵ�ĵ�����
	list<Person>::iterator it;
	cout << "================copy================" << endl;
	it = copy(lis2.begin(), lis2.end(), lis1.begin());
	//it��ֵ
	if (it == lis1.end())
	{
		cout << "it ����Ŀ��������β" << endl;
	}
	//�����������������������������ӡ
	cout << "���������ӡ================" << endl;
	for_each(lis1.begin(), lis1.end(), cPrint());

	cout << "================replace================" << endl;
	replace(lis1.begin(), lis1.end(), p4, p1);//��Ҫ����==��=�����ؿ�ʹ��Ĭ��
	cout << "��Ա������ӡ================" << endl;
	for_each(lis1.begin(), lis1.end(), mem_fun_ref(&Person::PrintInfomation));

	cout << "================replace_if================" << endl;/////////�ѵ�
	//���������30���˶�����p3���ú��������������ķ���
	replace_if(lis1.begin(), lis1.end(), bind2nd(replaceIf(), 30), p3);
	cout << "����������ͨ������ӡ================" << endl;
	//����ptr_funת���ɺ��������ٰ�
	//ptr_fun��һ������ָ��ת��Ϊһ��binary_function�ļ̳���pointer_to_binary_function
	//������ͨ������Ҫ2��������һ�����Ե�������һ�����Զ��壬�����ڴ�ӡ�����ж���
	for_each(lis1.begin(), lis1.end(), bind2nd(ptr_fun(normalPrintAdp), 5));

	cout << "================swap================" << endl;
	swap(lis1, lis2);
	cout << "it��ӡlis2================" << endl;
	for (list<Person>::iterator i = lis2.begin(); i != lis2.end(); ++i)
	{
		i->PrintInfomation();
	}
	cout << "auto��ӡlis1================" << endl;
	for (auto i : lis1)
	{
		i.PrintInfomation();
	}
}

//==============������==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
