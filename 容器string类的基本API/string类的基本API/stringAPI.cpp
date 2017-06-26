#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
void test()
{
//==============构造==============//
	/*
	string();//创建一个空的字符串 例如: string str;      
	string(const string& str);//使用一个string对象初始化另一个string对象
	string(const char* s);//使用字符串s初始化
	string(int n, char c);//使用n个字符c初始化 
	*/
	string str1, str7, str8;
	string str2("aaa");
	string str3 = "bbb";
	string str4(3, 'c');
	string str5(str4);
	string str6 = str5;
	cout << "赋值" << endl << str1 << str2 << str3
		<< str4 << str5 << str6 << str7 << str8 << endl;
//==============赋值==============//
	/*
	string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
	string& operator=(const string &s);//把字符串s赋给当前的字符串
	string& operator=(char c);//字符赋值给当前的字符串
	string& assign(const char *s);//把字符串s赋给当前的字符串
	string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
	string& assign(const string &s);//把字符串s赋给当前字符串
	string& assign(int n, char c);//用n个字符c赋给当前字符串
	string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
	*/
	str1 = str2;
	str2 = "abc";
	str3 = 'd';
	str4.assign("efg");
	str5.assign("hijaaa", 3);
	str6.assign(str1);
	str7.assign(3, 'b');
	str8.assign(str5, 2, 1);
	cout << "赋值" << endl << str1 << str2 << str3 
		<< str4 << str5 << str6 << str7 << str8 << endl;
//==============存取字符==============//
	/*
	char& operator[](int n);//通过[]方式取字符
	char& at(int n);//通过at方法获取字符
	*/
	cout << "存取字符" << endl;
	try
	{
		//cout << str1[10] << endl;
		cout << str1.at(10) << endl;
	}
	catch (const std::exception& ex)
	{
		cout << "下标越界" << endl;
	}
//==============拼接==============//
	/*
	string& operator+=(const string& str);//重载+=操作符
	string& operator+=(const char* str);//重载+=操作符
	string& operator+=(const char c);//重载+=操作符
	string& append(const char *s);//把字符串s连接到当前字符串结尾
	string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
	string& append(const string &s);//同operator+=()
	string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
	string& append(int n, char c);//在当前字符串结尾添加n个字符c
	*/

	str1 = "0"; str2 = str3 = str4 = str5 = '0';
	str1 += "111";
	str1 += '5';
	str2 += str1;
	str3 = str1 + "222";
	str4 = str1 + str2;
	str5 = str1 + str1 + "333" + str1 + '4';
	cout << "拼接" << endl << str1 << " " << str2 << " " << str3
		<< " " << str4 << " " << str5 << " " << endl;

	str1 = "0"; str2 = str3 = str4 = str5 = '0';
	str1.append("aaa");
	str2.append("bbbccc", 3);
	str3.append(str1);
	str4.append(str2, 1, 2);
	str5.append(3, 'c');
	cout << "拼接" << endl << str1 << " " << str2 << " " << str3
		<< " " << str4 << " " << str5 << " " << endl;
//==============查找替换==============//
	/*
	int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
	int find(const char* s, int pos = 0) const;		//查找s第一次出现位置,从pos开始查找
	int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
	int find(const char c, int pos = 0) const;		//查找字符c第一次出现位置
	int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
	int rfind(const char* s, int pos = npos) const;	//查找s最后一次出现位置,从pos开始查找
	int rfind(const char* s, int pos, int n) const;	//从pos查找s的前n个字符最后一次位置
	int rfind(const char c, int pos = 0) const;		//查找字符c最后一次出现位置
	string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
	string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
	*/
	string str = "aabbccddaabbaaeeaa";
	//			  012345678901234567
	str1 = "aa";
	int a, b, c, d, e, f, g;
	a = str.find('b');
	b = str.find('b', 5);
	c = str.find("bb");
	d = str.find("bb", 5);
	e = str.find(str1);
	f = str.find(str1, 5);
	g = str.find("aecd", 5, 2);
	cout << "查找替换" << endl << a << " " << b << " " << c
		<< " " << d << " " << e << " "<< f << " " << g << " " << endl;
	a = str.rfind(str1);
	b = str.rfind(str1, 5);
	c = str.rfind("aa");
	d = str.rfind("aa", 5);
	e = str.rfind("abcd", 15, 2);
	f = str.rfind('g');
	g = str.rfind('a', 10);
	cout << a << " " << b << " " << c << " " << d << " " << 
		e << " " << f << " " << g << " " << endl;
	str2 = str.replace(5, 3, "jjjjjj");
	str3 = "kkkkkk";
	str4 = str.replace(5, 3, str3);//替换3个字符，其余插入
	cout << str2 << " " << str4 << endl;
//==============比较==============//
	/*
	compare函数在>时返回 1，<时返回 -1，==时返回 0。
	比较区分大小写，比较时参考字典顺序，排越前面的越小。
	大写的A比小写的a小。
	int compare(const string &s) const;//与字符串s比较
	int compare(const char *s) const;//与字符串s比较
	*/
	str1 = "bbb";
	str2 = "BBB";
	cout << "比较" << endl;
	cout << str1.compare(str2) << str1.compare("ddd") << endl;
//==============子串==============//
	/*
	string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
	*/
	str1 = str.substr(5, 3);
	cout << "子串" << endl << str1 << endl;
//==============插入删除==============//
	/*
	string& insert(int pos, const char* s); //插入字符串
	string& insert(int pos, const string& str); //插入字符串
	string& insert(int pos, int n, char c);//在指定位置插入n个字符c
	string& erase(int pos, int n = npos);//删除从Pos开始的n个字符 
	*/
	str1 = "11"; str2 = "22";
	str1.insert(1, "aa");
	str1.insert(2, str2);
	str1.insert(3, 2, 'b');
	cout << "插入" << endl << str1 << endl;
	str1.erase(1, 2);
	cout << "删除" << endl << str1 << endl;
//==============和c风格字符串转换==============//
	//string 转 char*
	const char * cstr = str1.c_str();
	//char* 转 string 
	str2 = "aaa";
	cout << "转换" << endl << cstr << str2 << endl;
}

int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
