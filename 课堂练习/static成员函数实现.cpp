#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person {
public:
	//普通成员函数可以访问static和non-static成员属性
	void changeParam1(int param) {
		mParam = param;
		sNum = param;
	}
	//静态成员函数只能访问static成员属性
	static void changeParam2(int param);
	void test()
	{
		changeParam2(1);//普通成员函数调用静态成员函数
	}

	void func()const 
	{
		cout << mParam << endl;
		mParam = 1;
	}
private:
	static void changeParam3(int param) {
		//mParam = param; //无法访问
		sNum = param;
	}
public:
	int mParam;
	static int sNum;
};

//静态成员属性类外初始化
int Person::sNum = 0;

void Person::changeParam2(int param)
{
	//mParam = param; //无法访问
	sNum = param;
}

int main() {

	//1. 类名直接调用
	Person::changeParam2(100);

	//2. 通过对象调用
	Person p;
	p.changeParam2(200);

	//3. 静态成员函数也有访问权限
	//Person::changeParam3(100); //类外无法访问私有静态成员函数
	//Person p1;
	//p1.changeParam3(200);
	return EXIT_SUCCESS;
}