#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//==============父类==============//

class Concrete
{
public:
	int a;
	virtual void func1()
	{
		cout << "父类虚函数func1" << endl;
	}
	virtual void func2()
	{
		cout << "父类虚函数func2" << endl;
	}
};

//==============子类==============//

class Derive : public Concrete
{
public:
	virtual void func1()
	{
		cout << "子类虚函数重写func1" << endl;
	}
#if 0
	virtual void func2()
	{
		cout << "子类虚函数重写func2" << endl;
	}
#endif
};

/*
class Derive    size(8):
+---
0      | +--- (base class Concrete)
0      | | {vfptr}		//指向虚函数列表首地址的指针的地址，也是对象的首地址
4      | | a
| +---
+---

Derive::$vftable@:
| &Derive_meta
|  0
0      | &Derive::func1	//在虚函数表中，指向函数1的首地址的 指针 的位置
1      | &Derive::func2	//在虚函数表中，指向函数2的首地址的 指针 的位置

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

//==============测试函数==============//

void test()
{
	Derive d;

#if 0
	typedef void(*P)();
	((P)(*((int*)*(int*)&d + 1)))();
#endif

	((void(*)())(*((int*)*(int*)&d + 1)))();
	/*

	&d：指向虚函数列表首地址的 指针 的地址，也是对象的首地址
	(int*)&d：读取指向虚函数列表首地址的 指针 的地址
	*(int*)&d：取出内存中存储的数据，即虚函数列表的首地址
	虚函数列表的本质是一个指针数组。
	(int*)*(int*)&d：将步长设置为元素大小，处在第0个元素的地址
	(int*)*(int*)&d + 1：第1个元素的地址，是一个指针，指向func2函数的首地址
	*((int*)*(int*)&d + 1)：func2函数的入口地址
	( void(*)() )(*((int*)*(int*)&d + 1))：强转成函数类型
	((void(*)())(*((int*)*(int*)&d + 1)))()：调用函数

	*/
}

//==============主函数==============//

int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
