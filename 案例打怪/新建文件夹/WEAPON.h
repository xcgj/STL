#pragma once
#include <iostream>
#include <string>

//������������

#include "MONSTER.h"

class MONSTER;

class WEAPON
{
protected:
	//��������
	std::string name;	
	//��������
	int damage;
	//��󱩻�����
	int strikeRate;
	//�����ӳ�
	int strikeAdd;
	//���ܼ��ʼӳ�
	int hide;
	//������ݱ�ʶ
	int state;
public:
	//�ؼ����麯����
	virtual void weaponSkill(MONSTER * monster);
	//��������
	int weaponDamage();
	//��󱩻�����
	int weaponStrikeRate();
	//�����ӳ�
	int weaponStrikeAdd();
	//����������
	virtual ~WEAPON();
	//���ܼ��ʼӳ�
	int weaponHide();
	//��������
	std::string weaponName();
	//������ݱ�ʶ
	int getID();
	WEAPON();
};