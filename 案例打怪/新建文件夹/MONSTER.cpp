#include "MONSTER.h"
using std::cout;
using std::endl;


MONSTER::MONSTER()
{
	//怪物名字
	name = "MONSTER";
	//血量
	Hp = 3000;
	//基础攻击
	attack = 150;
	//防御
	defense = 0;
	//基础暴击几率
	strikeRate = 0;
	//基础暴击加成
	strikeAdd = 0;
	//基础闪避几率
	hide = 0;
	//冰冻回合
	frozenRound = 0;
}

//血量
int MONSTER::getHp()
{
	return this->Hp;
}

void MONSTER::setHp(int a)
{
	this->Hp = a;
}

//基础攻击
int MONSTER::getAttack()
{
	return this->attack;
}

//防御
int MONSTER::getDefense()
{
	return this->defense;
}

//基础暴击几率
int MONSTER::getStrikeRate()
{
	return this->strikeRate;
}

//基础暴击加成
int MONSTER::getStrikeAdd()
{
	return this->strikeAdd;
}

//基础闪避几率
int MONSTER::getHide()
{
	return this->hide;
}

//暴击计算函数
bool MONSTER::isStrike()
{
	return 0;
}

//闪避计算函数
bool MONSTER::isHide()
{
	return 0;
}

//设置冰冻回合数
void MONSTER::setFrozenRound(int a)
{
	this->frozenRound = a;
}

//攻击英雄
void MONSTER::attackHero(HERO & hero)
{
	//随机数种子
	srand((unsigned int)std::time(NULL));

	//先判断自身触发冰冻状态
	if (this->frozenRound)
	{
		cout << "怪物冰冻，本回合无法攻击" << endl;
		this->frozenRound--;
		return;
	}

	//判断英雄是否触发闪避
	if (hero.isHide())
	{
		cout << "英雄闪避，本回合攻击无效" << endl;
		return;
	}

	//开始攻击
	//控制攻击范围
	int herodamage = this->attack - 10 + rand() % 21;
	hero.setHp(hero.getHp() - (herodamage - hero.getDefense()));
	cout << "怪物对英雄造成了" << herodamage << "点伤害" << endl;
}

