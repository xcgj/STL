#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>
using namespace std;

//==============选手类==============//
class PLAYER
{
private:
	string name;
public:
	int score;
	PLAYER(string n, int a)
	{
		name = n;
		score = a;
	}

	void printInfo()
	{
		cout << score << "," << name << endl;
	}

	//重载>操作符
	bool operator> (PLAYER player)
	{
		return this->score > player.score;
	}

	//重载<操作符
	bool operator< (PLAYER player)
	{
		return this->score < player.score;
	}
};

//==============参赛选手报名==============//
void GetPlayers(deque<PLAYER> & q)
{
	string num = "12345";
	//产生选手信息（堆空间），并放入容器中
	for (int i = 0; i < 5; ++i)
	{
		string name = "选手00";
		name += num[i];
		q.push_back(PLAYER(name, 0));
	}
}

//==============分数产生函数==============//
void Grade(deque<int> & p)
{
	for (int i = 0; i < 5; i++)
	{
		int num = rand() % 51 + 50;
		p.push_back(num);
	}
}

//==============排序仿函数==============//
template<typename T>//降序
class lowSort
{
public:
	bool operator()(T in1, T in2)
	{
		return in1 > in2;
	}
};

template<typename T>//升序
class upSort
{
public:
	bool operator()(T in1, T in2)
	{
		return in1 < in2;
	}
};

//==============每位选手依次表演获得分数==============//
void Comment(deque<PLAYER> & q)
{
	srand((unsigned int)time(NULL));
	//每个选手上台表演——遍历容器
	for (deque<PLAYER>::iterator i = q.begin(); i != q.end(); ++i)
	{
		//5个评委每次都对每位选手打分，分数存入另外的容器——新增容器——deque?vector
		deque<int> d;
		Grade(d);
		//排序去除最高分和最低分——deque容器
		sort(d.begin(), d.end(), upSort<int>());//匿名对象
#if 0
		for (int val : d)
		{
			cout << val << " ";
		}
		cout << endl;
#endif
		d.pop_back();
		d.pop_front();
		//遍历打分deque，求总分、平均分，放入选手信息里
		int sum = 0;
		for (int val : d)
		{
			sum += val;
		}
		int avg = sum / d.size();
		i->score = avg;
	}
}

//==============测试文件==============//
void test()
{
//创建容器，vector容器、deque容器
	deque<PLAYER> d;
//输入选手信息
	GetPlayers(d);
//评委打分
	Comment(d);
//按分数排名
	sort(d.begin(), d.end(), upSort<PLAYER>());//升序排列
	//sort(d.begin(), d.end(), lowSort<PLAYER>());//降序排列
//输出分数排名
	//for (PLAYER val : d){val.printInfo();}//顺序打印
	for (deque<PLAYER>::reverse_iterator i = d.rbegin(); i != d.rend(); ++i){i->printInfo();}//逆序打印
}

//==============主函数==============//
int main(void)
{
	test();
	cout << "Compelete" << endl;
	return 0;
}
