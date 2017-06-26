#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

//==============д�ļ�==============//
void ioWrite()
{
	//�ļ�ָ��
#if 0
	ofstream outfile("test.txt", ios::out);
	if (!outfile)
	{
		//throw bad_alloc("û������ļ�");
	}
#else 
	ofstream outfile;
	outfile.open("test.txt", ios::out);
	if (outfile.is_open())
	{
		//throw bad_alloc("û������ļ�");
	}
#endif

	//д�ļ�
	char * buf[] = { "aaa\n","bbb\n","ccc\n" };
	for (int i = 0; i < 3; i++)
	{
		outfile << buf[i];
	}

	//���ļ�
	outfile.close();
}

//==============���ļ�==============//
void ioRead()
{
	//���ļ�
#if 1
	ifstream readfile("test.txt"/*, ios::in*/);//Ĭ���Ƕ��ļ�
	if (!readfile)
	{
		//throw bad_alloc("û������ļ�");
	}
#else
	ifstream readfile;
	readfile.open("test.txt", ios::in);
	if (readfile.is_open())
	{
		//throw bad_alloc("û������ļ�");
	}
#endif

	//���ļ�
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
		cout << "�ļ��α����ļ���β" << endl;
	}
	//���¶�ȡһ���ļ�����Ҫ����״̬
	readfile.clear();//����good״̬λ
	readfile.seekg(0, ios::beg);//�ļ��α�ص��ļ���ʼλ��
	memset(buf, 0, 1024);

	while (readfile.getline(buf, 1024))
	{
		cout << buf << endl;
		memset(buf, 0, 1024);
	}

	//���ļ�
	readfile.close();
}

//==============������==============//
int main(void)
{
	ioWrite();
	ioRead();

	cout << "Compelete" << endl;
	return 0;
}
