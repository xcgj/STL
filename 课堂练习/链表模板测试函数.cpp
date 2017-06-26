#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "链表模板.hpp"

void test()
{
	List<DATA<int, string>,int, string> ls;
	PRINT<int, string> print;
	COMPARE<int, string> compare;

	cout << "//=============入链===============//" << endl;
	ls.Insert(new DATA<int, string>(10, "aaa"), 0);
	ls.Insert(new DATA<int, string>(20, "bbb"), 0);
	ls.Insert(new DATA<int, string>(30, "ccc"), 0);
	ls.Insert(new DATA<int, string>(40, "ddd"), 1);
	ls.Insert(new DATA<int, string>(50, "eee"), 2);
	ls.Insert(new DATA<int, string>(60, "fff"), 1);

	ls.Ergodic(PRINT<int, string>());//传给形参匿名对象

	cout << "//=============出链===============//" << endl;
	ls.Delpos(3);

	ls.Ergodic(PRINT<int, string>());//传给形参匿名对象

	cout << "//=============排序===============//" << endl;
	ls.Sort(compare); // 传给形参对象
	
	ls.Ergodic(print);// 传给形参对象

	cout << "//=============逆置===============//" << endl;
	ls.Reverse();

	ls.Ergodic(print); // 传给形参对象

}

int main(void)
{
	test();
	cout << "Compelete" << endl;
	return 0;
}
