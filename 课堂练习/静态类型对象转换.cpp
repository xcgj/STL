#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class FuLei
{
public:	
	virtual void a(){}
};

class ZiLei : public FuLei
{
public:
	int a;
	int b;
};

class E
{};

int main(void)
{

#if 0
	FuLei * f = NULL;
	ZiLei * s = NULL;
	E * e = NULL;

	FuLei fc;//�������
	ZiLei sc;//�������

	//��������ת��
	s = static_cast		<ZiLei *>(f);
	s = dynamic_cast	<ZiLei *>(f);//Ҫ���麯���Ų��ᱨ�����麯���б�������ʱ���
	s = reinterpret_cast<ZiLei *>(f);//����ʲô�����֧��
	//��������ת��
	f = static_cast		<FuLei *>(s);
	f = dynamic_cast	<FuLei *>(s);
	f = reinterpret_cast<FuLei *>(s);
	//e = dynamic_cast<ZiLei *>(f);	//����
	//e = static_cast<FuLei *>(s);	//����
	
	fc = (FuLei)sc;
	fc = static_cast<FuLei>(sc);
	//sc = (ZiLei)fc;				//����	��
	//sc = static_cast<ZiLei>(fc);	//����	��

#endif
	FuLei * f = new FuLei;
	ZiLei * s = new ZiLei;
	ZiLei * t = dynamic_cast	<ZiLei *>(f);//Ҫ���麯���Ų��ᱨ�����麯���б�������ʱ���
	if (NULL == t)
	{
		cout << "t�ǿ�ָ��" << t << endl;
	}
	//�������麯����dynamic_cast��⵽��������ת��ʱ���᷵�ؿ�ָ��
	cout << "Compelete" << endl;
	return 0;
}
