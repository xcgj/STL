#pragma once

#include <iostream>
#include <string>
#include <ctime>

//#include "WEAPON.h"
#include "MONSTER.h"
#include "NOweapon.h"

class WEAPON;
class MONSTER;
class NOweapon;

class HERO
{
private:
	//英雄名字
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

	//装备武器
	WEAPON * wp;//要判空操作，不能引用

	NOweapon noweapon;
public:
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
	//初始化
	HERO();

	//获得武器
	void getWeapon(WEAPON * wp);
	std::string getWeaponName();

	//攻击怪物
	void attackMonster(MONSTER * monster);
};

