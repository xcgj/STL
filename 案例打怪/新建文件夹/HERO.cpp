#include "HERO.h"

HERO::HERO()
{
	//英雄名字
	name = "HERO";
	//血量
	Hp = 1500;
	//基础攻击
	attack = 50;
	//防御
	defense = 10;
	//基础暴击几率
	strikeRate = 30;
	//基础暴击加成
	strikeAdd = 30;
	//基础闪避几率
	hide = 10;

	//武器
	//wp = &noweapon;
}

//装备武器
void HERO::getWeapon(WEAPON * wp)
{
	//先判断是否有一样的武器
	if (this->wp->getID() == wp->getID())
	{
		return;
	}

	//判断有没有武器，有的话卸载原来的武器
	if (this->wp->getID() != 0)
	{
		//恢复各项加成的数值
		//攻击
		this->attack -= this->wp->weaponDamage();
		//暴击几率
		strikeRate -= this->wp->weaponStrikeRate();
		//暴击加成
		strikeAdd -= this->wp->weaponStrikeAdd();
		//闪避几率
		hide -= this->wp->weaponHide();
	}

	//装备武器
	this->wp = wp;
	//加成数值
	//攻击
	this->attack += wp->weaponDamage();
	//暴击几率
	strikeRate += wp->weaponStrikeRate();
	//暴击加成
	strikeAdd += wp->weaponStrikeAdd();
	//闪避几率
	hide += wp->weaponHide();
	//判断武器有没有发动特效

}

std::string HERO::getWeaponName()
{
	return this->wp->weaponName();
}

//血量
int HERO::getHp()
{
	return this->Hp;
}

void HERO::setHp(int a)
{
	this->Hp = a;
}

//基础攻击
int HERO::getAttack()
{
	return this->attack;
}

//防御
int HERO::getDefense()
{
	return this->defense;
}

//基础暴击几率
int HERO::getStrikeRate()
{
	return this->strikeRate;
}

//基础暴击加成
int HERO::getStrikeAdd()
{
	return this->strikeAdd;
}

//基础闪避几率
int HERO::getHide()
{
	return this->hide;
}

//暴击计算函数
bool HERO::isStrike()
{
	//随机数种子
	srand((unsigned int)std::time(NULL));
	return rand() % 100 + 1 < this->strikeRate;
}

//闪避计算函数
bool HERO::isHide()
{
	//随机数种子
	srand((unsigned int)std::time(NULL));
	return rand() % 100 + 1 < (this->hide + this->wp->weaponHide());
}

//攻击怪物
void HERO::attackMonster(MONSTER * monster)
{
	//随机数种子
	srand((unsigned int)std::time(NULL));

	//判断武器是否对怪物触发冰冻
	this->wp->weaponSkill(monster);

	//计算伤害
	int hdamage = this->getAttack() + this->wp->weaponDamage();

	//开始攻击
	if (isStrike())
	{
		std::cout << "英雄触发了暴击！" <<  std::endl;
		hdamage += this->strikeAdd * hdamage / 100;
	}
	//控制攻击范围
	hdamage = rand() % 21 + hdamage - 10;
	monster->setHp(monster->getHp() - hdamage);
	std::cout << "英雄对怪物造成了" << hdamage << "点伤害"  << std::endl;
}