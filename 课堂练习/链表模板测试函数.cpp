#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "����ģ��.hpp"

void test()
{
	List<DATA<int, string>,int, string> ls;
	PRINT<int, string> print;
	COMPARE<int, string> compare;

	cout << "//=============����===============//" << endl;
	ls.Insert(new DATA<int, string>(10, "aaa"), 0);
	ls.Insert(new DATA<int, string>(20, "bbb"), 0);
	ls.Insert(new DATA<int, string>(30, "ccc"), 0);
	ls.Insert(new DATA<int, string>(40, "ddd"), 1);
	ls.Insert(new DATA<int, string>(50, "eee"), 2);
	ls.Insert(new DATA<int, string>(60, "fff"), 1);

	ls.Ergodic(PRINT<int, string>());//�����β���������

	cout << "//=============����===============//" << endl;
	ls.Delpos(3);

	ls.Ergodic(PRINT<int, string>());//�����β���������

	cout << "//=============����===============//" << endl;
	ls.Sort(compare); // �����βζ���
	
	ls.Ergodic(print);// �����βζ���

	cout << "//=============����===============//" << endl;
	ls.Reverse();

	ls.Ergodic(print); // �����βζ���

}

int main(void)
{
	test();
	cout << "Compelete" << endl;
	return 0;
}
