#pragma once
#include <iostream>
#include <string>

//定义武器基类

#include "MONSTER.h"

class MONSTER;

class WEAPON
{
protected:
	//武器名字
	std::string name;	
	//基础攻击
	int damage;
	//最大暴击几率
	int strikeRate;
	//暴击加成
	int strikeAdd;
	//闪避几率加成
	int hide;
	//武器身份标识
	int state;
public:
	//特技（虚函数）
	virtual void weaponSkill(MONSTER * monster);
	//基础攻击
	int weaponDamage();
	//最大暴击几率
	int weaponStrikeRate();
	//暴击加成
	int weaponStrikeAdd();
	//虚析构函数
	virtual ~WEAPON();
	//闪避几率加成
	int weaponHide();
	//武器名字
	std::string weaponName();
	//武器身份标识
	int getID();
	WEAPON();
};