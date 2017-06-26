#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <list>

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

	bool operator==(const Person & obj)
	{
		return (this->age == obj.age) && (this->name == obj.name);
	}


	bool operator>(const Person & obj)
	{
		return this->age > obj.age;
	}

	bool operator<(const Person & obj)
	{
		return this->age < obj.age;
	}
};

bool uppertolow(Person & p1, Person & p2)
{
	return p1 > p2;
}

//==============���Ժ���==============//
void test1()
{
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//��ʼ��
	/*
	list<T> lstT;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
	list(beg,end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
	list(n,elem);//���캯����n��elem����������
	list(const list &lst);//�������캯����
	*/
	list<Person> li1;		//Ĭ�Ϲ���
	list<Person> li2 = li1;	//����
	list<Person> li3(li2);

	//����
	li1.push_back(p1);
	li1.push_front(p2);
	li1.insert(li1.begin(), p3);
	li1.insert(li1.end(), 3, p4);
	li1.push_back(p5);
	list<Person> li4(li1.begin(), li1.end());
	for (auto i : li4)
	{
		i.PrintInfomation();
	}
	cout << "==============" << endl;
	list<Person> li5(3, p1);
	list<Person> li6 = { p1, p2, p3, p4, p5 };///////////////
	for (auto i : li6)
	{
		i.PrintInfomation();
	}
	cout << "==============" << endl;
	li3.insert(li3.begin(), li1.begin(), li1.end());
	for (auto i : li3)
	{
		i.PrintInfomation();
	}
	cout << "==============" << endl;

	//��ֵ
	/*
	assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
	assign(n, elem);//��n��elem������ֵ������
	list& operator=(const list &lst);//���صȺŲ�����
	swap(lst);//��lst�뱾���Ԫ�ػ�����
	*/
	li3 = li1;

	//��С
	/*
	size();//����������Ԫ�صĸ���
	empty();//�ж������Ƿ�Ϊ��
	resize(num);//����ָ�������ĳ���Ϊnum��
	�������䳤������Ĭ��ֵ�����λ�á�
	���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	resize(num, elem);//����ָ�������ĳ���Ϊnum��
	�������䳤������elemֵ�����λ�á�
	���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	*/
	cout << li3.size() << endl;

	//��ȡ ɾ��
	/*
	push_back(elem);//������β������һ��Ԫ��
	pop_back();//ɾ�����������һ��Ԫ��
	push_front(elem);//��������ͷ����һ��Ԫ��
	pop_front();//��������ͷ�Ƴ���һ��Ԫ��
	insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
	insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
	insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
	clear();//�Ƴ���������������
	erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
	erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
	remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
	front();//���ص�һ��Ԫ�ء�
	back();//�������һ��Ԫ�ء�
	*/
	Person a = li1.back();
	a.PrintInfomation();
	li1.pop_back();
	Person b = li1.back();
	b.PrintInfomation();
	Person c = li1.front();
	c.PrintInfomation();
	li1.pop_front();

	//������
	/*
	reverse();//��ת��������lst����1,3,5Ԫ�أ����д˷�����lst�Ͱ���5,3,1Ԫ�ء�
	sort(); //list����
	*/
	cout << "==============" << endl;
	for (list<Person>::iterator i = li1.begin(); i != li1.end(); ++i)
	{
		i->PrintInfomation();
	}
	cout << "==============" << endl;
	li1.reverse();
	for (list<Person>::iterator i = li1.begin(); i != li1.end(); ++i)
	{
		i->PrintInfomation();
	}
	cout << "==============" << endl;
	for (list<Person>::reverse_iterator i = li1.rbegin(); i != li1.rend(); ++i)
	{
		i->PrintInfomation();
	}
	cout << "==============" << endl;

	//ɾ��
	cout << "=======ɾ��=======" << endl;
	li1.erase(li1.begin());
	for (list<Person>::reverse_iterator i = li1.rbegin(); i != li1.rend(); ++i)
	{
		i->PrintInfomation();
	}
	cout << "==============" << endl;
	li1.erase(li1.begin(), li1.begin()++);
	for (list<Person>::reverse_iterator i = li1.rbegin(); i != li1.rend(); ++i)
	{
		i->PrintInfomation();
	}
}

void test2()
{
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	list<Person> li6 = { p1, p2, p3, p4, p5 };
	li6.sort(uppertolow);	//���غ�����Ĭ���������У�������Ҫ�Լ�д���غ���
	for (auto i : li6)
	{
		i.PrintInfomation();
	}
	list<Person> li, li7;
	/*
	push_back(elem);//������β������һ��Ԫ��
	pop_back();//ɾ�����������һ��Ԫ��
	push_front(elem);//��������ͷ����һ��Ԫ��
	pop_front();//��������ͷ�Ƴ���һ��Ԫ��
	insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
	insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
	insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
	clear();//�Ƴ���������������
	erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
	erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
	remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
	*/

	li6.remove(Person("ccc", 30));	//����==��������Ҫ��const
	list<Person>::iterator it = li6.begin();
	it = li6.erase(++li6.begin());
	it->PrintInfomation();
	cout << "==============" << endl;
	li6.erase(++li6.begin(), --li6.end());
	for (auto i : li6)
	{
		i.PrintInfomation();
	}
	cout << "==============" << endl;
	li6.clear();
	cout << li6.empty() << endl;

	li6.resize(6, p1);
	cout << li6.size() << endl;
	li.assign(++li6.begin(), --li6.end());
	li7.assign(3, p2);
	li.swap(li7);
}
//==============������==============//
int main(void)
{
	//test1();
	test2();
	cout << "Compelete" << endl;
	return 0;
}
