#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "������.h"

int main(void)
{
	myArray arr(5);
	arr << 2 << 5 << 7 << 3 << 8 << 4;
	arr[0] = 1;
	cout << arr;

	arr.pop();
	cout << arr;
	cout << "size: " << arr.size() << endl;

	myArray arr1 = arr;
	cout << arr1;
	arr1.pushback(100);

	myArray arr2;
	arr2 = arr1;
	cout << arr2;

	cout << arr2(arr1) << endl;
	cout << arr2(arr) << endl;
	cout << arr(arr2) << endl;

	return 0;
}
//������ ����<<
//Ĭ���в�
//��������
//����
//��ֵ������=
//����[]
//����<<
//��������
//����
//ɾ��
//���С
