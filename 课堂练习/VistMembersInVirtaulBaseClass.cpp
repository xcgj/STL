#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//==============虚基类==============//

class Concrete
{
public:
	Concrete(int) {}//构造

	int a;
};

//==============子类们==============//

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

//==============孙子类==============//

class SON : public Derive1, public Derive2
{
public:
	SON() :Concrete(1) {}
};

//==============测试函数==============//
void test1()
{
	SON * son = new SON;
}

void test2()
{
	//先将a赋值
	Derive1 * d1 = new Derive1;
	d1->a = 50;

	//用Derive1类的虚函数指针访问a
	(*((Concrete*)((char*)d1 + *((int*)*(int*)d1 + 1)))).a;
	
	//虚基类表中1号元素的值
	//应该输出4
	cout << *((int*)*(int*)d1 + 1) << endl;
	//a的值
	//应该输出50
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
	//先将a赋值
	SON * son = new SON;
	son->a = 100;

	//用Derive1类的虚函数指针访问a
	(*((Derive1*)((char*)son + *((int*)*(int*)son + 1)))).a;
	/*
	son：对象地址，也是虚基类列表指针的地址
	(int*)son：虚基类列表指针在内存中的存储空间
	*(int*)son：虚函数列表指针指向的地址，即虚基类表的首地址，也是虚基类表中第一个元素的地址
	虚基类表本质是一个数组
	(int*)*(int*)son：指定数组操作步长为int
	(int*)*(int*)son + 1：访问虚基类表的1号元素的首地址
	*((int*)*(int*)son + 1)：访问虚基类表中1号元素的值,就是指向虚基类的指针相对于该指针的偏移量
	(char*)son：对象地址，也是虚基类列表指针的地址，以char*访问
	(char*)son + *((int*)*(int*)son + 1)：指向虚基类的指针的真实地址
	*((char*)son + *((int*)*(int*)son + 1))：虚基类的首地址
	((Concrete*)((char*)son + *((int*)*(int*)son + 1)))：Concrete的步长访问虚基类所在空间
	*((Concrete*)((char*)son + *((int*)*(int*)son + 1)))：虚基类对象
	(*((Concrete*)((char*)son + *((int*)*(int*)son + 1)))).a：访问a的值
	*/
	//虚基类表中1号元素的值
	//应该输出8
	cout << *((int*)*(int*)son + 1) << endl;
	
	//查看地址是否一样
	cout << &(son->a) << endl;
	cout << (Concrete*)((char*)son + *((int*)*(int*)son + 1)) << endl;

	//a的值
	//应该是也是100，Derive1的a和SON的a是同一个
	cout << ((Concrete*)((char*)son + *((int*)*(int*)son + 1)))->a << endl;
	//cout << ((Derive1*)((char*)son + *((int*)*(int*)son + 1)))->a << endl;//错误代码
	//Derive1的大小是8个字节，((char*)son + *((int*)*(int*)son + 1))虽然已经指向了Derive1中的a的地址，
	//但是，(Derive1*)转类型后，一次性会取出8个字节进行解引用，前4个字节是a的空间，后4个字节是越界的非法空间，所以出错

	delete son;
	son = NULL;
}

//==============主函数==============//

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
0      | | {vbptr}		//继承了Derive1的虚基类指针
| +---
4      | +--- (base class Derive2)
4      | | {vbptr}		//继承了Derive2的虚基类指针
| +---
+---
+--- (virtual base Concrete)
8      | a
+---

SON::$vbtable@Derive1@:	//虚基类指针指向的列表（首地址）
0      | 0
1      | 8 (SONd(Derive1+0)Concrete)	

/////////////////////////////////////
//1号位置存放的元素是8，
//表示用Derive1的虚基类指针从该指针首地址开始往后走8个字节（相对位置），
//就是指向虚基类的指针所在的位置
////////////////////////////////////

SON::$vbtable@Derive2@:
0      | 0
1      | 4 (SONd(Derive2+0)Concrete)
vbi:       class  offset o.vbptr  o.vbte fVtorDisp
		Concrete       8       0       4 0

/////////////////////////////////////
//1号位置存放的元素是4，
//表示用Derive2的虚基类指针从该指针首地址开始往后走4个字节（相对位置），
//就是指向虚基类的指针所在的位置
////////////////////////////////////
*/

/*
结论：
1. 虚基类有有参构造，其子类必须全部写一下初始化列表
2. 
*/