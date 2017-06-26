#include <iostream>
#include <exception>//�쳣����ͷ�ļ�
#include <string>
using namespace std;

//==============����������==============//
class Person
{
public:
	int age;
	char name[];

public:
	Person(int a)
	{
		age = a;
		cout << "Person ���캯����" << age << endl;
	}

	~Person()
	{
		cout << "Person ����������" << age << endl;
	}
};

//==============��������ָ��==============//
class Pointer
{
private:
	Person * person;

public:
	//���캯������������ָ�룬
	Pointer(Person * transin_person)
	{
		this->person = transin_person;//��ò��������Ķѿռ��ַ
	}
	//����->������
	Person * operator->()//���ض���ָ�룬�ָ�->����������
	{
		return this->person;//�õ�ַ���ز���ʧЧ
	}
	//���ؽ����ò�����
	Person & operator*()//ע�ⷵ�����ã���.����������
	{
		return *(this->person);//�õ�ַ�����÷��ز���ʧЧ
	}
	//�����������ʱ����������ָ������������ʹ����������Զ�����
	~Pointer()
	{
		if (NULL != person)
		{
			delete person;
			person = NULL;
		}
	}
};

//==============�����Լ����쳣������==============//
class myException : public exception
{
private:
	string message;
public:
	//string��ʼ���Ĺ��캯��
	myException(string s)
	{
		message = s;
	}
	//what����
	string & what()
	{
		return message;
	}
};

//==============�׳��쳣����==============//
void throwException(int a)
{
	Person p1(20);				//ջ����
	Person *p2 = new Person(21);//�ѿռ䣬ջ�����ڴ�й©
	Pointer p3(new Person(23));	//����ָ��ѿռ�

	if (a == 0)
	{
		throw myException("�쳣����");	//��ʼջ����
	}
	
	Person p4(24);				//ջ������ջ��������ִ��
}

//==============�쳣������==============//
void exceptionTest()
{
	try
	{
		throwException(0);	//����ջ����
	}
	catch (const exception & ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}
}

//==============����ָ�빹�����Ժ���==============//
void pointertest()
{
	Pointer p(new Person(10));//p��ջ����
	cout << p->age << endl;
	cout << (*p).age << endl;
}

//==============������==============//
int main(void)
{
	//pointertest();

	exceptionTest();

	return 0;
}
