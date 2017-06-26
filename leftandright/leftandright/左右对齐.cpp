#include <iostream>
using namespace std;
#include <iomanip>//输出控制符
#include <string>
#include <strstream>

/*
cout.flush() //刷新缓冲区
cout.put() //向缓冲区写字符
cout.write() //从buffe中写num个字节到当前输出流中。
*/
//在Linux下测试，没有刷新缓冲区，hello是不会输出
void test01()
{
	cout << "hello";
	cout.flush();
	cout.put('a').put('b').put('c');
	char buf[1024] = "haha";
	cout.write(buf, 4);
}

//输出控制符----1.通过流成员函数  2.控制符

//通过流成员函数
void test02()
{
	string str = "abcd123";
	cout.width(20);
	cout.setf(ios::left);
	cout.fill('*');
	cout << str << endl;

	int num = 100;
	cout.width(10);
	cout.setf(ios::right);
	cout.fill('*');
	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout.setf(ios::showbase);
	cout << num << endl;
}

//控制符
void test03()
{
	string str1 = "abcd123";
	cout << setw(20)
		<< setfill('*')
		<< setiosflags(ios::left)
		<< str1
		<< endl;
	//先输出占位符号*，再设置左对齐 或者右对齐


	int num = 100;
	cout << setw(10)
		<< setiosflags(ios::right)
		<< setfill('*')
		<< resetiosflags(ios::dec)
		<< setiosflags(ios::hex)
		<< setiosflags(ios::showbase)
		<< num << endl;
}
int main()
{
	//test01();
	test02();
	test03();
	return 0;
}