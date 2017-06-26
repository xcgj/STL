#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <map>
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

	void PrintInfomation()const//�����const��Ҫ��map��������
	{
		std::cout << "name = " << name << ", age = " << age << endl;
	}
	////���صȺ�
	//Person & operator= (Person & p)
	//{
	//	this->name = p.name;
	//	this->age = p.age;
	//	return *this;
	//}
	//����<��
	bool operator<(const Person & p)const
	{
		return this->age < p.age;
	}
	//����>��
	bool operator>(const Person & p)
	{
		return this->age > p.age;
	}
};

template<typename T>
class MoreToLess
{
public:
	bool operator()(T p1, T p2)
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

	cout << "==========���죬��ֵ������==========" << endl;
	/*
	map<T1, T2> mapTT;//mapĬ�Ϲ��캯��: 
	map(const map &mp);//�������캯��

	map& operator=(const map &mp);//���صȺŲ�����
	swap(mp);//����������������

	map.insert(...); //����������Ԫ�أ�����pair<iterator,bool>
	map<int, string> mapStu;
	// ��һ�� ͨ��pair�ķ�ʽ�������
	mapStu.insert(pair<int, string>(3, "С��"));
	// �ڶ��� ͨ��pair�ķ�ʽ�������
	mapStu.inset(make_pair(-1, "У��"));
	// ������ ͨ��value_type�ķ�ʽ�������
	mapStu.insert(map<int, string>::value_type(1, "С��"));
	// ������ ͨ������ķ�ʽ����ֵ
	mapStu[3] = "С��";
	mapStu[5] = "С��";
	*/
	map<Person, int> m, m1;
	pair<map<Person, int>::iterator, bool> gmit;
	//map.insert()��������������pair
	gmit = m.insert(pair<Person, int>(p2, 2));
	m.insert(make_pair(p5, 5));
	m.insert(map<Person, int>::value_type(p1, 1));
	m[p3] = 3; m[p4] = 4;
	cout << "==========gmit������==========" << endl;
	cout << "����״̬��" << gmit.second << ", ���ݣ�";
	cout << gmit.first->second << ", ";
	gmit.first->first.PrintInfomation();

	m1 = m;
	cout << "==========����m1==========" << endl;
	for (map<Person, int>::iterator i = m1.begin(); i!= m1.end(); ++i)
	{
		cout << i->second << ", ";
		i->first.PrintInfomation();
	}

	//���뺯������ı�����˳��
	multimap<int, Person, MoreToLess<int>> mm = { {30, p3}, {20, p2}, {10, p1}, {50, p5}, {40, p4} };
	multimap<int, Person>::iterator gmmit;
	mm.insert(map<int, Person>::value_type(30, p2));
	//multimap.insert()�����ķ��������ǵ�����

	gmmit = mm.insert(pair<int, Person>(10, p1));
	cout << "==========gmmit������==========" << endl;
	cout << gmmit->first << ", ";
	gmmit->second.PrintInfomation();

	cout << "==========����mm1==========" << endl;
	multimap<int, Person, MoreToLess<int>> mm1 = mm;//���뺯������ı�����˳��
	for (auto val : mm1)
	{
		cout << val.first << ", ";
		val.second.PrintInfomation();
	}
	cout << "==========���ң���С��ɾ��==========" << endl;
	/*
	find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�������/�������ڣ�����map.end();
	count(keyElem);//����������keyΪkeyElem�Ķ����������map��˵��Ҫô��0��Ҫô��1����multimap��˵��ֵ���ܴ���1��
	lower_bound(keyElem);//���ص�һ��key<=keyElemԪ�صĵ�������
	upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
	equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������

	size();//����������Ԫ�ص���Ŀ
	empty();//�ж������Ƿ�Ϊ��

	clear();//ɾ������Ԫ��
	erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
	erase(beg,end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
	erase(keyElem);//ɾ��������keyΪkeyElem�Ķ��顣
	*/
	cout << "==========finditm==========" << endl;
	map<Person, int>::iterator finditm;
	finditm = m.find(p3);//������ʱ��ֻ��Ҫ����������ô�ֵ
	if (finditm == m.end())
	{
		cout << "û�������" << endl;
	}
	else
	{
		finditm->first.PrintInfomation();
	}
	cout << "==========count_m==========" << endl;
	cout << m.count(p3) << endl;
	cout << "==========lower_bound_m==========" << endl;
	map<Person, int>::iterator lm;
	lm = m.lower_bound(p4);
	cout << lm->second << ", ";
	lm->first.PrintInfomation();
	cout << "==========upper_bound_m==========" << endl;
	lm = m.upper_bound(p4);
	cout << lm->second << ", ";
	lm->first.PrintInfomation();
	cout << "==========equal_range_m==========" << endl;
	pair<map<Person, int>::iterator, map<Person, int>::iterator> pm;
	pm = m.equal_range(p4);
	cout << pm.first->second << ", ";
	pm.first->first.PrintInfomation();
	cout << pm.second->second << ", ";
	pm.second->first.PrintInfomation();
	cout << "==========size_m==========" << endl;
	cout << m.size() << endl;
	cout << m.empty() << endl;
	cout << "==========erase_m_m.begin()==========" << endl;
	lm = m.erase(m.begin());
	cout << lm->second << ", ";
	lm->first.PrintInfomation();
	cout << "==========erase_m_m.begin(), ++m.begin()==========" << endl;
	lm = m.erase(m.begin(), ++m.begin());
	cout << lm->second << ", ";
	lm->first.PrintInfomation();
	cout << "==========erase_m_p5==========" << endl;
	m.erase(p5);
	for (auto val : m)
	{
		cout << val.second << ", ";
		val.first.PrintInfomation();
	}
}

//==============������==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
