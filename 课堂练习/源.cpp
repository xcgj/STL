#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class person
{
public:
	int c;
	person()
	{
		cout << "默认构造" << endl;
	}

	/*person(int)
	{
		cout << "构造" << endl;
	}*/
	person & operator=(int b)
	{
		this->c = b;
		return *this;
	}
};

int main()
{
	person a;
	a = 9;
	return 0;
}