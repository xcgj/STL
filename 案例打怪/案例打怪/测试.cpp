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
ʵ��˼·��
Ӣ��ʹ������������ӵ���ؼ�
Ӣ�۶Թ�������˺���ӵ�б������ʣ����ܼ���
�����Ӣ������˺�����������ܱ�����������������
*/

void test()
{
	HERO			hero;		//Ӣ��
	MONSTER			monster;	//����
	RMBweapon		rbmweapon;	//��������
	NORMALweapon	pinweapon;	//ƶ������

	//װ������
#if 1
	hero.getWeapon(&rbmweapon);
#else
	hero.getWeapon(&pinweapon);
#endif

	
	cout << "Ӣ��װ����" << hero.getWeaponName() << endl;
	cout << "Ӣ�۵�ǰ��������" << hero.getAttack() << endl;
	cout << "Ӣ�۵�ǰ��������" << hero.getDefense() << endl;
	cout << "Ӣ�۵�ǰ�����ʣ�" << hero.getStrikeRate() << endl;
	cout << "Ӣ�۵�ǰ��������" << hero.getStrikeAdd() << endl;
	cout << "Ӣ�۵�ǰ�����ʣ�" << hero.getHide() << endl;

	//��ʼ���
	while (1)
	{
		cout << "Ӣ��ʣ��Ѫ����" << hero.getHp() << endl;
		cout << "����ʣ��Ѫ����" << monster.getHp() << endl;

		getchar();
		//Ӣ�۹���
		hero.attackMonster(&monster);
		if (monster.getHp() <= 0)
		{
			cout << "�������" << endl;
			break;
		}
		
		//���ﷴɱ
		monster.attackHero(hero);
		if (hero.getHp() <= 0)
		{
			cout << "Ӣ�۹���" << endl;
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