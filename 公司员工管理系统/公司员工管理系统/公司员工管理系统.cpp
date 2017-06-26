#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;
#define MARKETING	1	//营销
#define SCHEME		2	//策划
#define RESEARCH	3	//研发
#define ALL			4	//全部

//vector容存储信息
//map容器分组信息

//==============员工类==============//
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

//==============产生员工信息==============//
void makeWorker(vector<Worker> &v)
{
	string s = "ABCDE";
	for (int i = 0; i < 5; ++i)
	{
		string name = "员工";
		name += s[i];
		int salary = (rand() % 10000 + 10000) / 100 * 100;
		v.push_back(Worker(name, salary));
	}

	cout << "============产生员工信息===========" << endl;
	for_each(v.begin(), v.end(), [](Worker p)
	{
		p.PrintInfomation();
	});						//lambda表达式
}

//==============工具==============//
class PRINT
{
public:
	void operator()(pair<int, Worker> p)
	{
		cout << "部门：" << p.first << ": ";
		p.second.PrintInfomation();
	}
};

//==============分组员工==============//
void classifyWorker(multimap<int, Worker> & m, vector<Worker> & v)
{
	cout << "============分配员工到部门===========" << endl;

	for (vector<Worker>::iterator it = v.begin(); it != v.end(); ++it)
	{
		int department;
		REINPUT:
		cout << "请给员工：“" << it->GetName() << ", " << it->GetSalary() << " ” 分组：";
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
			cout << "部门错误，请重新分配" << endl;
			goto REINPUT;
		}
	}
	cout << "员工分配完成" << endl;
	//for_each(m.begin(), m.end(), PRINT());
}

//==============查询部门==============//
void listDpartment(multimap<int, Worker> & m, int command)
{
	//列出全部部门
	if (command == 4)
	{
		for_each(m.begin(), m.end(), PRINT());
		return;
	}

	//找到对应部门的第一个数据
	multimap<int, Worker>::iterator start = m.find(command);
	//该部门的人数
	int size = m.count(command);
	//遍历该部门
	for (int i = 0; i < size; ++i, ++start)
	{
		cout << "部门：" << start->first << ", ";
		start->second.PrintInfomation();
	}
}

//==============显示命令==============//
void listCommand(multimap<int, Worker> & m)
{
	cout << "============查询部门的员工===========" << endl;
	cout << "MARKETING\t1\nSCHEME\t\t2\nRESEARCH\t3\nALL\t\t4\n" << endl;
	while (1)
	{
		int Command;
		cout << "请输入部门：";
		cin >> Command;
		if (MARKETING == Command || SCHEME == Command || RESEARCH == Command || ALL == Command)
		{
			listDpartment(m, Command);
		}
		else
		{
			cout << "查询结束" << endl;
			break;
		}
	}
}

//==============测试文件==============//
void test()
{
	srand((unsigned)time(NULL));
	vector<Worker> v;			//存未分组员工
	multimap<int, Worker> m;	//员工分部门

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
