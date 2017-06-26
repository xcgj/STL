#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

/*
ʹ���ļ�IO��ȡa.txt�ļ��е���Ϣ������Person����
ʹ��ѡ�����������С��������
�������Ľ������д�뵽�ļ��У�д�뷽ʽ���ޣ�����ֹ���ļ���д��string����
*/

//==============������==============//
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

//==============�Զ��庯�����ߡ��๤��==============//
//���ļ�����
void readLine(int & n)
{
	//����
	char buf[1024] = { 0 };
	int line = 0;

	//��
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

//���ļ�
void readFile(Person * & p, int line)
{
	//����
	char buf[1024] = { 0 };

	//��
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
		//cout << pname << endl;//����
		p[i].age = atoi(pname);
		
		pname = strtok(buf, "#");
		//cout << pname << endl;//����
		strcpy(p[i].name, pname);

		memset(buf, 0, sizeof(buf));
	}
}

//����
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

//д�ļ�
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

//==============���Ժ���==============//
void test()
{
	int lines = 0;
	readLine(lines);
	cout << lines << " " << endl;;

	Person *person = new Person[lines];
	cout << "==============���ļ�==============" << endl;
	readFile(person, lines);
	for (int i = 0; i < lines; ++i)
	cout << person[i].name << " " << person[i].age << endl;

	cout << "==============����==============" << endl;
	selectSort(person, lines);
	for (int i = 0; i < lines; ++i)
	cout << person[i].name << " " << person[i].age << endl;

	cout << "==============д�ļ�==============" << endl;
	writeFile(person, lines);
}

//==============������==============//
int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}