#include <iostream>
#include <queue>
using namespace std;

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

	Person & operator=(const Person &  obj)
	{
		this->age = obj.age;
		this->name = obj.name;
		return *this;
	}
};

//==============�����ļ�==============//
void test()
{
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	//��ʼ��
	/*
	queue<T> queT;//queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ��
	queue(const queue &que);//�������캯��
	*/
	queue<Person> v1;		//Ĭ�Ϲ���
	queue<Person> v2(v1);	//��������
	queue<Person> v3 = v2;

	//����
	v1.push(p1);
	v1.push(p2);
	v1.push(p3);
	v1.push(p4);
	v1.push(p5);

	//��ֵ
	//queue& operator=(const queue &que);//���صȺŲ�����
	v2 = v1;

	//��ȡ
	/*
	push(elem);//����β���Ԫ��
	pop();//�Ӷ�ͷ�Ƴ���һ��Ԫ��
	back();//�������һ��Ԫ��
	front();//���ص�һ��Ԫ��
	*/
	Person a = v2.back();	//��β
	Person b = v2.front();	//��ͷ
	a.PrintInfomation();
	b.PrintInfomation();
	//��С
	/*
	empty();//�ж϶����Ƿ�Ϊ��
	size();//���ض��еĴ�С
	*/
	cout << "��С = " << v2.size() << endl;

	//ɾ��
	v1.pop();	//��ͷ����
	v3.swap(v1);
}
//���в���������ʣ����ܱ�����û�е�����
//==============������==============//
int main(void)
{
	test();

	return 0;
}