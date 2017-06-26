
#include "ʹ�ö�̬ʵ��һ��ͼ�λ���.h"

//==============�������෽��==============//
ORTHOGON::ORTHOGON(double len, double wid)
{
	if (len < 0)
	{
		len = 0;
	}
	if (wid < 0)
	{
		wid = 0;
	}
	length = len;
	width = wid;
}

double ORTHOGON::perimeter()
{
	return 2 * (length + width);
}

double ORTHOGON::area()
{
	return length * width;
}


//==============Բ�����෽��==============//
CIRCLE::CIRCLE(double rad)
{
	if (rad < 0)
	{
		rad = 0;
	}
	radius = rad;
}

double CIRCLE::perimeter()
{
	return PI * radius * 2;
}

double CIRCLE::area()
{
	return PI * radius * radius; 
}