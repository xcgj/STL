#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include <algorithm>
#include <numeric>
#include <functional>

//for_each()
//transform()

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

	//����+
	Person operator+(int val)
	{
		Person temp;
		temp.name = this->name;
		temp.age = this->age + val;
		return temp;
	}
};

//==============����==============//
//�ص�����
bool compare(int a, int b)
{
	return a < b;
}

void print(pair<int, Person> callback)
{
	callback.second.PrintInfomation();
}

Person trans(pair<int, Person> p)//m������Ԫ���Ƕ������͵ģ�v����ֻ��Ҫ����Person���ͣ����ԣ���ȡ�����ٷ������
{
	return p.second + 10;		//����+
}

//��������
template <typename T>
class COMPARE
{
public:
	bool operator()(const T a, const T b)const	//ֻ������
	{
		return a > b;
	}
};

class ERGODIC
{
public:
	void operator()(pair<int, Person> print)
	{
		print.second.PrintInfomation();
	}
};

class TRANS : public binary_function<pair<int, Person>, int, Person>
{
public:
	Person operator()(pair<int, Person> a, int b)const
	{
		return a.second + b;
	}
};
//==============���Ժ���==============//
void test()
{
	//map<int, Person, greater<int>> m;
	//map<int, Person, compare> m;	//����map��Ҫ������������map<int, Person, compare>��һ������
	map<int, Person, COMPARE<int>> m;
	m.insert(pair<int, Person>(1, Person("aaa", 10)));
	m.insert(map<int, Person>::value_type(2, Person("bbb", 20)));
	m.insert(make_pair(3, Person("ccc", 30)));
	m[4] = Person("ddd", 40);

	/*
	���ñ����㷨

	�����㷨 ��������Ԫ��
	@param beg ��ʼ������
	@param end ����������
	@param _callback  �����ص����ߺ�������
	@return ��������
	for_each(iterator beg, iterator end, _callback);

	transform�㷨 ��ָ����������Ԫ�ذ��˵���һ������
	ע�� : transform �����Ŀ�����������ڴ棬������Ҫ������ǰ������ڴ�
	@param beg1 Դ������ʼ������
	@param end1 Դ��������������
	@param beg2 Ŀ��������ʼ������
	@param _cakkback �ص��������ߺ�������
	@return ����Ŀ������������
	transform(iterator beg1, iterator end1, iterator beg2, _callbakc)
	*/
	cout << "=============lambda ���ʽ����==============" << endl;
	for_each(m.begin(), m.end(), [](pair<int, Person> p)
	{
		p.second.PrintInfomation();
	});
	cout << "=============�ص����� ����==============" << endl;
	for_each(m.begin(), m.end(), print);
	cout << "=============�������� ����==============" << endl;
	for_each(m.begin(), m.end(), ERGODIC());
	

	//map<int, Person> m2;
	vector<Person> v;
	v.resize(m.size());
	cout << "=============lambda ���ʽת��==============" << endl;
	transform(m.begin(), m.end(), v.begin(), [](pair<int, Person> p)	//�������ÿ�δ����m�����Ķ���
	{
		return p.second + 20;	//����ֵ�Ƿ���v���������
	});
	for (Person val : v)
	{
		val.PrintInfomation();
	}
	cout << "=============�ص����� ת��==============" << endl;
	transform(m.begin(), m.end(), v.begin(), trans);
	for (Person val : v)
	{
		val.PrintInfomation();
	}
	cout << "=============�������� ת��==============" << endl;
	vector<Person>::iterator vit = transform(m.begin(), m.end(), v.begin(), bind2nd(TRANS(), 5));
	if (vit == v.end())
	{
		cout << "������ָ���λ����v.end()" << endl;
	}
	for (auto val : v)
	{
		val.PrintInfomation();
	}
}

//==============������==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
