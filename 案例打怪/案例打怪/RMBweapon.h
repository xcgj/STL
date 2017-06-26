#pragma once

#include "WEAPON.h"
#include <ctime>

class RMBweapon : public WEAPON
{
public:
	RMBweapon();
	//特技（虚函数）
	virtual void weaponSkill(MONSTER * monster);
	bool isFrozen();
private:
	//冰冻几率
	int frozenRate;
	int frozenRound;
};

