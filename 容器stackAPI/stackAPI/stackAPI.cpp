#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stack>

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

	Person & operator= (const Person & obj)//�����const
	{
		name = obj.name;
		age = obj.age;
		return *this;
	}
};

//==============���Ժ���==============//
void test()
{
	//������
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	stack<Person> s4;
	stack<Person> s5;
	s5 = s4;

	//��ʼ��
	//stack<T> stkT;//stack����ģ����ʵ�֣� stack�����Ĭ�Ϲ�����ʽ�� 
	//stack(const stack &stk);//�������캯��
	stack<Person> s1;		//Ĭ�Ϲ���
	stack<Person> s2 = s1;	//��������
	stack<Person> s3;


	//����
	s1.push(p1);
	s1.push(p2);
	s1.push(p3);
	s1.push(p4);
	s1.push(p5);

	//push(elem);	//��ջ�����Ԫ��
	//pop();		//��ջ���Ƴ���һ��Ԫ��
	//top();		//����ջ��Ԫ��
	//empty();		//�ж϶�ջ�Ƿ�Ϊ��
	//size();		//���ض�ջ�Ĵ�С
	//stack& operator=(const stack &stk);//���صȺŲ�����
	s3 = s2;			//��ֵ
	Person a = s1.top();//��ջ��
	s1.pop();			//ɾջ��
	a.PrintInfomation();
	cout << s1.size() << endl;	//��С
	cout << s1.empty() << endl;	//��С
	//s2.swap(s1);		//����
}
//ջ����������ʣ�û�е�����
//==============������==============//
int main(void)
{
	test();
	cout << "Compelete" << endl;
	return 0;
}
