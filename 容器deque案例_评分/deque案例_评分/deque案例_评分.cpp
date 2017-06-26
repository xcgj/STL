#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>
using namespace std;

//==============ѡ����==============//
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

	//����>������
	bool operator> (PLAYER player)
	{
		return this->score > player.score;
	}

	//����<������
	bool operator< (PLAYER player)
	{
		return this->score < player.score;
	}
};

//==============����ѡ�ֱ���==============//
void GetPlayers(deque<PLAYER> & q)
{
	string num = "12345";
	//����ѡ����Ϣ���ѿռ䣩��������������
	for (int i = 0; i < 5; ++i)
	{
		string name = "ѡ��00";
		name += num[i];
		q.push_back(PLAYER(name, 0));
	}
}

//==============������������==============//
void Grade(deque<int> & p)
{
	for (int i = 0; i < 5; i++)
	{
		int num = rand() % 51 + 50;
		p.push_back(num);
	}
}

//==============����º���==============//
template<typename T>//����
class lowSort
{
public:
	bool operator()(T in1, T in2)
	{
		return in1 > in2;
	}
};

template<typename T>//����
class upSort
{
public:
	bool operator()(T in1, T in2)
	{
		return in1 < in2;
	}
};

//==============ÿλѡ�����α��ݻ�÷���==============//
void Comment(deque<PLAYER> & q)
{
	srand((unsigned int)time(NULL));
	//ÿ��ѡ����̨���ݡ�����������
	for (deque<PLAYER>::iterator i = q.begin(); i != q.end(); ++i)
	{
		//5����ίÿ�ζ���ÿλѡ�ִ�֣����������������������������������deque?vector
		deque<int> d;
		Grade(d);
		//����ȥ����߷ֺ���ͷ֡���deque����
		sort(d.begin(), d.end(), upSort<int>());//��������
#if 0
		for (int val : d)
		{
			cout << val << " ";
		}
		cout << endl;
#endif
		d.pop_back();
		d.pop_front();
		//�������deque�����ܷ֡�ƽ���֣�����ѡ����Ϣ��
		int sum = 0;
		for (int val : d)
		{
			sum += val;
		}
		int avg = sum / d.size();
		i->score = avg;
	}
}

//==============�����ļ�==============//
void test()
{
//����������vector������deque����
	deque<PLAYER> d;
//����ѡ����Ϣ
	GetPlayers(d);
//��ί���
	Comment(d);
//����������
	sort(d.begin(), d.end(), upSort<PLAYER>());//��������
	//sort(d.begin(), d.end(), lowSort<PLAYER>());//��������
//�����������
	//for (PLAYER val : d){val.printInfo();}//˳���ӡ
	for (deque<PLAYER>::reverse_iterator i = d.rbegin(); i != d.rend(); ++i){i->printInfo();}//�����ӡ
}

//==============������==============//
int main(void)
{
	test();
	cout << "Compelete" << endl;
	return 0;
}
