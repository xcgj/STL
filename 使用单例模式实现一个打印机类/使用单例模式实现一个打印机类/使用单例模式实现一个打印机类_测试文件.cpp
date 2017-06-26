
#include "使用单例模式实现一个打印机类.h"

void test()
{
	//3人使用打印机
	SINGLETON * p1 = SINGLETON::GetSingleton();
	SINGLETON * p2 = SINGLETON::GetSingleton();
	SINGLETON * p3 = SINGLETON::GetSingleton();

	//打印文件
	p1->print("aaa");
	p2->print("bbb");
	p1->print("aaa");
	p3->print("ccc");
	p2->print("bbb");

	//打印次数
	cout << "总共打印的次数为：" << SINGLETON::GetCount() << endl;
}

int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
