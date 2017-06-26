#include <iostream>
using namespace std;

//#include <string.h>

#include "WEAPON.h"
#include "RMBweapon.h"
#include "NORMALweapon.h"
#include "HERO.h"
#include "MONSTER.h"
#include "NOweapon.h"

/*
实现思路：
英雄使用武器，武器拥有特技
英雄对怪物造成伤害，拥有暴击几率，闪避几率
怪物对英雄造成伤害，但怪物可能被被动，攻击被闪避
*/

void test()
{
	HERO			hero;		//英雄
	MONSTER			monster;	//怪物
	RMBweapon		rbmweapon;	//土豪武器
	NORMALweapon	pinweapon;	//贫民武器

	//装备武器
#if 1
	hero.getWeapon(&rbmweapon);
#else
	hero.getWeapon(&pinweapon);
#endif

	
	cout << "英雄装备了" << hero.getWeaponName() << endl;
	cout << "英雄当前攻击力：" << hero.getAttack() << endl;
	cout << "英雄当前防御力：" << hero.getDefense() << endl;
	cout << "英雄当前暴击率：" << hero.getStrikeRate() << endl;
	cout << "英雄当前暴击力：" << hero.getStrikeAdd() << endl;
	cout << "英雄当前闪避率：" << hero.getHide() << endl;

	//开始打怪
	while (1)
	{
		cout << "英雄剩余血量：" << hero.getHp() << endl;
		cout << "怪物剩余血量：" << monster.getHp() << endl;

		getchar();
		//英雄攻击
		hero.attackMonster(&monster);
		if (monster.getHp() <= 0)
		{
			cout << "怪物挂了" << endl;
			break;
		}
		
		//怪物反杀
		monster.attackHero(hero);
		if (hero.getHp() <= 0)
		{
			cout << "英雄挂了" << endl;
			break;
		}
	}
}

int main(void)
{
	test();

	cout << "Compelete" << endl;
	return 0;
}