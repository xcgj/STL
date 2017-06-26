#include "MONSTER.h"
using std::cout;
using std::endl;


MONSTER::MONSTER()
{
	//��������
	name = "MONSTER";
	//Ѫ��
	Hp = 3000;
	//��������
	attack = 150;
	//����
	defense = 0;
	//������������
	strikeRate = 0;
	//���������ӳ�
	strikeAdd = 0;
	//�������ܼ���
	hide = 0;
	//�����غ�
	frozenRound = 0;
}

//Ѫ��
int MONSTER::getHp()
{
	return this->Hp;
}

void MONSTER::setHp(int a)
{
	this->Hp = a;
}

//��������
int MONSTER::getAttack()
{
	return this->attack;
}

//����
int MONSTER::getDefense()
{
	return this->defense;
}

//������������
int MONSTER::getStrikeRate()
{
	return this->strikeRate;
}

//���������ӳ�
int MONSTER::getStrikeAdd()
{
	return this->strikeAdd;
}

//�������ܼ���
int MONSTER::getHide()
{
	return this->hide;
}

//�������㺯��
bool MONSTER::isStrike()
{
	return 0;
}

//���ܼ��㺯��
bool MONSTER::isHide()
{
	return 0;
}

//���ñ����غ���
void MONSTER::setFrozenRound(int a)
{
	this->frozenRound = a;
}

//����Ӣ��
void MONSTER::attackHero(HERO & hero)
{
	//���������
	srand((unsigned int)std::time(NULL));

	//���ж�����������״̬
	if (this->frozenRound)
	{
		cout << "������������غ��޷�����" << endl;
		this->frozenRound--;
		return;
	}

	//�ж�Ӣ���Ƿ񴥷�����
	if (hero.isHide())
	{
		cout << "Ӣ�����ܣ����غϹ�����Ч" << endl;
		return;
	}

	//��ʼ����
	//���ƹ�����Χ
	int herodamage = this->attack - 10 + rand() % 21;
	hero.setHp(hero.getHp() - (herodamage - hero.getDefense()));
	cout << "�����Ӣ�������" << herodamage << "���˺�" << endl;
}

