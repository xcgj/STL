#pragma once

#include "WEAPON.h"
#include <ctime>

class RMBweapon : public WEAPON
{
public:
	RMBweapon();
	//�ؼ����麯����
	virtual void weaponSkill(MONSTER * monster);
	bool isFrozen();
private:
	//��������
	int frozenRate;
	int frozenRound;
};

