#include <iostream>
using namespace std;
#include <iomanip>//������Ʒ�
#include <string>
#include <strstream>

/*
cout.flush() //ˢ�»�����
cout.put() //�򻺳���д�ַ�
cout.write() //��buffe��дnum���ֽڵ���ǰ������С�
*/
//��Linux�²��ԣ�û��ˢ�»�������hello�ǲ������
void test01()
{
	cout << "hello";
	cout.flush();
	cout.put('a').put('b').put('c');
	char buf[1024] = "haha";
	cout.write(buf, 4);
}

//������Ʒ�----1.ͨ������Ա����  2.���Ʒ�

//ͨ������Ա����
void test02()
{
	string str = "abcd123";
	cout.width(20);
	cout.setf(ios::left);
	cout.fill('*');
	cout << str << endl;

	int num = 100;
	cout.width(10);
	cout.setf(ios::right);
	cout.fill('*');
	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout.setf(ios::showbase);
	cout << num << endl;
}

//���Ʒ�
void test03()
{
	string str1 = "abcd123";
	cout << setw(20)
		<< setfill('*')
		<< setiosflags(ios::left)
		<< str1
		<< endl;
	//�����ռλ����*������������� �����Ҷ���


	int num = 100;
	cout << setw(10)
		<< setiosflags(ios::right)
		<< setfill('*')
		<< resetiosflags(ios::dec)
		<< setiosflags(ios::hex)
		<< setiosflags(ios::showbase)
		<< num << endl;
}
int main()
{
	//test01();
	test02();
	test03();
	return 0;
}