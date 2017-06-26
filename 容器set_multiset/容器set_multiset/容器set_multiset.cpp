#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <set>

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

	void PrintInfomation()const
	{
		std::cout << "name = " << name << ", age = " << age << endl;
	}

	Person & operator=(const Person & obj)
	{
		this->name = obj.name;
		this->age = obj.age;
	}

	bool operator<(const Person & obj) const
	{
		return this->age < obj.age;
	}

	bool operator>(const Person & obj) const
	{
		return this->age > obj.age;
	}

	bool operator==(const Person & obj) const
	{
		return (this->age == obj.age) && (this->name == obj.name);
	}
};

template<typename T>
class MoreToLess
{
public:
	bool operator()(const T & p1, const T &p2)const //������������()�Ƚϴ�С
	{
		return p1 > p2;
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
	//���� ��ֵ ����
	/*
	set<T> st;//setĬ�Ϲ��캯����
	mulitset<T> mst; //multisetĬ�Ϲ��캯��: 
	set(const set &st);//�������캯��

	set& operator=(const set &st);//���صȺŲ�����
	swap(st);//����������������
	insert(elem);//�������в���Ԫ�ء�,����pair����
	*/
	cout << "========��ʼ�������е�Ĭ�ϲ���========" << endl;
	set<Person> s = {p3, p1, p5, p2, p4};	//Ĭ����������
	for (set<Person>::iterator it = s.begin(); it != s.end(); ++it)
	{
		it->PrintInfomation();
	}
	cout << "========set���뷵��pair����========" << endl;
	set<Person> s1 = s;
	set<Person> s2;
	s2 = s1;
	pair<set<Person>::iterator, bool> pa1 = s2.insert(p3);//����pair
	pa1.first->PrintInfomation();
	cout << pa1.second << endl;
	s2.swap(s1);

	cout << "========�޸�Ĭ�ϲ����ı�����ʽ========" << endl;
	multiset<Person, MoreToLess<Person>> ms = { p3, p1, p5, p2, p2, p4, p3 };	//ָ���������У�����ʹ�ú�������
	for (set<Person>::iterator it = ms.begin(); it != ms.end(); ++it)
	{
		it->PrintInfomation();
	}
	cout << "========multiset���뷵�ص���������========" << endl;
	multiset<Person> s3;
	s3.insert(p2);
	multiset<Person>::iterator pa2 = s3.insert(p2);//���ص�����
	pa2->PrintInfomation();

	//��С  ����
	/*
	size();//����������Ԫ�ص���Ŀ
	empty();//�ж������Ƿ�Ϊ��
	find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
	count(key);//���Ҽ�key��Ԫ�ظ���
	lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
	upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
	equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
	*/
	cout << "s1�Ĵ�С = " << s1.size() << endl;
	cout << "s1Ϊ�գ��� " << s1.empty() << endl;

	cout << "========find����========" << endl;
	multiset<Person>::iterator msi = find(ms.begin(),ms.end(), Person("ddd", 40));
	if (msi == ms.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		msi->PrintInfomation();
	}

	int n = s.count(Person("ddd", 40));
	cout << "n = " << n << endl;

	cout << "========����========" << endl;
	for (multiset<Person>::iterator i = ms.begin(); i != ms.end(); ++i)
	{
		i->PrintInfomation();
	}

	cout << "========lower_bound����========" << endl;
	multiset<Person>::iterator msi2 = ms.lower_bound(Person("ddd", 40));
	//auto msi2 = ms.lower_bound(Person("ddd", 40));
	msi2->PrintInfomation();

	cout << "========upper_bound����========" << endl;
	set<Person>::iterator sit = s.upper_bound(Person("ddd", 40));
	sit->PrintInfomation();

	cout << "========ms.equal_range����========" << endl;
	pair<multiset<Person>::iterator, multiset<Person>::iterator> pai1 = ms.equal_range(Person("ddd", 45));
	pai1.first->PrintInfomation();
	pai1.second->PrintInfomation();

	//ɾ��
	/*
	clear();//�������Ԫ��
	erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
	erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
	erase(elem);//ɾ��������ֵΪelem��Ԫ�ء�
	*/
	cout << "========����s����========" << endl;
	for (set<Person>::iterator i = s.begin(); i != s.end(); ++i)
	{
		i->PrintInfomation();//12345
	}

	set<Person>::iterator delsi = s.begin();
	delsi++;
	delsi = s.erase(delsi);
	cout << "========delsi��λ��========" << endl;
	delsi->PrintInfomation();//3

	cout << "========����ms����========" << endl;
	for (auto i : ms)
	{
		i.PrintInfomation();//5433221
	}

	auto delmsi = ms.begin();//5
	delmsi++;//4
	delmsi++;//3
	delmsi++;//3
	delmsi = ms.erase(++ms.begin(), ++delmsi);//5221
	cout << "========delmsi��λ��========" << endl;
	delmsi->PrintInfomation();//2
	ms.erase(Person("bbb", 20));//51
	cout << "========����ms����========" << endl;
	for (multiset<Person>::iterator i = ms.begin(); i != ms.end(); ++i)
	{
		i->PrintInfomation();//51
	}
	ms.clear();
}

//==============������==============//
int main(void)
{
	test();
	cout << endl << "Compelete" << endl;
	return 0;
}
