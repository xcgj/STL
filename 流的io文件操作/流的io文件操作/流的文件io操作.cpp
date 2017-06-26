#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

//==============写文件==============//
void ioWrite()
{
	//文件指针
#if 0
	ofstream outfile("test.txt", ios::out);
	if (!outfile)
	{
		//throw bad_alloc("没有这个文件");
	}
#else 
	ofstream outfile;
	outfile.open("test.txt", ios::out);
	if (outfile.is_open())
	{
		//throw bad_alloc("没有这个文件");
	}
#endif

	//写文件
	char * buf[] = { "aaa\n","bbb\n","ccc\n" };
	for (int i = 0; i < 3; i++)
	{
		outfile << buf[i];
	}

	//关文件
	outfile.close();
}

//==============读文件==============//
void ioRead()
{
	//开文件
#if 1
	ifstream readfile("test.txt"/*, ios::in*/);//默认是读文件
	if (!readfile)
	{
		//throw bad_alloc("没有这个文件");
	}
#else
	ifstream readfile;
	readfile.open("test.txt", ios::in);
	if (readfile.is_open())
	{
		//throw bad_alloc("没有这个文件");
	}
#endif

	//读文件
	char buf[1024] = { 0 };
#if 0
	while (readfile.getline(buf, 1024))
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}
#else
	while (readfile >> buf)
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}
#endif

	if (readfile.eof())
	{
		cout << "文件游标在文件结尾" << endl;
	}
	//重新读取一次文件，需要重置状态
	readfile.clear();//重置good状态位
	readfile.seekg(0, ios::beg);//文件游标回到文件起始位置
	memset(buf, 0, 1024);

	while (readfile.getline(buf, 1024))
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}

	//关文件
	readfile.close();
}

//==============主函数==============//
int main(void)
{
	ioWrite();
	ioRead();

	cout << "Compelete" << endl;
	return 0;
}
