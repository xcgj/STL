#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//==============����==============//

class Concrete
{
public:
	int a;
	virtual void func1()
	{
		cout << "�����麯��func1" << endl;
	}
	virtual void func2()
	{
		cout << "�����麯��func2" << endl;
	}
};

//==============����==============//

class Derive : public Concrete
{
public:
	virtual void func1()
	{
		cout << "�����麯����дfunc1" << endl;
	}
#if 0
	virtual void func2()
	{
		cout << "�����麯����дfunc2" << endl;
	}
#endif
};

/*
class Derive    size(8):
+---
0      | +--- (base class Concrete)
0      | | {vfptr}		//ָ���麯���б��׵�ַ��ָ��ĵ�ַ��Ҳ�Ƕ�����׵�ַ
4      | | a
| +---
+---

Derive::$vftable@:
| &Derive_meta
|  0
0      | &Derive::func1	//���麯�����У�ָ����1���׵�ַ�� ָ�� ��λ��
1      | &Derive::func2	//���麯�����У�ָ����2���׵�ַ�� ָ�� ��λ��

Derive::func1 this adjustor: 0
Derive::func2 this adjustor: 0
*/

/*
class Derive    size(8):
+---
0      | +--- (base class Concrete)
0      | | {vfptr}
4      | | a
| +---
+---

Derive::$vftable@:
| &Derive_meta
|  0
0      | &Derive::func1
1      | &Concrete::func2

Derive::func1 this adjustor: 0
*/

//==============���Ժ���==============//

void test()
{
	Derive d;

#if 0
	typedef void(*P)();
	((P)(*((int*)*(int*)&d + 1)))();
#endif

	((void(*)())(*((int*)*(int*)&d + 1)))();
	/*

	&d��ָ���麯���б��׵�ַ�� ָ�� �ĵ�ַ��Ҳ�Ƕ�����׵�ַ
	(int*)&d����ȡָ���麯���б��׵�ַ�� ָ�� �ĵ�ַ
	*(int*)&d��ȡ���ڴ��д洢�����ݣ����麯���б���׵�ַ
	�麯���б�ı�����һ��ָ�����顣
	(int*)*(int*)&d������������ΪԪ�ش�С�����ڵ�0��Ԫ�صĵ�ַ
	(int*)*(int*)&d + 1����1��Ԫ�صĵ�ַ����һ��ָ�룬ָ��func2�������׵�ַ
	*((int*)*(int*)&d + 1)��func2��������ڵ�ַ
	( void(*)() )(*((int*)*(int*)&d + 1))��ǿת�ɺ�������
	((void(*)())(*((int*)*(int*)&d + 1)))()�����ú���

	*/
}

//==============������==============//

int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
