#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;
#define MARKETING	1	//Ӫ��
#define SCHEME		2	//�߻�
#define RESEARCH	3	//�з�
#define ALL			4	//ȫ��

//vector�ݴ洢��Ϣ
//map����������Ϣ

//==============Ա����==============//
#include <string>
class Worker
{
private:
	string name;
	int salary;
public:
	Worker(string n = "abc", int a = 0)
	{
		name = n;
		salary = a;
	}

	string GetName()
	{
		return name;
	}

	int GetSalary()
	{
		return salary;
	}

	void PrintInfomation()
	{
		std::cout << "name = " << name << ", salary = " << salary << endl;
	}
};

//==============����Ա����Ϣ==============//
void makeWorker(vector<Worker> &v)
{
	string s = "ABCDE";
	for (int i = 0; i < 5; ++i)
	{
		string name = "Ա��";
		name += s[i];
		int salary = (rand() % 10000 + 10000) / 100 * 100;
		v.push_back(Worker(name, salary));
	}

	cout << "============����Ա����Ϣ===========" << endl;
	for_each(v.begin(), v.end(), [](Worker p)
	{
		p.PrintInfomation();
	});						//lambda���ʽ
}

//==============����==============//
class PRINT
{
public:
	void operator()(pair<int, Worker> p)
	{
		cout << "���ţ�" << p.first << ": ";
		p.second.PrintInfomation();
	}
};

//==============����Ա��==============//
void classifyWorker(multimap<int, Worker> & m, vector<Worker> & v)
{
	cout << "============����Ա��������===========" << endl;

	for (vector<Worker>::iterator it = v.begin(); it != v.end(); ++it)
	{
		int department;
		REINPUT:
		cout << "���Ա������" << it->GetName() << ", " << it->GetSalary() << " �� ���飺";
		cin >> department;
		if (MARKETING == department)
		{
			m.insert(make_pair(MARKETING, (*it)));
		}
		else if (SCHEME == department)
		{
			m.insert(pair<int, Worker>(SCHEME, (*it)));
		}
		else if (RESEARCH == department)
		{
			m.insert(map<int, Worker>::value_type(RESEARCH, (*it)));
		}
		else
		{
			cout << "���Ŵ��������·���" << endl;
			goto REINPUT;
		}
	}
	cout << "Ա���������" << endl;
	//for_each(m.begin(), m.end(), PRINT());
}

//==============��ѯ����==============//
void listDpartment(multimap<int, Worker> & m, int command)
{
	//�г�ȫ������
	if (command == 4)
	{
		for_each(m.begin(), m.end(), PRINT());
		return;
	}

	//�ҵ���Ӧ���ŵĵ�һ������
	multimap<int, Worker>::iterator start = m.find(command);
	//�ò��ŵ�����
	int size = m.count(command);
	//�����ò���
	for (int i = 0; i < size; ++i, ++start)
	{
		cout << "���ţ�" << start->first << ", ";
		start->second.PrintInfomation();
	}
}

//==============��ʾ����==============//
void listCommand(multimap<int, Worker> & m)
{
	cout << "============��ѯ���ŵ�Ա��===========" << endl;
	cout << "MARKETING\t1\nSCHEME\t\t2\nRESEARCH\t3\nALL\t\t4\n" << endl;
	while (1)
	{
		int Command;
		cout << "�����벿�ţ�";
		cin >> Command;
		if (MARKETING == Command || SCHEME == Command || RESEARCH == Command || ALL == Command)
		{
			listDpartment(m, Command);
		}
		else
		{
			cout << "��ѯ����" << endl;
			break;
		}
	}
}

//==============�����ļ�==============//
void test()
{
	srand((unsigned)time(NULL));
	vector<Worker> v;			//��δ����Ա��
	multimap<int, Worker> m;	//Ա���ֲ���

	makeWorker(v);
	classifyWorker(m, v);
	listCommand(m);
}

int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}
