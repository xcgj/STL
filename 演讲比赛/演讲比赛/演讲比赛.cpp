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

//思路：
//选手报名
//	选手类
//	产生选手序号，同时将序号绑定选手放入容器1——vector、deque，其他不行，要求随机访问并能打乱顺序，这个容器用来保存晋级的选手
//				再做一个map容器，保存全部选手信息，索引是选手序号，用来打印信息
//选手比赛 x 3次
//	打乱序号（抽签）
//	分组——另外创建一个只容纳6人的容器2，存储 id
//		演讲，评委打分——分数放入一个新的容器3， 存储分数
//		获得分数结果，——分数放入一个multimap容器，以分数作为索引，存 分数 id
//		淘汰或晋级，将前三名成绩打印，并存入新的容器4 存 id 分数
//		清空容器2，容器3，multimap容器
//	清空容器1，将新容器4中的晋级名单放入容器1
//打印成绩

//=============选手类==============//
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

//==============选手报名==============//
void GetPlayers(vector<int> & pl, map<int, Player> & pm)
{
	string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; ++i)
	{
		string name = "选手";
		name += s[i];
		int id = 1000 + i;

		//保存选手信息，初始分数为0
		pl.insert(pl.begin(), id);
	
		//保存选手id和信息
		pm.insert(pair<int, Player>(id, Player(name)));
	}
}

//==============打分==============//
void GetScore(deque<int> & pd, int & ps)
{
	for (int i = 0; i < 10; i++)
	{
		int makeScore = rand() % 41 + 60;
		pd.push_back(makeScore);
	}

	//去掉最高分和最低分
	sort(pd.begin(), pd.end());
	pd.pop_back();
	pd.pop_front();

	//平均分
	int sum = accumulate(pd.begin(), pd.end(), 0);
	ps = sum / pd.size();
}

//==============开始比赛==============//
void Campaign(int round, vector<int> & pv, map<int, Player> & pm)
{
	random_shuffle(pv.begin(), pv.end());
	multimap<int, int, greater<int>> mmp;	//只容纳6人的容器2，存储 分数 和 序号
	vector<int> tmp;
	int t = 0;

	//选手依次获取分数
	for (vector<int>::iterator i = pv.begin(); i != pv.end(); ++i)
	{
		//评委打分——deque容器或list容器
		deque<int> pd;
		int pscore = 0;
		GetScore(pd, pscore);
		//cout << pscore << endl;

		//保存选手分数
		pm[*i].score[round - 1] = pscore;
		//存储 分数 和 序号
		mmp.insert(multimap<int, int, greater<int>>::value_type(pscore, *i));
		if (mmp.size() == 6)
		{
			cout << "第" << round << " 轮" << "第" << t + 1 << " 组的前三为：" << endl;
			multimap<int, int, greater<int>>::iterator mmpit = mmp.begin();
			for (int j = 0; j < 3; ++j)
			{
				//插入分数
				cout << mmpit->first << ", " << mmpit->second << ", " << pm[mmpit->second].name << endl;
				tmp.push_back(mmpit->second);
				++mmpit;
			}
			mmp.clear();
			t++;
		}
	}

	//更新晋级名单
	//pv.clear();
	pv = tmp;
}

//==============主函数==============//
int main(void)
{ 
	//随机数种子
	srand((unsigned int)time(NULL));
	vector<int> pl;			//存放 序号
	map<int, Player> pm;		//存放 选手 序号

	//选手报名
	GetPlayers(pl, pm);
	//print<list<Player>>(pl);
	//for_each(pm.begin(), pm.end(), [](pair<int, Player> m){cout << m.first << ", "; m.second.PrintInfomation();});

	//选手比赛
	for (int i = 1; i < 4; ++i)
	{
		int pause;
		cout << endl << "选手已就绪，按回车开始第" << i << " 轮比赛..." << endl;
		cin.get() >> pause;
		Campaign(i, pl, pm);
	}

	cout << "Compelete" << endl;
	return 0;
}