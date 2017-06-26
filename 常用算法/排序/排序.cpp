#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;
#include <vector>
#include <ctime>

//merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
//sort(iterator beg, iterator end, _callback)
//random_shuffle(iterator beg, iterator end)
//reverse(iterator beg, iterator end)

//==============������==============//
#include <string>
class Person
{
private:
	mutable string name;
	mutable int age;
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

	//����>
	bool operator>(const Person & p)const
	{
		return this->age > p.age;//��>�ĳ�>=�ɽ�������������
	}

	//����<
	bool operator<(const Person & p)const
	{
		return this->age <= p.age;
	}
};

//==============�Զ��庯�����ߡ��๤��==============//
class trans
{
public:
	Person operator()(Person p)
	{
		return p;
	}
};

//��ͨ������Ϊ��ӡ����
void npri(Person p)
{
	p.PrintInfomation();
}

//==============���Ժ���==============//
void test()
{
	/*
	���������㷨

	merge�㷨 ����Ԫ�غϲ������洢����һ������
	ע��:�������������������
	@param beg1 ����1��ʼ������
	@param end1 ����1����������
	@param beg2 ����2��ʼ������
	@param end2 ����2����������
	@param dest  Ŀ��������ʼ������
	merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

	sort�㷨 ����Ԫ������
	ֻ��������������ʵ������������������������Ԫ�ص�����ѡ�����򷽷���������ջ���򡢲�������ȣ�
	@param beg ����1��ʼ������
	@param end ����1����������
	@param _callback �ص���������ν��(����bool���͵ĺ�������)
	sort(iterator beg, iterator end, _callback)

	random_shuffle�㷨 ��ָ����Χ�ڵ�Ԫ�������������
	@param beg ������ʼ������
	@param end ��������������
	random_shuffle(iterator beg, iterator end)

	reverse�㷨 ��תָ����Χ��Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	reverse(iterator beg, iterator end)
	*/

	/*
		//��ʼ��
	multiset<Person, greater<Person>> m =	//��Ҫ����<ʹgreater������ȡ�������ͱȽϹ���
	{
		Person("ccc", 30),
		Person("aaa", 10),
		Person("eee", 50),
		Person("bbb", 20),
		Person("ddd", 40)
	};
	//�ٳ�ʼ��һ��
	multiset<Person, greater<Person>> n;	//��������Ҫƥ��
	n.insert(Person("a", 10));
	n.insert(Person("b", 20));
	n.insert(Person("c", 30));
	n.insert(Person("d", 40));
	n.insert(Person("e", 50));

	//transform����Ԫ��
	transform(m.begin(), m.end(), n.begin(), [](Person p)
	{
		return p;
	});
	for_each(n.begin(), n.end(), [](Person p)
	{
		p.PrintInfomation();
	});

	transform(m.begin(), m.end(), n.begin(), trans());
	for_each(n.begin(), n.end(), [](Person p)
	{
		p.PrintInfomation();
	});*/
	//������룬����ԭ��map��set������ֵ�����޸ģ�ֻ��ɾ���Ͳ���

	vector<Person> v1 =	//��Ҫ����<ʹgreater������ȡ�������ͱȽϹ���
	{
		Person("ccc", 30),
		Person("aaa", 10),
		Person("eee", 50),
		Person("bbb", 20),
		Person("ddd", 40)
	};

	vector<Person> v2;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), trans());
	//not2 ������ʹ��
	sort(v1.begin(), v1.end(), not2(less<Person>()));//����
	sort(v2.begin(), v2.end(), greater<Person>());
	cout << "==============v2==============" << endl;
	//lambda���ʽ
	for_each(v2.begin(), v2.end(), [](Person p)
	{
		p.PrintInfomation();
	});

	cout << "==============merge==============" << endl;
	vector<Person> v3;
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), greater<Person>());
	//��Ա������Ϊ��ӡ����
	for_each(v3.begin(), v3.end(), mem_fun_ref(&Person::PrintInfomation));

	cout << "==============sort==============" << endl;
	//��v3����
	//sort(v3.begin(), v3.end(), not2(greater<Person>()));//�˴���not2�����ҵ�
	//sort(v1.begin(), v1.end(), not2(greater<Person>()));//�˴���not2�����ҵ�
	sort(v3.begin(), v3.end(), not2(less<Person>()));
	//��ͨ������Ϊ��ӡ���������ص�����
	for_each(v3.begin(), v3.end(), npri);
	//for_each(v1.begin(), v1.end(), npri);

	cout << "==============random_shuffle==============" << endl;
	//��ֹÿ�β����Ľ��һ��
	srand((unsigned)time(NULL));
	random_shuffle(v3.begin() + 2, v3.end() - 3);
	//auto
	for (auto p : v3)
	{
		p.PrintInfomation();
	}

	cout << "==============reverse==============" << endl;
	reverse(v1.begin(), v1.end());
	//it
	for (vector<Person>::iterator i = v1.begin(); i != v1.end(); ++i)
	{
		i->PrintInfomation();
	}
}

//==============������==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
