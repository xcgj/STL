#pragma once
/*
使用多态实现一个图形基类，两个子类：矩形和圆形
基类包含两个抽象方法：周长和面积
子类分别重写这两个方法
另外写一个全局的计算方法，参数为基类指针，传入子类对象时，输出对应的周长和面积
*/

#include <iostream>
#define PI 3.14159

//==============图形基类==============//
class FIGURE
{
public:
	virtual double perimeter() = 0;
	virtual double area() = 0;
};

//==============矩形子类==============//
class ORTHOGON : public FIGURE
{
private:
	double length;
	double width;
public:
	ORTHOGON(double, double);
	virtual double perimeter();
	virtual double area();
};

//==============圆形子类==============//
class CIRCLE : public FIGURE
{
private:
	double radius;
public:
	CIRCLE(double);
	virtual double perimeter();
	virtual double area();
};