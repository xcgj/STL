#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

//==============�û��Զ���������==============//
class Person
{
private:
	int age;
	char name[16];//���鲻Ҫ��string���ַ���̫����浽�ѿռ䣬��д��ѿռ��ַ
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

//==============д�ļ�==============//
void write()
{
	//�����ļ�����
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
	
	//�û�����		�ۺϳ�ʼ��
	Person man[3] = { Person("aaa", 10), Person("bbb", 20),Person("ccc", 30) };

	//д������
	writef.write((const char *)man, sizeof(man));

	//���ļ�
	writef.close();
}

//==============���ļ�==============//
void read()
{
	//����������
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

	//���ļ�
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
	readf.clear();//�ָ�״̬λ
	readf.seekg(sizeof(men), ios::beg);

	readf.read((char *)&men, sizeof(men));
	men.info();

	//���ļ�
	readf.close();
}

//==============������==============//
int main(void)
{
	write();
	read();
	cout << "Compelete" << endl;
	return 0;
}
