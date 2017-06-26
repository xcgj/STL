#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <strstream>
#include <iomanip>
using namespace std;

//==============cin测试函数==============//
/*
cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
*/
void cintest()
{
	char a, b, c, d, e;
	char s[100] = { 0 };

#if 0
	cin.get(c);
	cout << c << endl;
#elif 0
	c = cin.get();
	cout << c << endl;
#elif 0
	c = cin.get();
	cout << c << endl;
	c = cin.get();
	cout << c << endl;
	c = cin.get();
	cout << c << endl;
	c = cin.get();
	cout << c << endl;
	c = cin.get();
	cout << c << endl;
	cout << cin.get();
	cout << cin.get();
	cout << cin.get();
	//结论：
	// 能读取换行符，也能读取空格
	// 按回车后不能读取本次回车输入的换行符'\n'，换行符还在缓冲区，下一次开始能读取到。
	// cout << cin.get();读取的是字符的ASCII码
	// 缓冲区不为空时，会依次读取字符，每读取都会将会缓冲区里的字符取出来放入c，cout显示到屏幕上
	// 当缓冲区读完时，会等待用户输入新的内容，继续读取，直到不再调用cin.get()
#elif 0
	//链式编程
	cin.get(a).get(b).get(c).get(d).get(e);
	cout << a << b << c << d << e << endl;
#elif 0
	cin.get(s, 10);
	cout << s;
	//注意点：
	//输入：0123456789
	//输出：012345678
	//结论：
	//cin.get(s, 10)在输入字符串超出范围时，自动在结尾接上了‘\0’，可见这个函数是安全的
	//验证：
	c = cin.get();
	cout << endl << c << endl;
	//输入：012345678987654321
	//输出：012345678
	//		9
#elif 0
	//cin.clear(ios::failbit);
	//c = cin.get();
	//cout << c;
	cin.getline(s, 5);
	cout << s;
	cin.clear();
	c = cin.get();
	cout << '@' << c;
	c = cin.get();
	cout << c;
	c = cin.get();
	cout << c;
	/*
	asdfghjk
	asdf@ghj请按任意键继续. . .
	结论：s能读取到的有效字符数量为5 - 1个，最后一个字符为‘\0'
		  因为越界，导致ios::goodbit状态位变成了false。
	*/
#elif 0
	cin.ignore(3);//忽略3个字符
	cin.getline(s, 10);
	cout << s;
#elif 0
	a = cin.peek();//查看缓冲区有没有字符，并 复制 第一个字符给c；
	cout << '@' << a;
	if (a == '\n')
	{
		cout << "a读了换行";
	}
	b = cin.peek();
	cout << '@' << b;
	if (b == '\n')
	{
		cout << "b读了换行";
	}

	e = cin.get();

	c = cin.peek();
	cout << '@' << c;
	if (c == '\n')
	{
		cout << "c读了换行";
	}
	d = cin.peek();
	cout << '@' << d;
	if (d == '\n')
	{
		cout << "d读了换行";
	}
	/*	
	@
	a读了换行@
	b读了换行a
	@a@a请按任意键继续. . .
	*/
#elif 0
	cin.get(a);
	cout << '@' << a << endl;
	cin.getline(s, 5);
	cout << '@' << s << endl;
	cin.clear();
	cin.putback(a);
	cout << '@' << a << endl;
	cin.getline(s, 20);
	cout << '@' << s << endl;
	/*
	asdfghjk
	@a
	@sdfg
	@a
	@ahjk
	请按任意键继续. . .
	*/
#endif
}

//==============cout测试函数==============//
void couttest()
{
/*
cout.flush() //刷新缓冲区
cout.put() //向缓冲区写字符
cout.write() //从buffe中写num个字节到当前输出流中。
*/
	char a, b, c, d, e;
	char s[1024] = { 0 };

#if 0	//	linux下测试有效
	cout << "abc";
	cout.flush();
#elif 0
	cout.put('a');
	//链式编程
	cout.put('\n').put('a').put('b').put('c');
#elif 0
	//左对齐输出字符宽度为5，不够以空格补齐
	//字符串长度大于数字，多余的不输出
	cout.write("abc" ,1);
	cout.put('a');
#elif 0
	char buf[1024] = "abcde";
	cout.write(buf, 1);
	cout.put('a');
#endif

}

//==============主函数==============//
int main(void)
{
	//cintest();
	couttest();

	return 0;
}
