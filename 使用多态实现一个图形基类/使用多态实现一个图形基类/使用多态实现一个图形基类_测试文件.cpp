
#include "ʹ�ö�̬ʵ��һ��ͼ�λ���.h"

//==============���Ժ���==============//

void Calculate(FIGURE & base)
{
	std::cout << "�ܳ���" << base.perimeter() << 
		"�������" << base.area() << std::endl;
}

//==============������==============//

int main(void)
{
	CIRCLE c1(2);
	CIRCLE c2 = 1;
	ORTHOGON o1(2, 3);
	ORTHOGON o2 = ORTHOGON(4, 6);

	Calculate(c1);
	Calculate(c2);
	Calculate(o1);
	Calculate(o2);
	
	return 0;
}
