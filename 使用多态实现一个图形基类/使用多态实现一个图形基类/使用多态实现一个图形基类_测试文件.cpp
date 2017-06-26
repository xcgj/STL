
#include "使用多态实现一个图形基类.h"

//==============测试函数==============//

void Calculate(FIGURE & base)
{
	std::cout << "周长：" << base.perimeter() << 
		"，面积：" << base.area() << std::endl;
}

//==============主函数==============//

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
