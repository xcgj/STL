
#include "使用多态实现一个图形基类.h"

//==============矩形子类方法==============//
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


//==============圆形子类方法==============//
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