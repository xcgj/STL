#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//==============������Ԫ����ʵ��==============//
template<typename T>
class BASE
{
	//==============<<����������==============//
	friend ostream& operator<< <> (ostream & out, BASE & base);
	//	<>��������ǿ��ģ�廯���Ǹ��߱������������Ԫ�Ǻ���ģ���������������ͨ���������������ӵ�ʱ���Һ���ģ��
};

template<typename T>
ostream& operator<<(ostream & out, BASE<T> & base)
{
	out << "<<����" << endl;
	return out;
}
//
//template<typename T>
//operator()(T a)
//{
//	cout << "()����" << a << endl;
//}

//==============��ͨ��Ԫ����ʵ��==============//
//��������
template<typename T> class DERIVE;
//����������
template<typename T> void visit(DERIVE<T> & d);

//void normalfunc();

//��ʵ����
template<typename T>
class DERIVE
{
private:
	T a;
public:
	DERIVE()
	{
		a = 10;
	}
	//template<typename T2> Ҫ������ģ�庯��
	//ע�⣬DERIVE��Ȼ������������棬����Ҳ������Ԫ����ģ����������������Ԫ����ģ�����������ˣ���
	//һ��Ҫ����<T2>���״�㡣������������������������������
	template<typename T2> friend void visit(DERIVE<T2> & d);


	//��ͨ����ʵ��
	friend void normalfunc();
	//��Ա����
	void memberfunc(){}
};

//���ʵ�ֺ���
template<typename T>
void visit(DERIVE<T> & d)
{
	cout << "����ʵ����Ԫģ�庯��" << d.a << endl;	//���벻����
}

void normalfunc()
{
	cout << "ֻ��һ����ͨ��Ԫ����" << endl;
}

//==============��ͨ��==============//
class A
{
	int a = 10;
	friend void func(A & b);
};

void func(A & b)
{
	cout << "a = " << b.a << endl;
}
//==============���Ժ���==============//
void test1()
{
	BASE<int> a;
	cout << a << endl;
}

void test2()
{
	DERIVE<int> c;
	visit(c);//���ü�<int>			//�����޷�����a��
	//normalfunc();
}

void test3()
{
	A test;
	func(test);
}
//==============������==============//

int main(void)
{
	//test1();
	test2();
	//test3();
	cout << "Compelete" << endl;
	return 0;
}
