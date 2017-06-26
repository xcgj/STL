#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//==============�����==============//

class Concrete
{
public:
	Concrete(int) {}//����

	int a;
};

//==============������==============//

class Derive1: virtual public Concrete
{
public:
	Derive1() :Concrete(1) {}
};

class Derive2 : virtual public Concrete
{
public:
	Derive2() :Concrete(2) {}
};

//==============������==============//

class SON : public Derive1, public Derive2
{
public:
	SON() :Concrete(1) {}
};

//==============���Ժ���==============//
void test1()
{
	SON * son = new SON;
}

void test2()
{
	//�Ƚ�a��ֵ
	Derive1 * d1 = new Derive1;
	d1->a = 50;

	//��Derive1����麯��ָ�����a
	(*((Concrete*)((char*)d1 + *((int*)*(int*)d1 + 1)))).a;
	
	//��������1��Ԫ�ص�ֵ
	//Ӧ�����4
	cout << *((int*)*(int*)d1 + 1) << endl;
	//a��ֵ
	//Ӧ�����50
	cout << ((Concrete*)((char*)d1 + *((int*)*(int*)d1 + 1)))->a << endl;
	delete d1;
	d1 = NULL;
}

/*
class Derive1   size(8):
+---
0      | {vbptr}
+---
+--- (virtual base Concrete)
4      | a
+---

Derive1::$vbtable@:
0      | 0
1      | 4 (Derive1d(Derive1+0)Concrete)
vbi:       class  offset o.vbptr  o.vbte fVtorDisp
		Concrete       4       0       4 0
*/

void test3()
{
	//�Ƚ�a��ֵ
	SON * son = new SON;
	son->a = 100;

	//��Derive1����麯��ָ�����a
	(*((Derive1*)((char*)son + *((int*)*(int*)son + 1)))).a;
	/*
	son�������ַ��Ҳ��������б�ָ��ĵ�ַ
	(int*)son��������б�ָ�����ڴ��еĴ洢�ռ�
	*(int*)son���麯���б�ָ��ָ��ĵ�ַ������������׵�ַ��Ҳ���������е�һ��Ԫ�صĵ�ַ
	����������һ������
	(int*)*(int*)son��ָ�������������Ϊint
	(int*)*(int*)son + 1�������������1��Ԫ�ص��׵�ַ
	*((int*)*(int*)son + 1)��������������1��Ԫ�ص�ֵ,����ָ��������ָ������ڸ�ָ���ƫ����
	(char*)son�������ַ��Ҳ��������б�ָ��ĵ�ַ����char*����
	(char*)son + *((int*)*(int*)son + 1)��ָ��������ָ�����ʵ��ַ
	*((char*)son + *((int*)*(int*)son + 1))���������׵�ַ
	((Concrete*)((char*)son + *((int*)*(int*)son + 1)))��Concrete�Ĳ���������������ڿռ�
	*((Concrete*)((char*)son + *((int*)*(int*)son + 1)))����������
	(*((Concrete*)((char*)son + *((int*)*(int*)son + 1)))).a������a��ֵ
	*/
	//��������1��Ԫ�ص�ֵ
	//Ӧ�����8
	cout << *((int*)*(int*)son + 1) << endl;
	
	//�鿴��ַ�Ƿ�һ��
	cout << &(son->a) << endl;
	cout << (Concrete*)((char*)son + *((int*)*(int*)son + 1)) << endl;

	//a��ֵ
	//Ӧ����Ҳ��100��Derive1��a��SON��a��ͬһ��
	cout << ((Concrete*)((char*)son + *((int*)*(int*)son + 1)))->a << endl;
	//cout << ((Derive1*)((char*)son + *((int*)*(int*)son + 1)))->a << endl;//�������
	//Derive1�Ĵ�С��8���ֽڣ�((char*)son + *((int*)*(int*)son + 1))��Ȼ�Ѿ�ָ����Derive1�е�a�ĵ�ַ��
	//���ǣ�(Derive1*)ת���ͺ�һ���Ի�ȡ��8���ֽڽ��н����ã�ǰ4���ֽ���a�Ŀռ䣬��4���ֽ���Խ��ķǷ��ռ䣬���Գ���

	delete son;
	son = NULL;
}

//==============������==============//

int main(void)
{
	test1();
	test2();
	test3();

	cout << "Compelete" << endl;
	return 0;
}

/*
class SON       size(12):
+---
0      | +--- (base class Derive1)
0      | | {vbptr}		//�̳���Derive1�������ָ��
| +---
4      | +--- (base class Derive2)
4      | | {vbptr}		//�̳���Derive2�������ָ��
| +---
+---
+--- (virtual base Concrete)
8      | a
+---

SON::$vbtable@Derive1@:	//�����ָ��ָ����б��׵�ַ��
0      | 0
1      | 8 (SONd(Derive1+0)Concrete)	

/////////////////////////////////////
//1��λ�ô�ŵ�Ԫ����8��
//��ʾ��Derive1�������ָ��Ӹ�ָ���׵�ַ��ʼ������8���ֽڣ����λ�ã���
//����ָ��������ָ�����ڵ�λ��
////////////////////////////////////

SON::$vbtable@Derive2@:
0      | 0
1      | 4 (SONd(Derive2+0)Concrete)
vbi:       class  offset o.vbptr  o.vbte fVtorDisp
		Concrete       8       0       4 0

/////////////////////////////////////
//1��λ�ô�ŵ�Ԫ����4��
//��ʾ��Derive2�������ָ��Ӹ�ָ���׵�ַ��ʼ������4���ֽڣ����λ�ã���
//����ָ��������ָ�����ڵ�λ��
////////////////////////////////////
*/

/*
���ۣ�
1. ��������вι��죬���������ȫ��дһ�³�ʼ���б�
2. 
*/