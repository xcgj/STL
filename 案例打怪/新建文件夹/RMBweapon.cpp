#include "RMBweapon.h"

RMBweapon::RMBweapon()
{
	//武器名字
	name = "RMBweapon";
	//基础攻击
	damage = 100;
	//最大暴击几率
	strikeRate = 20;
	//暴击加成
	strikeAdd = 30;
	//闪避几率加成
	hide = 20;

	//冰冻几率
	frozenRate = 30;
	//冰冻回合
	frozenRound = 1;
	//武器身份标识
	state = 2;
}

bool RMBweapon::isFrozen()
{
	//随机种子
	srand((unsigned int)std::time(NULL));
	//在冰冻范围内就返回真
	bool tf = rand() % 100 + 1 < this->frozenRate;
	if (tf)
	{
		std::cout << "英雄攻击时，武器发动特效，怪物被冰冻了！" << std::endl;
	}
	return tf;
}

void RMBweapon::weaponSkill(MONSTER * monster)
{
	//根据冰冻几率判断是否冰冻怪物
	if (isFrozen())
	{
		//将怪物的冰冻回合数设置为1
		monster->setFrozenRound(1);
	}
}