#pragma once

#include <iostream>
#include <string>
#include <ctime>


class HERO;

class MONSTER
{
private:
	//怪物名字
	std::string name;
	//血量
	int Hp;
	//基础攻击
	int attack;
	//防御
	int defense;
	//基础暴击几率
	int strikeRate;
	//基础暴击加成
	int strikeAdd;
	//基础闪避几率
	int hide;
	//冰冻回合
	int frozenRound;
public:
	//初始化
	MONSTER();

	//血量
	int getHp();
	void setHp(int);
	//基础攻击
	int getAttack();
	//防御
	int getDefense();
	//基础暴击几率
	int getStrikeRate();
	//基础暴击加成
	int getStrikeAdd();
	//基础闪避几率
	int getHide();
	//暴击计算函数
	bool isStrike();
	//闪避计算函数
	bool isHide();
	//设置冰冻回合数
	void setFrozenRound(int a = 1);

	//攻英雄
	void attackHero(HERO & hero);
};

