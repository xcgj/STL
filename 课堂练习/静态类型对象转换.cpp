#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class FuLei
{
public:	
	virtual void a(){}
};

class ZiLei : public FuLei
{
public:
	int a;
	int b;
};

class E
{};

int main(void)
{

#if 0
	FuLei * f = NULL;
	ZiLei * s = NULL;
	E * e = NULL;

	FuLei fc;//父类对象
	ZiLei sc;//子类对象

	//向下类型转换
	s = static_cast		<ZiLei *>(f);
	s = dynamic_cast	<ZiLei *>(f);//要有虚函数才不会报错——虚函数列表——运行时检查
	s = reinterpret_cast<ZiLei *>(f);//不管什么情况都支持
	//向上类型转换
	f = static_cast		<FuLei *>(s);
	f = dynamic_cast	<FuLei *>(s);
	f = reinterpret_cast<FuLei *>(s);
	//e = dynamic_cast<ZiLei *>(f);	//报错
	//e = static_cast<FuLei *>(s);	//报错
	
	fc = (FuLei)sc;
	fc = static_cast<FuLei>(sc);
	//sc = (ZiLei)fc;				//报错	？
	//sc = static_cast<ZiLei>(fc);	//报错	？

#endif
	FuLei * f = new FuLei;
	ZiLei * s = new ZiLei;
	ZiLei * t = dynamic_cast	<ZiLei *>(f);//要有虚函数才不会报错——虚函数列表——运行时检查
	if (NULL == t)
	{
		cout << "t是空指针" << t << endl;
	}
	//基类有虚函数，dynamic_cast检测到向下类型转换时，会返回空指针
	cout << "Compelete" << endl;
	return 0;
}
