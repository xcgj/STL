
#include "WEAPON.h"

WEAPON::WEAPON() { state = 0; }

//�ؼ����麯����
void WEAPON::weaponSkill(MONSTER * monster){}

//��������
int WEAPON::weaponDamage()
{
	return this->damage;
}

//��������
int WEAPON::weaponDefense()
{
	return this->defense;
}

//��󱩻�����
int WEAPON::weaponStrikeRate()
{
	return this->strikeRate;
}

//�����ӳ�
int WEAPON::weaponStrikeAdd()
{
	return this->strikeAdd;
}

//����������
WEAPON::~WEAPON(){}

//���ܼ��ʼӳ�
int WEAPON::weaponHide()
{
	return this->hide;
}

std::string WEAPON::weaponName()
{
	return this->name;
}

//������ݱ�ʶ
int WEAPON::getID()
{
	return this->state;
}

