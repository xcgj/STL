#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

/*
使用文件IO读取a.txt文件中的信息，构建Person对象，
使用选择排序按年龄从小到大排序，
将排序后的结果重新写入到文件中（写入方式不限），禁止向文件中写入string类型
*/

//==============测试类==============//
class Person
{
public:
	char name[64];
	int age;
public:
	Person()
	{
		name[0] = '\0';
		age = 0;
	}

	char * GetName()
	{
		return name;
	}

	int GetAge()
	{
		return age;
	}

	void PrintInfomation()
	{
		std::cout << "name = " << name << ", age = " << age << endl;
	}
};

//==============自定义函数工具、类工具==============//
//读文件行数
void readLine(int & n)
{
	//缓冲
	char buf[1024] = { 0 };
	int line = 0;

	//读
	fstream readfile("./a.txt", ios::in);
	if (!readfile)
	{
		return;
	}

	while (readfile >> buf)
	{
		line++;
		memset(buf, 0, sizeof(buf));
	}
	
	readfile.close();

	n = line;
}

//读文件
void readFile(Person * & p, int line)
{
	//缓冲
	char buf[1024] = { 0 };

	//读
	fstream readfile("./a.txt", ios::in);
	if (!readfile)
	{
		return;
	}

	for (int i = 0; i < line; ++i)
	{
		readfile.getline(buf, 1024);
		char *pname = NULL;
		/*pname = strtok(buf, "#");
		//cout << pname << endl;
		strcpy(p[i].name, pname);*/

		pname = strchr(buf, '#');
		pname++;
		//cout << pname << endl;//年龄
		p[i].age = atoi(pname);
		
		pname = strtok(buf, "#");
		//cout << pname << endl;//名字
		strcpy(p[i].name, pname);

		memset(buf, 0, sizeof(buf));
	}
}

//排序
void selectSort(Person * & p, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int minindex = i;
		Person min = p[i];
		int j = i + 1;
		for (; j < length; j++)
		{
			if (min.age > p[j].age)
			{
				min = p[j];
				minindex = j;
			}
		}

		if (i != minindex)
		{
			Person tmp = p[i];
			p[i] = p[minindex];
			p[minindex] = tmp;
		}
	}
}

//写文件
void writeFile(Person * & p, int line)
{
	ofstream writefile;
	writefile.open("./b.txt", ios::out);
	if (!writefile.is_open())
	{
		return;
	}

	for (int i = 0; i < line; i++)
	{
		writefile << p[i].name << ", " << p[i].age << endl;
	}

	writefile.close();
}

//==============测试函数==============//
void test()
{
	int lines = 0;
	readLine(lines);
	cout << lines << " " << endl;;

	Person *person = new Person[lines];
	cout << "==============读文件==============" << endl;
	readFile(person, lines);
	for (int i = 0; i < lines; ++i)
	cout << person[i].name << " " << person[i].age << endl;

	cout << "==============排序==============" << endl;
	selectSort(person, lines);
	for (int i = 0; i < lines; ++i)
	cout << person[i].name << " " << person[i].age << endl;

	cout << "==============写文件==============" << endl;
	writeFile(person, lines);
}

//==============主函数==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}