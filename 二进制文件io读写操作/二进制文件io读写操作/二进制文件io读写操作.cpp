#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

//==============用户自定数据类型==============//
class Person
{
private:
	int age;
	char name[16];//建议不要用string，字符串太长会存到堆空间，会写入堆空间地址
public:
	Person(char * s, int a)
	{
		strcpy(name, s);
		age = a;
	}
	void info()
	{
		cout << name << " " << age << endl;
	}
};

//==============写文件==============//
void write()
{
	//创建文件对象
#if 1
	ofstream writef("test.txt", ios::out | ios::binary);
	if (!writef)
	{
		//throw;
	}
#else
	ofstream writef;
	if (writef.open("test.txt", ios::out | ios::binary))
	{
		//throw;
	}
#endif
	
	//用户数据		聚合初始化
	Person man[3] = { Person("aaa", 10), Person("bbb", 20),Person("ccc", 30) };

	//写入数据
	writef.write((const char *)man, sizeof(man));

	//关文件
	writef.close();
}

//==============读文件==============//
void read()
{
	//创建读对象
#if 1
	ifstream readf("test.txt", ios::in | ios::binary);
	if (!readf)
	{
		//throw;
	}
#else
	ifstream readf;
	if (readf.open("test.txt", ios::in | ios::binary))
	{
		//throw;
	}
#endif

	//读文件
	Person men("eee", 100);
	while (!readf.eof())
	{
		readf.read((char *)&men, sizeof(men));

		if (readf.eof())
		{
			break;
		}

		men.info();
	}

	cout << "---------------" << endl; 
	readf.clear();//恢复状态位
	readf.seekg(sizeof(men), ios::beg);

	readf.read((char *)&men, sizeof(men));
	men.info();

	//关文件
	readf.close();
}

//==============主函数==============//
int main(void)
{
	write();
	read();
	cout << "Compelete" << endl;
	return 0;
}
