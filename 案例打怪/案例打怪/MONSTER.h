#pragma once

#include <iostream>
#include <string>
#include <ctime>


class HERO;

class MONSTER
{
private:
	//��������
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
	//�����غ�
	int frozenRound;
public:
	//��ʼ��
	MONSTER();

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
	//���ñ����غ���
	void setFrozenRound(int a = 1);

	//��Ӣ��
	void attackHero(HERO & hero);
};

