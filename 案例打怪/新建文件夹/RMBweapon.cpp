#include "RMBweapon.h"

RMBweapon::RMBweapon()
{
	//��������
	name = "RMBweapon";
	//��������
	damage = 100;
	//��󱩻�����
	strikeRate = 20;
	//�����ӳ�
	strikeAdd = 30;
	//���ܼ��ʼӳ�
	hide = 20;

	//��������
	frozenRate = 30;
	//�����غ�
	frozenRound = 1;
	//������ݱ�ʶ
	state = 2;
}

bool RMBweapon::isFrozen()
{
	//�������
	srand((unsigned int)std::time(NULL));
	//�ڱ�����Χ�ھͷ�����
	bool tf = rand() % 100 + 1 < this->frozenRate;
	if (tf)
	{
		std::cout << "Ӣ�۹���ʱ������������Ч�����ﱻ�����ˣ�" << std::endl;
	}
	return tf;
}

void RMBweapon::weaponSkill(MONSTER * monster)
{
	//���ݱ��������ж��Ƿ��������
	if (isFrozen())
	{
		//������ı����غ�������Ϊ1
		monster->setFrozenRound(1);
	}
}