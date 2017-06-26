#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include <list>
#include <vector>
#include <map>
#include <deque>
#include <ctime>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

//˼·��
//ѡ�ֱ���
//	ѡ����
//	����ѡ����ţ�ͬʱ����Ű�ѡ�ַ�������1����vector��deque���������У�Ҫ��������ʲ��ܴ���˳����������������������ѡ��
//				����һ��map����������ȫ��ѡ����Ϣ��������ѡ����ţ�������ӡ��Ϣ
//ѡ�ֱ��� x 3��
//	������ţ���ǩ��
//	���顪�����ⴴ��һ��ֻ����6�˵�����2���洢 id
//		�ݽ�����ί��֡�����������һ���µ�����3�� �洢����
//		��÷��������������������һ��multimap�������Է�����Ϊ�������� ���� id
//		��̭���������ǰ�����ɼ���ӡ���������µ�����4 �� id ����
//		�������2������3��multimap����
//	�������1����������4�еĽ���������������1
//��ӡ�ɼ�

//=============ѡ����==============//
#include <string>
class Player
{
public:
	string name;
	int score[3];
	Player(string n = "abc")
	{
		name = n;
	}

	string GetName()
	{
		return name;
	}

	//void SetScore(int a)
	//{
	//	score = a;
	//}

	//int GetScore()
	//{
	//	return score;
	//}

	/*void PrintInfomation()
	{
		std::cout << "score = " << score << ", name = " << name << endl;
	}*/
};

//==============ѡ�ֱ���==============//
void GetPlayers(vector<int> & pl, map<int, Player> & pm)
{
	string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; ++i)
	{
		string name = "ѡ��";
		name += s[i];
		int id = 1000 + i;

		//����ѡ����Ϣ����ʼ����Ϊ0
		pl.insert(pl.begin(), id);
	
		//����ѡ��id����Ϣ
		pm.insert(pair<int, Player>(id, Player(name)));
	}
}

//==============���==============//
void GetScore(deque<int> & pd, int & ps)
{
	for (int i = 0; i < 10; i++)
	{
		int makeScore = rand() % 41 + 60;
		pd.push_back(makeScore);
	}

	//ȥ����߷ֺ���ͷ�
	sort(pd.begin(), pd.end());
	pd.pop_back();
	pd.pop_front();

	//ƽ����
	int sum = accumulate(pd.begin(), pd.end(), 0);
	ps = sum / pd.size();
}

//==============��ʼ����==============//
void Campaign(int round, vector<int> & pv, map<int, Player> & pm)
{
	random_shuffle(pv.begin(), pv.end());
	multimap<int, int, greater<int>> mmp;	//ֻ����6�˵�����2���洢 ���� �� ���
	vector<int> tmp;
	int t = 0;

	//ѡ�����λ�ȡ����
	for (vector<int>::iterator i = pv.begin(); i != pv.end(); ++i)
	{
		//��ί��֡���deque������list����
		deque<int> pd;
		int pscore = 0;
		GetScore(pd, pscore);
		//cout << pscore << endl;

		//����ѡ�ַ���
		pm[*i].score[round - 1] = pscore;
		//�洢 ���� �� ���
		mmp.insert(multimap<int, int, greater<int>>::value_type(pscore, *i));
		if (mmp.size() == 6)
		{
			cout << "��" << round << " ��" << "��" << t + 1 << " ���ǰ��Ϊ��" << endl;
			multimap<int, int, greater<int>>::iterator mmpit = mmp.begin();
			for (int j = 0; j < 3; ++j)
			{
				//�������
				cout << mmpit->first << ", " << mmpit->second << ", " << pm[mmpit->second].name << endl;
				tmp.push_back(mmpit->second);
				++mmpit;
			}
			mmp.clear();
			t++;
		}
	}

	//���½�������
	//pv.clear();
	pv = tmp;
}

//==============������==============//
int main(void)
{ 
	//���������
	srand((unsigned int)time(NULL));
	vector<int> pl;			//��� ���
	map<int, Player> pm;		//��� ѡ�� ���

	//ѡ�ֱ���
	GetPlayers(pl, pm);
	//print<list<Player>>(pl);
	//for_each(pm.begin(), pm.end(), [](pair<int, Player> m){cout << m.first << ", "; m.second.PrintInfomation();});

	//ѡ�ֱ���
	for (int i = 1; i < 4; ++i)
	{
		int pause;
		cout << endl << "ѡ���Ѿ��������س���ʼ��" << i << " �ֱ���..." << endl;
		cin.get() >> pause;
		Campaign(i, pl, pm);
	}

	cout << "Compelete" << endl;
	return 0;
}