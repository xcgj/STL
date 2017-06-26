
#include "WEAPON.h"

//特技（虚函数）
void WEAPON::weaponSkill(MONSTER * monster){}

//基础攻击
int WEAPON::weaponDamage()
{
	return this->damage;
}

//最大暴击几率
int WEAPON::weaponStrikeRate()
{
	return this->strikeRate;
}

//暴击加成
int WEAPON::weaponStrikeAdd()
{
	return this->strikeAdd;
}

//虚析构函数
WEAPON::~WEAPON(){}

//闪避几率加成
int WEAPON::weaponHide()
{
	return this->hide;
}

std::string WEAPON::weaponName()
{
	return this->name;
}

//武器身份标识
int WEAPON::getID()
{
	return this->state;
}

WEAPON::WEAPON() { state = 0; }