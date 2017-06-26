#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

//==============�û��Զ���������==============//
class Person
{
public:
	int age;
	string name;
public:
	Person(int a, string n)
	{
		age = a;
		name = n;
	}
};

void APItest()
{
	Person p1(10, "aa");
	Person p2(20, "bb");
	Person p3(30, "cc");
	Person p4(40, "dd");
	Person p5(50, "ee");
//==============���캯��==============//
	/*
	vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
	vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
	vector(n, elem);//���캯����n��elem����������
	vector(const vector &vec);//�������캯����
	*/
	vector<Person> v1(5, Person(10, "dd"));
	vector<Person> v2 = v1;
	vector<Person> v3(v2);
	vector<Person> v4(v3.begin() + 1, v3.end() - 1);
	vector<Person> v5;
	cout << "���캯��v3" << endl;
	for (auto val : v3)
	//for (vector<Person>::iterator val : v3)
	{
		cout << val.name << " " << val.age << endl;
	}
	cout << "���캯��v4" << endl;
	for(vector<Person>::iterator it = v4.begin(); it != v4.end(); ++it)
	{
		cout << it->name << " " << (*it).age << endl;
	}

//==============����ɾ��==============//
	/*
	insert(const_iterator pos, int count,ele);//������ָ��λ��pos����count��Ԫ��ele.
	push_back(ele); //β������Ԫ��ele
	pop_back();//ɾ�����һ��Ԫ��
	erase(const_iterator start, const_iterator end);//ɾ����������start��end֮���Ԫ��
	erase(const_iterator pos);//ɾ��������ָ���Ԫ��
	clear();//ɾ������������Ԫ��
	*/
	v1.clear();
	vector<Person*> v;
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.insert(v.begin() + 1, 1, &p4);
	v.insert(v.begin() + 1, 1, &p5);
	cout << "����" << endl;
	for (auto val : v)
	{
		cout << val->name << " " << val->age << endl;
	}
	cout << "ɾ��" << endl;
	v.pop_back();
	v.erase(v.begin(), v.begin() + 1);
	v.erase(v.begin() + 2);
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it)->name << " " << (*it)->age << endl;
	}
//==============��ֵ==============//
	/*
	assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
	assign(n, elem);//��n��elem������ֵ������
	vector& operator=(const vector  &vec);//���صȺŲ�����
	swap(vec);// ��vec�뱾���Ԫ�ػ�����
	*/
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);//54123
	vector<Person *> v6, v7, v8, v9;
	v6.assign(v.begin(), v.begin() + 4);//5412
	v7.assign(3, *(v6.begin() + 1));//444
	v8 = v7;
	v9.swap(v8);
	cout << "v6��ֵ" << endl;
	for (auto val : v6)
	//for (vector<Person*> val : &v6)
	{
		cout << (*val).age << " " << val->name << endl;
	}
	cout << "v9��ֵ" << endl;
	for (vector<Person*>::iterator it = v9.begin(); it != v9.end(); ++it)
	{
		cout << (*it)->name << " " << (*it)->age << endl;
	}
//==============��С==============//
	/*
	size();//����������Ԫ�صĸ���
	empty();//�ж������Ƿ�Ϊ��
	resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ����������>�ȵ�Ԫ�ر�ɾ����
	capacity();//����������
	reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
	*/
	v.size();
	v.empty();
	v.resize(8);
	v.resize(10, &p1);
	v.capacity();
	v.reserve(20);
//==============��ȡ==============//
	/*
	at(int idx); //��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range�쳣��
	operator[];//��������idx��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���
	front();//���������е�һ������Ԫ��
	back();//�������������һ������Ԫ��
	*/
	v.at(3);
	v[2];
	v.front();
	v.back();
}

//==============�����ռ�==============/
void shrink()
{
	vector<int> v;
	v.resize(1000);	//v.capacity() 1000;	v.size()1000
	v.resize(10);	//v.capacity() 1000;	v.size()10
	vector<int>(v).swap(v);//ָ�����������ָ����� �� ָ�� v ��ָ����� ����ָ��ָ������������ָ�������ָ��Ŀռ��ͷ�
	cout << v.size() << v.capacity();//10 10
}

//==============����Ƕ������==============//
void vectorinvector()
{
	//������������
	vector<Person> v1;
	vector<Person> v2;
	vector<Person> v3;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(Person(10 * i + 1, "a"));
		v2.push_back(Person(10 * i + 2, "b"));
		v3.push_back(Person(10 * i + 3, "c"));
	}
	//����������������
	vector< vector<Person> > v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	//��������
	for (vector< vector<Person> >::iterator it = v.begin(); it != v.end(); ++it)
	{
		for (vector<Person>::iterator i = it->begin(); i != it->end() ; ++i)
		{
			cout << i->name << " " << i->age << endl;
		}
	}
}

//==============������==============//
int main(void)
{
	//APItest();
	//shrink();
	vectorinvector();

	cout << "Compelete" << endl;
	return 0;
}
