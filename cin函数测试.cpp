#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <strstream>
#include <iomanip>
using namespace std;

//==============cin���Ժ���==============//
/*
cin.get() //һ��ֻ�ܶ�ȡһ���ַ�
cin.get(һ������) //��һ���ַ�
cin.get(��������) //���Զ��ַ���
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
*/
void cintest()
{
	char a, b, c, d, e;
	char s[100] = { 0 };

#if 0
	cin.get(c);
	cout << c << endl;
#elif 0
	c = cin.get();
	cout << c << endl;
#elif 0
	c = cin.get();
	cout << c << endl;
	c = cin.get();
	cout << c << endl;
	c = cin.get();
	cout << c << endl;
	c = cin.get();
	cout << c << endl;
	c = cin.get();
	cout << c << endl;
	cout << cin.get();
	cout << cin.get();
	cout << cin.get();
	//���ۣ�
	// �ܶ�ȡ���з���Ҳ�ܶ�ȡ�ո�
	// ���س����ܶ�ȡ���λس�����Ļ��з�'\n'�����з����ڻ���������һ�ο�ʼ�ܶ�ȡ����
	// cout << cin.get();��ȡ�����ַ���ASCII��
	// ��������Ϊ��ʱ�������ζ�ȡ�ַ���ÿ��ȡ���Ὣ�Ỻ��������ַ�ȡ��������c��cout��ʾ����Ļ��
	// ������������ʱ����ȴ��û������µ����ݣ�������ȡ��ֱ�����ٵ���cin.get()
#elif 0
	//��ʽ���
	cin.get(a).get(b).get(c).get(d).get(e);
	cout << a << b << c << d << e << endl;
#elif 0
	cin.get(s, 10);
	cout << s;
	//ע��㣺
	//���룺0123456789
	//�����012345678
	//���ۣ�
	//cin.get(s, 10)�������ַ���������Χʱ���Զ��ڽ�β�����ˡ�\0�����ɼ���������ǰ�ȫ��
	//��֤��
	c = cin.get();
	cout << endl << c << endl;
	//���룺012345678987654321
	//�����012345678
	//		9
#elif 0
	//cin.clear(ios::failbit);
	//c = cin.get();
	//cout << c;
	cin.getline(s, 5);
	cout << s;
	cin.clear();
	c = cin.get();
	cout << '@' << c;
	c = cin.get();
	cout << c;
	c = cin.get();
	cout << c;
	/*
	asdfghjk
	asdf@ghj�밴���������. . .
	���ۣ�s�ܶ�ȡ������Ч�ַ�����Ϊ5 - 1�������һ���ַ�Ϊ��\0'
		  ��ΪԽ�磬����ios::goodbit״̬λ�����false��
	*/
#elif 0
	cin.ignore(3);//����3���ַ�
	cin.getline(s, 10);
	cout << s;
#elif 0
	a = cin.peek();//�鿴��������û���ַ����� ���� ��һ���ַ���c��
	cout << '@' << a;
	if (a == '\n')
	{
		cout << "a���˻���";
	}
	b = cin.peek();
	cout << '@' << b;
	if (b == '\n')
	{
		cout << "b���˻���";
	}

	e = cin.get();

	c = cin.peek();
	cout << '@' << c;
	if (c == '\n')
	{
		cout << "c���˻���";
	}
	d = cin.peek();
	cout << '@' << d;
	if (d == '\n')
	{
		cout << "d���˻���";
	}
	/*	
	@
	a���˻���@
	b���˻���a
	@a@a�밴���������. . .
	*/
#elif 0
	cin.get(a);
	cout << '@' << a << endl;
	cin.getline(s, 5);
	cout << '@' << s << endl;
	cin.clear();
	cin.putback(a);
	cout << '@' << a << endl;
	cin.getline(s, 20);
	cout << '@' << s << endl;
	/*
	asdfghjk
	@a
	@sdfg
	@a
	@ahjk
	�밴���������. . .
	*/
#endif
}

//==============cout���Ժ���==============//
void couttest()
{
/*
cout.flush() //ˢ�»�����
cout.put() //�򻺳���д�ַ�
cout.write() //��buffe��дnum���ֽڵ���ǰ������С�
*/
	char a, b, c, d, e;
	char s[1024] = { 0 };

#if 0	//	linux�²�����Ч
	cout << "abc";
	cout.flush();
#elif 0
	cout.put('a');
	//��ʽ���
	cout.put('\n').put('a').put('b').put('c');
#elif 0
	//���������ַ����Ϊ5�������Կո���
	//�ַ������ȴ������֣�����Ĳ����
	cout.write("abc" ,1);
	cout.put('a');
#elif 0
	char buf[1024] = "abcde";
	cout.write(buf, 1);
	cout.put('a');
#endif

}

//==============������==============//
int main(void)
{
	//cintest();
	couttest();

	return 0;
}
