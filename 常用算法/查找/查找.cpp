#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <numeric>
using namespace std;

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

	//����==
	bool operator==(Person &  p)
	{
		return this->name == p.name && this->age == p.age;
	}

	//����<
	bool operator<(Person & p)
	{
		return this->age < p.age;
	}
};

//==============����==============//
//������������
class Print
{
public:
	void operator()(pair<int, Person> p)
	{
		p.second.PrintInfomation();
	}
};

//��ͨ����
void print(pair<int, Person> p)
{
	p.second.PrintInfomation();
}

//����==
bool operator==(pair<int, Person> a, int b)
{
	return a.first == b;
}

//�ȽϺ�������
class BigThan : public binary_function<pair<int, Person>, int, bool>
{
public:
	bool operator()(pair<int, Person> a, int b)const
	{
		return a.first >= b;
	}
};

class adjacentfind
{
public:
	bool operator()(pair<int, Person> a, pair<int, Person> b)
	{
		return a.first == b.first && a.second == b.second;
	}
};

//binary_search ==
//class binarysearch : public binary_function<pair<int, Person>, int, bool>
//{
//public:
//	bool operator()(pair<int, Person> a, int b)const
//	{
//		return a.first == b;
//	}
//};

//binary_search����<
//class bless
//{
//public:
//	bool operator()(pair<int, Person> a, int b)const
//	{
//		return a.first < b;
//	}
//};
//
//bool operator<(const pair<int, Person> a, const int b)
//{
//	return a.first < b;
//}
//
//class bser
//{
//public:
//	bool operator()(pair<int, Person> a, pair<int, Person> b)
//	{
//		return a.first < b.first;
//	}
//};

//��������pair<int, Person>�����<�ţ��ɰ�����ֵ����ֵƥ�䣬�Լ�Ϊ��
bool operator<(pair<int, Person> a, pair<int, Person> b)
{
	return a.second < b.second;
}

class myless
{
public:
	bool operator()(pair<int, Person> a, pair<int, Person> b)
	{
		return a.first < b.first;
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
	���ò����㷨

	find�㷨 ����Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param value ���ҵ�Ԫ��
	@return ���ز���Ԫ�ص�λ��
	find(iterator beg, iterator end, value)

	adjacent_find�㷨 ���������ظ�Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param  _callback �ص���������ν��(����bool���͵ĺ�������)
	@return ��������Ԫ�صĵ�һ��λ�õĵ�����
	adjacent_find(iterator beg, iterator end, _callback);

	binary_search�㷨 ���ֲ��ҷ�
	ע��: �����������в�����
	@param beg ������ʼ������
	@param end ��������������
	@param value ���ҵ�Ԫ��
	@return bool ���ҷ���true ����false
	bool binary_search(iterator beg, iterator end, value);

	find_if�㷨 ��������
	@param beg ������ʼ������
	@param end ��������������
	@param  callback �ص���������ν��(����bool���͵ĺ�������)
	@return bool ���ҷ���true ����false
	bool find_if(iterator beg, iterator end, _callback);

	count�㷨 ͳ��Ԫ�س��ִ���
	@param beg ������ʼ������
	@param end ��������������
	@param  value�ص���������ν��(����bool���͵ĺ�������)
	@return int����Ԫ�ظ���
	size_t count(iterator beg, iterator end, value);

	count_if�㷨 ͳ��Ԫ�س��ִ���
	@param beg ������ʼ������
	@param end ��������������
	@param  callback �ص���������ν��(����bool���͵ĺ�������)
	@return int����Ԫ�ظ���
	size_t count_if(iterator beg, iterator end, _callback);
	*/
	//multimap<int, Person, not2(less<int>)> m;//less<int>�����ͣ�not12���ε��Ǻ�������ķ���ֵ
	multimap<int, Person, less<int>> m;
	m.insert(pair<int, Person>(1, Person("aaa", 10)));
	m.insert(make_pair(2, Person("bbb", 20)));
	m.insert(map<int, Person>::value_type(3, Person("ccc", 30)));
	m.insert(pair<int, Person>(1, Person("aaa", 10)));
	//m[4] = Person("ddd", 40);	multimap����ʹ��[]�����������ԣ����޸Ļ�������

	//�������󡢺���ָ�롢lambda���ʽ����Ա��������ͨ����
	//for_each(m.begin(), m.end(), mem_fun_ref(&Person::PrintInfomation));����ת��ʧ��
	cout << "================��ͨ���� ����================" << endl;
	for_each(m.begin(), m.end(), ptr_fun(print));
	cout << "================find================" << endl;

	multimap<int, Person>::iterator it;
	it = find(m.begin(), m.end(), 2);//find����m.find���������ͣ���Ҫ����==
	it->second.PrintInfomation();

	cout << "================find_if================" << endl;
	it = find_if(m.begin(), m.end(), bind2nd(BigThan(), 2));
	it->second.PrintInfomation();

	cout << "================adjacent_find================" << endl;
	it = adjacent_find(m.begin(), m.end(), adjacentfind());//����Ͷ���ıȽ�
	it->second.PrintInfomation();

	cout << "================binary_search================" << endl;
	//bool bs = binary_search(m.begin(), m.end(), bind2nd(binarysearch(), 2)/*, bless()*/);//����
	//binary_searchÿ�ζ��ǽ���ֵ�������ó����Ƚϣ����
	//������ �� �������ķ���ֵ ��Ҫ��pair<int, Person>
	//��������Ҫ��pair<int, Person>���ͱȽϣ���������pair<int, Person>�����<��
	//bool bs = binary_search(m.begin(), m.end(), pair<int, Person>(0, Person("aaa", 20))/*, less<pair<int, Person>>()*/);//��ȷ
	bool bs = binary_search(m.begin(), m.end(), pair<int, Person>(2, Person())/*, myless()*/);//��ȷ
	//bool bs = binary_search(m.begin(), m.end(), Person(), myless());//����
	cout << bs << endl;

	cout << "================count================" << endl;
	int cnt = count(m.begin(), m.end(), 1);
	cout << "cnt = " << cnt << endl;

	cout << "================count_if================" << endl;
	cnt = count_if(m.begin(), m.end(), bind2nd(BigThan(), 1));
	cout << "cnt = " << cnt << endl;
}

//==============������==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
