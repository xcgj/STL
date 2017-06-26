#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include <map>
void test()
{
	cout << "===========创建对组===========" << endl;
	pair<string, int> p1("aaa", 20);
	pair<string, int> p2 = make_pair("bbb", 30);
	pair<string, int> p3 = p1;
	pair<string, int> p4 = map<string, int>::value_type("ccc", 40);
	cout << p4.first << ", " << p4.second << endl;
}

int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
