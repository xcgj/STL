#include "HERO.h"

HERO::HERO()
{
	//Ӣ������
	name = "HERO";
	//Ѫ��
	Hp = 1500;
	//��������
	attack = 50;
	//����
	defense = 10;
	//������������
	strikeRate = 30;
	//���������ӳ�
	strikeAdd = 30;
	//�������ܼ���
	hide = 10;

	//����
	//wp = &noweapon;
}

//װ������
void HERO::getWeapon(WEAPON * wp)
{
	//���ж��Ƿ���һ��������
	if (this->wp->getID() == wp->getID())
	{
		return;
	}

	//�ж���û���������еĻ�ж��ԭ��������
	if (this->wp->getID() != 0)
	{
		//�ָ�����ӳɵ���ֵ
		//����
		this->attack -= this->wp->weaponDamage();
		//��������
		strikeRate -= this->wp->weaponStrikeRate();
		//�����ӳ�
		strikeAdd -= this->wp->weaponStrikeAdd();
		//���ܼ���
		hide -= this->wp->weaponHide();
	}

	//װ������
	this->wp = wp;
	//�ӳ���ֵ
	//����
	this->attack += wp->weaponDamage();
	//��������
	strikeRate += wp->weaponStrikeRate();
	//�����ӳ�
	strikeAdd += wp->weaponStrikeAdd();
	//���ܼ���
	hide += wp->weaponHide();
	//�ж�������û�з�����Ч

}

std::string HERO::getWeaponName()
{
	return this->wp->weaponName();
}

//Ѫ��
int HERO::getHp()
{
	return this->Hp;
}

void HERO::setHp(int a)
{
	this->Hp = a;
}

//��������
int HERO::getAttack()
{
	return this->attack;
}

//����
int HERO::getDefense()
{
	return this->defense;
}

//������������
int HERO::getStrikeRate()
{
	return this->strikeRate;
}

//���������ӳ�
int HERO::getStrikeAdd()
{
	return this->strikeAdd;
}

//�������ܼ���
int HERO::getHide()
{
	return this->hide;
}

//�������㺯��
bool HERO::isStrike()
{
	//���������
	srand((unsigned int)std::time(NULL));
	return rand() % 100 + 1 < this->strikeRate;
}

//���ܼ��㺯��
bool HERO::isHide()
{
	//���������
	srand((unsigned int)std::time(NULL));
	return rand() % 100 + 1 < (this->hide + this->wp->weaponHide());
}

//��������
void HERO::attackMonster(MONSTER * monster)
{
	//���������
	srand((unsigned int)std::time(NULL));

	//�ж������Ƿ�Թ��ﴥ������
	this->wp->weaponSkill(monster);

	//�����˺�
	int hdamage = this->getAttack() + this->wp->weaponDamage();

	//��ʼ����
	if (isStrike())
	{
		std::cout << "Ӣ�۴����˱�����" <<  std::endl;
		hdamage += this->strikeAdd * hdamage / 100;
	}
	//���ƹ�����Χ
	hdamage = rand() % 21 + hdamage - 10;
	monster->setHp(monster->getHp() - hdamage);
	std::cout << "Ӣ�۶Թ��������" << hdamage << "���˺�"  << std::endl;
}