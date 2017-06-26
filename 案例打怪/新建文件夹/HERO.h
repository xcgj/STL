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
	//Ӣ������
	std::string name;
	//Ѫ��
	int Hp;
	//��������
	int attack;
	//����
	int defense;
	//������������
	int strikeRate;
	//���������ӳ�
	int strikeAdd;
	//�������ܼ���
	int hide;

	//װ������
	WEAPON * wp;//Ҫ�пղ�������������

	NOweapon noweapon;
public:
	//Ѫ��
	int getHp();
	void setHp(int);
	//��������
	int getAttack();
	//����
	int getDefense();
	//������������
	int getStrikeRate();
	//���������ӳ�
	int getStrikeAdd();
	//�������ܼ���
	int getHide();
	//�������㺯��
	bool isStrike();
	//���ܼ��㺯��
	bool isHide();
	//��ʼ��
	HERO();

	//�������
	void getWeapon(WEAPON * wp);
	std::string getWeaponName();

	//��������
	void attackMonster(MONSTER * monster);
};

