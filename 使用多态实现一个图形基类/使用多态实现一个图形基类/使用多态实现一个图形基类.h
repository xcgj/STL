#pragma once
/*
ʹ�ö�̬ʵ��һ��ͼ�λ��࣬�������ࣺ���κ�Բ��
��������������󷽷����ܳ������
����ֱ���д����������
����дһ��ȫ�ֵļ��㷽��������Ϊ����ָ�룬�����������ʱ�������Ӧ���ܳ������
*/

#include <iostream>
#define PI 3.14159

//==============ͼ�λ���==============//
class FIGURE
{
public:
	virtual double perimeter() = 0;
	virtual double area() = 0;
};

//==============��������==============//
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

//==============Բ������==============//
class CIRCLE : public FIGURE
{
private:
	double radius;
public:
	CIRCLE(double);
	virtual double perimeter();
	virtual double area();
};